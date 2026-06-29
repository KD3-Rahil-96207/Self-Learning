

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="jakarta.tags.core" prefix="c"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Product Catalog</title>

<style>
*{
    margin:0;
    padding:0;
    box-sizing:border-box;
    font-family:Arial, Helvetica, sans-serif;
}

body{
    background:#f4f6f9;
    height:100vh;
    display:flex;
    justify-content:center;
    align-items:center;
}

.container{
    background:#fff;
    padding:35px;
    border-radius:12px;
    box-shadow:0 8px 20px rgba(0,0,0,0.15);
    width:380px;
}

h2{
    text-align:center;
    margin-bottom:25px;
    color:#333;
}

label{
    display:block;
    margin-bottom:8px;
    font-weight:bold;
    color:#555;
}

select{
    width:100%;
    padding:10px;
    font-size:16px;
    border:1px solid #ccc;
    border-radius:6px;
    outline:none;
    margin-bottom:20px;
}

select:focus{
    border-color:#007bff;
}

input[type="submit"]{
    width:100%;
    padding:12px;
    background:#007bff;
    color:white;
    border:none;
    border-radius:6px;
    font-size:16px;
    cursor:pointer;
    transition:0.3s;
}

input[type="submit"]:hover{
    background:#0056b3;
}
</style>

</head>
<body>

<div class="container">

    <h2>Product Catalog</h2>

    <form action="product" method="post">

        <label>Select Category</label>

        <select name="categoryId">
            <c:forEach var="category" items="${requestScope.category_list}">
                <option value="${category.category_id}">
                    ${category.category_name}
                </option>
            </c:forEach>
        </select>

        <input type="submit" value="Show Products">

    </form>

</div>

</body>
</html>








<%-- <%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="jakarta.tags.core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Home</title>
</head>
<body>
	<form action="product" method="post">
	
		<select name="categoryId">
	        <c:forEach var="category" items="${requestScope.category_list}">
	            <option value="${category.category_id}">
	                ${category.category_name}
	            </option>
	        </c:forEach>
    	</select>
    	<br>
    	<input type="submit">
    	
	</form>
</body>
</html> --%>










