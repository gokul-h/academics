<!DOCTYPE html>
<html lang="en">

<head>
    <title>Employee</title>
</head>

<body>
    <h1>Salary greater than average salary</h1>
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

$sql = "SELECT * FROM info having salary > (SELECT AVG(salary) FROM info)";
$res1 = $conn->query($sql);
if ($res1 != False) {
    echo "
    <table>
        <thead>
              <tr>
                <th scope=\"col\">ID</th>
                <th scope=\"col\">Name</th>
                <th scope=\"col\">Qualification</th>
                <th scope=\"col\">Designation</th>
                <th scope=\"col\">Salary</th>
              </tr>
            </thead>
            <tbody>
        ";
    while ($row1 = $res1->fetch_assoc()) {
        echo "
     
          <tr>
          <td>" . $row1["id"] . "</td>
          <td>" . $row1["name"] . "</td>
          <td>" . $row1["designation"] . "</td>
          <td>" . $row1["qualification"] . "</td>
          <td>" . $row1["salary"] . "</td>
          </tr>";
    }
    echo "</tbody><table>";
} else {
    echo "Error in acessing records";
}


?>