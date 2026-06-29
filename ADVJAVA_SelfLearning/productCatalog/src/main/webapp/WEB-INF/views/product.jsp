

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="jakarta.tags.core" prefix="c"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Products</title>

<style>
*{
    margin:0;
    padding:0;
    box-sizing:border-box;
    font-family:Arial, Helvetica, sans-serif;
}

body{
    background:#f4f6f9;
    padding:40px;
}

.container{
    max-width:900px;
    margin:auto;
    background:#fff;
    padding:30px;
    border-radius:12px;
    box-shadow:0 8px 20px rgba(0,0,0,0.15);
}

h2{
    text-align:center;
    margin-bottom:25px;
    color:#333;
}

table{
    width:100%;
    border-collapse:collapse;
}

thead{
    background:#007bff;
    color:white;
}

th, td{
    padding:14px;
    text-align:center;
    border-bottom:1px solid #ddd;
}

tbody tr:nth-child(even){
    background:#f8f9fa;
}

tbody tr:hover{
    background:#e8f1ff;
    transition:0.3s;
}

.price{
    color:#28a745;
    font-weight:bold;
}

.stock{
    font-weight:bold;
}
</style>

</head>

<body>

<div class="container">

    <h2>Product List</h2>

    <table>

        <thead>
            <tr>
                <th>ID</th>
                <th>Product Name</th>
                <th>Price (₹)</th>
                <th>Stock</th>
            </tr>
        </thead>

        <tbody>

            <c:forEach var="product" items="${requestScope.product_list}">
                <tr>
                    <td>${product.product_id}</td>
                    <td>${product.product_name}</td>
                    <td class="price">${product.price}</td>
                    <td class="stock">${product.stock}</td>
                </tr>
            </c:forEach>

        </tbody>

    </table>

</div>

</body>
</html>





















<%--   <%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="jakarta.tags.core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Product</title>
</head>
<body>
	<h3>Product List</h3>
	<br>
	<table>
		<thead>
			<tr>
				<td>id</td>
				<td>Name</td>
				<td>Price</td>
				<td>Stock</td>
			</tr>
		</thead>
		<tbody>
			<c:forEach var="product" items="${requestScope.product_list}">
				<tr>
					<td>${product.product_id}</td>
					<td>${product.product_name}</td>
					<td>${product.price}</td>
					<td>${product.stock}</td>
				</tr>
			
			</c:forEach>
		</tbody>
	</table>
</body>
</html>  --%>