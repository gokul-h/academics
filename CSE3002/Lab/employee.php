<!DOCTYPE html>
<html lang="en">

<head>
    <title>Employee</title>
</head>

<body>
    <h1>Employee Details</h1>
    <h2>Please fill up the form to add an entry</h2>
    <form action="#" method="POST">
        <label for="id">ID:</label>
        <input type="number" name="id" id="id">
        <br><br>
        <label for="name">Name:</label>
        <input type="text" name="name" id="name">
        <br><br>
        <label for="age">Age:</label>
        <input type="number" name="age" id="age" max="200">
        <br><br>
        <label for="qualification">Qualification:</label>
        <input type="text" name="qualification" id="qualification">
        <br><br>
        <label for="designation">Designation:</label>
        <input type="text" name="designation" id="designation">
        <br><br>
        <label for="salary">Salary:</label>
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
    $name = $_POST['name'];
    $age = $_POST['age'];
    $qualification = $_POST['qualification'];
    $designation = $_POST['designation'];
    $salary = $_POST['salary'];
    $sql = "INSERT INTO info VALUES('$id','$name', $age, '$qualification', 
    '$designation', $salary)";
    if ($conn->query($sql)) {
        echo "Record added successful";
    } else {
        echo "Error in inserting record";
    }
}

?>