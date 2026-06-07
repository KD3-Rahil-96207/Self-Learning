namespace FoodOrderingBackend.Models
{
    public class ResultHelper
    {
        public static ApiResult Success(object data)
        {
            return new ApiResult
            {
                Status = "success",
                Data = data,
                Error = null
            };
        }

        public static ApiResult Failure(string error)
        {
            return new ApiResult
            {
                Status = "error",
                Data = null,
                Error = error
            };  
        }
    }
}
