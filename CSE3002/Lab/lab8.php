<html>

<head>
    <title>PHP Form</title>
    <script>
        function viewDate() {
            var today = new Date();
            var date = today.getFullYear()+'-'+(today.getMonth()+1)+'-'+today.getDate();
            var input = document.getElementById("date");
            document.getElementById("rdate").innerHTML = input;
            document.getElementById("tdate").innerHTML = date;
        }
    </script>
</head>

<body>
    <h1 style="text-align: center;">Lab 8 Gokul H - Form Validation</h1>
    <p style="text-align: center;">
        
    </p>
    <div>
        <form action="#" method="post"   style="align-content: center;align-items: center;text-align:center;" >
            <div class="form-group">
                <label for="name">Name:</label><br>
                <input type="text" name='name'><br>
                <label for="name">address:</label><br>
                <input type="text" name="address"><br>
                <label for="name">Contact no:</label><br>
                <input type="number" name="phone"><br>
                <label for="name">Pincode:</label><br>
                <input type="number" maxlength="6" name="pincode"><br>
                <label for="name">Date:</label><br>
                <input type="date" id="date" onchange="viewDate()"><br>
                <label for="name">Readonly date</label><br>
                <input type="date" id="rdate" readonly><br>
                <label for="name" onload="viewDate()">Today date</label><br>
                <div  style="border: 2px solid black;"><script>  document.write(new Date());</script></div>
                
                <label for="name">Card</label><br>
                <input type=number id="card"><br>
                <input type="submit" name="submit">
            </div>
        </form>
    </div>
</body>

</html>
<?php
if (isset($_POST['submit'])) {
    $name = $_POST['name'];
    $address = $_POST['address'];
    $phone = $_POST['phone'];
    $pincode = $_POST['pincode'];
    echo "Messages <br>";
    if (strlen($name) < 3) {
        echo "Length of name must be greater than 3 char<br>";
    } else {
        echo "Name is verified<br>";
    }
    if (strlen($address) < 3) {
        echo "Length of address must be greater than 3 char<br>";
    } else {
        echo "address is verified<br>";
    }
    if (strlen($phone) < 10) {
        echo "Mobile number must be 10 char<br>";
    } else {
        echo "Mobile number is verified<br>";
    }
    if (strlen($pincode) == 6) {
        echo "Pincode is verified<br>";
    } else {
        echo "pincode must be 6 digits<br>";
    }
} else {
    echo "Error";
}

?>