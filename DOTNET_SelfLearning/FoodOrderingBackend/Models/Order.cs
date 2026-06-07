using System;
using System.Collections.Generic;

namespace FoodOrderingBackend.Models;

public partial class Order
{
    public int Oid { get; set; }

    public int? Uid { get; set; }

    public decimal? TotalAmount { get; set; }

    public DateTime? OrderDate { get; set; }

    public virtual ICollection<OrderDetail> OrderDetails { get; set; } = new List<OrderDetail>();

    public virtual User? UidNavigation { get; set; }
}
