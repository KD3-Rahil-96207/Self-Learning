using BCrypt.Net;
using FoodOrderingBackend.DTOs;
using FoodOrderingBackend.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;

namespace FoodOrderingBackend.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class UserController : ControllerBase
    {
        private readonly AppDbContext _context;
        private IConfiguration _config;

        public UserController(AppDbContext context, IConfiguration config)
        {
            _context = context;
            _config = config;
        }

        [HttpPost("signup")]
        public async Task<IActionResult> Signup(SignupDto dto)
        {

            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            //check if email exists 

            var exists = await _context.Users.AnyAsync(u => u.Email == dto.Email);
            if (exists)
            {
                return BadRequest(ResultHelper.Failure("Email already registered"));
            }

            var user = new User
            {
                Name = dto.Name,
                Email = dto.Email,
                Password = BCrypt.Net.BCrypt.HashPassword(dto.Password),
                Mobile = dto.Mobile
            };

            _context.Users.Add(user);
            await _context.SaveChangesAsync();

            return Ok(ResultHelper.Success("Signup successful."));

        }

        // Sign In API

        [HttpPost("signin")]

        public async Task<IActionResult> Signin(SigninDto dto)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var user = await _context.Users.FirstOrDefaultAsync(u => u.Email == dto.Email);
            if (user == null || !BCrypt.Net.BCrypt.Verify(dto.Password, user.Password))
            {
                return BadRequest(ResultHelper.Failure("Invalid email or password"));
            }

            var token = GenerateJwtToken(user);
            return Ok(ResultHelper.Success(new {token}));
        }

        // Generate JWT Token

        private string GenerateJwtToken(User user)
        {
            var claims = new[]
            {
                new Claim("uid", user.Uid.ToString()),
            };

            var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_config["Jwt:Key"]!));

            var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);

            var token = new JwtSecurityToken(
                issuer: _config["Jwt:Issuer"],
                audience: _config["Jwt:Audience"],
                claims: claims,
                expires: DateTime.Now.AddHours(2),
                signingCredentials: creds
            );

            return new JwtSecurityTokenHandler().WriteToken(token);
        }


        [Authorize]
        [HttpGet]

        public async Task<IActionResult> GetProfile()
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);
            var user = await _context.Users.FindAsync(uid);

            if (user == null)
                return NotFound(ResultHelper.Failure("User not found"));

            return Ok(ResultHelper.Success(new
            {
                user.Uid,
                user.Name,
                user.Mobile
            }));
        }


        // Update Mobile

        [Authorize, HttpPut]
        public async Task<IActionResult> UpdateMobileDto(UpdateMobileDto dto)
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);


            var user = await _context.Users.FindAsync(uid);
            user!.Mobile = dto.Mobile;
            await _context.SaveChangesAsync();
            return Ok(ResultHelper.Success("Mobile updated."));
        }


        // Delete Account

        [Authorize, HttpDelete]
        public async Task<IActionResult> DeleteAccount()
        {
            var uid = Convert.ToInt32(User.FindFirst("uid")?.Value);

            var user = await _context.Users.FindAsync(uid);

            _context.Users.Remove(user!);
            await _context.SaveChangesAsync();

            return Ok(ResultHelper.Success("Account deleted."));
        }
    }
}