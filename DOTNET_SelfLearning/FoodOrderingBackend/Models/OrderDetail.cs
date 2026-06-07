using System;
using System.Collections.Generic;

namespace FoodOrderingBackend.Models;

public partial class OrderDetail
{
    public int OdId { get; set; }

    public int? Oid { get; set; }

    public int? Fid { get; set; }

    public int? Quantity { get; set; }

    public decimal? Price { get; set; }

    public virtual Food? FidNavigation { get; set; }

    public virtual Order? OidNavigation { get; set; }
}
