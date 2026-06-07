namespace FoodOrderingBackend.DTOs
{
    public class PlaceOrderDto
    {
        public List<CartItemDto> CartItems { get; set; }

        public decimal TotalAmount { get; set; }
    }
}
