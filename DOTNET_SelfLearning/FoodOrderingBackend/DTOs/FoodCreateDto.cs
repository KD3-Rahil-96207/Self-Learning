namespace FoodOrderingBackend.DTOs
{
    public class FoodCreateDto
    {
        public string Name { get; set; }

        public decimal Price { get; set; }

        public string Description { get; set; }

        public IFormFile? Image { get; set; }
    }
}
