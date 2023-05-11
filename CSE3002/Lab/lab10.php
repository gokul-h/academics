<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Form</title>
</head>

<body>
    <h1>Shopping</h1>
    <h3>Select the products to reveal total amount</h3>
    <form>
        <input type="checkbox" id="shirt" name="product" value="9.99" onclick="totalIt()">
        <label for="shirt">T shirt - <b>$9.99</b></label><br><br>
        <div>
            <input type="number" max="5" min="1" value="1" id="quantity" name="quantity" onclick="totalIt()">
            <label for="quantity">Quanitity</label>&emsp;
            <select id="color">
                <option>Red</option>
                <option>Green</option>
                <option>Blue</option>
            </select>
            <label for="color">Color</label>&emsp;
            <select id="size">
                <option>XS</option>
                <option>S</option>
                <option>M</option>
                <option>L</option>
                <option>XL</option>
                <option>XXL</option>
            </select>
            <label for="size">Size</label>
        </div><br>
        <input type="checkbox" id="mug" name="product" value="4.99" onclick="totalIt()">
        <label for="mug">Mug - <b>$4.99</b></label><br><br>
        <input type="checkbox" id="pencil" name="product" value="2.99" onclick="totalIt()">
        <label for="pencil">Pencil - <b>$2.99</b></label><br><br>
        <input type="checkbox" id="sticker" name="product" value="1.99" onclick="totalIt()">
        <label for="sticker">Sticker - <b>$1.99</b></label><br><br>

        <p>Total amount :
        <p id="total"></p>
        </p><br>


        <label for="username">Enter your username</label><br>
        <input type="text" maxlength="8" id="username" onblur="couponGenerator()"><br><br>
        <input type="button" value="Generate Coupon Code"><br><br>
        <label for="coupon">Coupon</label>
        <p id="coupon"></p><br>
        <label for="discount">Discount</label>
        <p id="discount"></p><br>
        <label for="discounted_price">Discounted Price</label>
        <p id="discounted_price"></p><br>
        <button style="background-color: orange;">Submit</button>

    </form>
    <script>
        function totalIt() {
            var input = document.getElementsByName("product");
            var q = document.getElementsByName("quantity");
            var total = 0;
            if (input[0].checked) {
                total += parseFloat(input[0].value) * parseFloat(q[0].value);
            }
            for (var i = 1; i < input.length; i++) {
                if (input[i].checked) {
                    total += parseFloat(input[i].value);
                }
            }
            document.getElementById("total").innerHTML = "$" + total.toFixed(2);
            var discounted_price = total * 0.9;
            var discount = 10;
            if (discounted_price >= 10) {
                discounted_price = total * 0.8;
                discount = 20;
            }
            document.getElementById("discount").innerHTML = discount;
            document.getElementById("discounted_price").innerHTML = discounted_price;
        }

        function couponGenerator() {
            var username = document.getElementById("username").value;
            let coupon = "";
            let length = username.length;
            if (length === 7) {
                coupon += (username.charAt(0));
                const count = username.match(/[aeiou]/gi).length;
                coupon += count;
                coupon += username.charAt(length - 1);
                coupon += "^";
                coupon += length - count;
            } else if (length === 8) {
                for (var i = 0; i < username.length; i++) {
                    coupon += username.charAt(i);
                }
            } else {
                coupon = "Not applicable";
            }
            document.getElementById("coupon").innerHTML = coupon;
        }
    </script>
</body>

</html>