<?php
$servername = "localhost";
$username = "root";
$user_name = "";
$dbname = "mydb";


$conn = new mysqli($servername, $username, $user_name, $dbname);
if ($conn->connect_error) {
    die("Connection failed" . $conn->connect_error);
}
// 1. Create and connect table
$sql1 = "SHOW DATABASES LIKE 'mydb'";
$sql11 = "USE mydb";
$sql2 = "SHOW TABLES LIKE 'student'";
if ($conn->query($sql1)) {
    echo "Database exist<br>";
    if ($conn->query($sql11)) {
        echo "Conection sucessful<br>";
    } else {
        echo "Cant cnnect to database" . $conn->error;
    }
    if ($conn->query($sql2)) {
        echo "Table exist<br>";
        
    } else {
        $sql3 = "use mydb; CREATE TABLE student (regno INT(6) PRIMARY KEY, usersname VARCHAR(30), gpa INT(1), email VARCHAR(30));";
        if ($conn->query($sql3)) {
            echo "Table created sucessfully";
        } else {
            echo "Error creating table: " . $conn->error;
        }
    }
} else {
    $sql4 = "CREATE DATABASE mydb";
    if ($conn->query($sql) === TRUE) {
        echo "Database created successfully";
    } else {
        echo "Error creating database: " . $conn->error;
    }
}

// 2.Form validation 
if (isset($_POST['submit'])) {
    $reg_no = $_POST['reg_no'];
    $user_name = $_POST['user_name'];
    $gpa = $_POST['gpa'];
    $email = $_POST['email'];
    $flag = 0;
    echo "Messages <br>";
    if (strlen($reg_no) > 6) {
        echo "Length of Registraion number must be less than 6 char<br>";
        $flag = 1;
    } else {
        echo "Registration number is verified<br>";
    }
    if (strlen($user_name) < 5) {
        echo "Length of Name must be greater than 5 char<br>";
        $flag = 1;
    } else {
        echo "Name is verified<br>";
    }
    if (strlen($gpa) != 1) {
        echo "GPA must be 1 number<br>";
        $flag = 1;
    } else {
        echo "GPA is verified<br>";
    }
    if (strlen($email) == 0) {
        echo "Please enter a valid email<br>";
        $flag = 1;
    } else {
        echo "Email validated<br>";
    }
    if ($flag == 0) {
        //3. Insert into table
        $sql5 = "INSERT INTO student VALUES ('$reg_no', '$user_name', $gpa, '$email')";
        //echo $sql5;
        if ($conn->query($sql5)) {
            echo "Record added successful";
        } else {
            echo "Error in inserting record";
        }
    }
} else {
    echo "Please Submit the form<br>";
}




$conn->close();
?>
<html>

<head>
    <title>PHP Form</title>
</head>

<body>
    <h1 style="text-align: center;">PHP Form Database</h1>
    <p style="text-align: center;">
        <script>
            document.write(new Date())
        </script>
    </p>
    <div style="align-content: center;align-items: center;border: 2px solid black;background-color: aqua;text-align:center;">
        <form action="#" method="post">
            Register number:<input type="text" name='reg_no'><br>
            Name:<input type="text" name="user_name"><br>
            GPA (single digit):<input type="number" maxlength="1" name="gpa"><br>
            Email:<input type="email" name="email"><br>
            <input type="submit" name="submit">
        </form>
    </div>
</body>

</html>