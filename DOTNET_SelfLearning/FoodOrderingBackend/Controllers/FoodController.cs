using FoodOrderingBackend.DTOs;
using FoodOrderingBackend.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualBasic;

namespace FoodOrderingBackend.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class FoodController : ControllerBase
    {
        private readonly AppDbContext _context;

        public FoodController(AppDbContext context)
        {
            _context = context;
        }

        // Food Upload API

        [HttpPost("uploadFood")]

        public async Task<IActionResult> AddFood([FromForm] FoodCreateDto dto)
        {
            string fileName = "";

            if (dto.Image != null)
            {
                fileName = Guid.NewGuid() + Path.GetExtension(dto.Image.FileName);

                var path = Path.Combine("wwwroot", "FoodImage", fileName);

                using var Stream = new FileStream(path, FileMode.Create);

                await dto.Image.CopyToAsync(Stream);
            }

            var food = new Food
            {
                Name = dto.Name,
                Price = dto.Price,
                Description = dto.Description,
                ImageFilename = fileName
            };

            _context.Foods.Add(food);

            await _context.SaveChangesAsync();

            return Ok(ResultHelper.Success("Food item added."));
        }


        [AllowAnonymous]
        [HttpGet("menu")]

        public async Task<IActionResult> GetMenu()
        {
            var foods = await _context.Foods.ToListAsync();
            return Ok(ResultHelper.Success(foods));
        }


        // Place Order API

        [Authorize, HttpPost]

        public async Task<IActionResult> PlaceOrder(PlaceOrderDto dto)
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);

            var order = new Order
            {
                Uid = uid,
                TotalAmount = dto.TotalAmount,
                OrderDate = DateTime.UtcNow
            };

            _context.Orders.Add(order);
            await _context.SaveChangesAsync();

            foreach (var item in dto.CartItems)
            {
                var food = await _context.Foods.FindAsync(item.Fid);
                var details = new OrderDetail
                {
                    Oid = order.Oid,
                    Fid = item.Fid,
                    Quantity = item.Quantity,
                    Price = food!.Price * item.Quantity
                };

                _context.OrderDetails.Add(details);
            }

            await _context.SaveChangesAsync();
            return Ok(ResultHelper.Success("Order placed successfully"));
        }

        // GET ORDER

        [Authorize, HttpGet]
        public async Task<IActionResult> GetOrders()
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);

            var orders = await _context.Orders
                .Where(o => o.Uid == uid)
                .ToListAsync();

            return Ok(ResultHelper.Success(orders));
        }

    }
}
