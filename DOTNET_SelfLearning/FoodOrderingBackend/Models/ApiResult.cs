namespace FoodOrderingBackend.Models
{
    public class ApiResult
    {
        public string Status { get; set; }

        public Object? Data { get; set; }

        public string? Error { get; set; }
    }
}
