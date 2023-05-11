<!DOCTYPE html>
<html lang="en">

<head>
    <title>Employee</title>
</head>

<body>
    <h1>Delete Employee</h1>
    <h2>Please fill up the form to delete an employee</h2>
    <form action="#" method="POST">
        <label for="id">ID:</label>
        <input type="number" name="id" id="id">
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
    $sql = "DELETE FROM info WHERE id='$id'";
    if ($conn->query($sql)) {
        echo "Record deleted successful";
    } else {
        echo "Error in deleting record";
    }
}

?>