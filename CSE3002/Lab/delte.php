<?php
$servername = "localhost";
$username = "root";
$user_name = "";
$dbname = "mydb";


$conn = new mysqli($servername, $username, $user_name, $dbname);
if ($conn->connect_error) {
    die("Connection failed" . $conn->connect_error);
}


// 2.Form validation 
if (isset($_POST['submit'])) {
    $reg_no = $_POST['reg_no'];
    $flag=0;
    echo "Messages <br>";
    if (strlen($reg_no) > 6) {
        echo "Length of Registraion number must be less than 6 char<br>";
        $flag = 1;
    } else {
        echo "Registration number is verified<br>";
    }
    if ($flag == 0) {
        //3. Insert into table
        $sql5 = "DELETE FROM student WHERE 'regno'=$reg_no;";
        //echo $sql5;
        if ($conn->query($sql5)) {
            echo "Record deleted successful";
        } else {
            echo "Error in deleting record";
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
    <h1 style="text-align: center;">Delete Data</h1>
    <p style="text-align: center;">
        <script>
            document.write(new Date())
        </script>
    </p>
    <div style="align-content: center;align-items: center;border: 2px solid black;background-color: aqua;text-align:center;">
        <form action="#" method="post">
            Register number:<input type="text" name='reg_no'><br>
            <input type="submit" name="submit">
        </form>
    </div>
</body>

</html>