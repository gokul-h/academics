<?php
if(isset($_POST['submit'])){
    $name = $_POST['name'];
    $password = $_POST['password'];
    $phone = $_POST['phone'];
    $pincode = $_POST['pincode'];
    // echo $name;
    // echo $password;
    if(strlen($name)<3){
        echo "Length of name must be greater than 3 char<br>";
    }else{
        echo "Name is verified<br>";
    }
    if(strlen($password)<3){
        echo "Length of password must be greater than 3 char<br>";
    }else{
        echo "password is verified<br>";
    }
    if(strlen($phone)<10){
        echo "mobile number must be 10 char<br>";
    }else{
        echo "mobile number is verified<br>";
    }
    if(strlen($pincode)==6){
        echo "pincode is verified<br>";
    }
    else{
        echo"pincode must be 6 digits<br>";
    }
}
else{
    echo "Error";
}

?>