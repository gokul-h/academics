<!DOCTYPE html>
<html lang="en">

<head>
    <title>Employee</title>
</head>

<body>
    <h1>Update Salary</h1>
    <h2>Please fill up the form to update an entry</h2>
    <form action="#" method="POST">
        <label for="id">ID:</label>
        <input type="number" name="id" id="id">
        <br><br>
        <label for="salary">New Salary:</label>
        <input type="number" name="salary" id="salary" max="999999999">
        <br><br>
        <input type="submit" name="submit" id="submit">
    </form>
    <h1 id="employee_id"></h1>
</body>

</html>
<?php
$servername = "localhost";
$username = "root";
$user_name = "";
$dbname = "employee";


$conn = new mysqli($servername, $username, $user_name, $dbname);
if ($conn->connect_error) {
    die("Connection failed" . $conn->connect_error);
}

if (isset($_POST['submit'])) {
    $id = $_POST['id'];
    $salary = $_POST['salary'];
    $sql = "UPDATE info SET salary='$salary' WHERE id='$id'";
    if ($conn->query($sql)) {
        echo "Record modified successful";
    } else {
        echo "Error in modifying record";
    }
}

?>