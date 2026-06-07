using System;
using System.Collections.Generic;

namespace FoodOrderingBackend.Models;

public partial class Food
{
    public int Fid { get; set; }

    public string? Name { get; set; }

    public decimal? Price { get; set; }

    public string? Description { get; set; }

    public string? ImageFilename { get; set; }

    public virtual ICollection<OrderDetail> OrderDetails { get; set; } = new List<OrderDetail>();
}
