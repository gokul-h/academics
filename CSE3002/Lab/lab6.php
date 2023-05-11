<html>
    <head>
        <title>PHP Form</title>
    </head>
    <body>
    <h1 style="text-align: center;">PHP Form Validation</h1>
        <p style="text-align: center;">
            <script>document.write(new Date())</script>
        </p>
        <div style="align-content: center;align-items: center;border: 2px solid black;background-color: aqua;text-align:center;">
            <form action="#" method="post">
                Name:<input type="text" name='name'><br>
                Password:<input type="text" name="password"><br>
                Contact no:<input type="number" name="phone"><br>
                Pincode:<input type="number" maxlength="6" name="pincode"><br>
                <input type="submit" name="submit">
            </form>
        </div>
    </body>
</html>
<?php
if(isset($_POST['submit'])){
    $name = $_POST['name'];
    $password = $_POST['password'];
    $phone = $_POST['phone'];
    $pincode = $_POST['pincode'];
    echo "Messages <br>";
    if(strlen($name)<3){
        echo "Length of name must be greater than 3 char<br>";
    }else{
        echo "Name is verified<br>";
    }
    if(strlen($password)<3){
        echo "Length of password must be greater than 3 char<br>";
    }else{
        echo "Password is verified<br>";
    }
    if(strlen($phone)<10){
        echo "Mobile number must be 10 char<br>";
    }else{
        echo "Mobile number is verified<br>";
    }
    if(strlen($pincode)==6){
        echo "Pincode is verified<br>";
    }
    else{
        echo"pincode must be 6 digits<br>";
    }
}
else{
    echo "Error";
}

?>