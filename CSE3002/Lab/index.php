<html>
   <head>
      <title>
         Shopping
      </title>
      <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
<style>
div {
  padding-top: 10px;
  padding-right: 10px;
  padding-bottom: 10px;
  padding-left: 10px;
}
</style>
   </head>
   <body>
      <nav class="navbar navbar-light bg-light">
         <div class="container-fluid">
            <a class="navbar-brand" href="#">Shopping Website</a>
         </div>
         <div></div>
      </nav>
      <div class = "card-group">
<?php
$servername = "localhost";
$username = "root";
$user_name = "";
$dbname = "items";

$conn = new mysqli($servername, $username, $user_name, $dbname);
if ($conn->connect_error)
{
    die("Connection failed" . $conn->connect_error);
}

$sql1 = "SELECT * FROM item_table";
$res1 = $conn->query($sql1);

if ($res1 != False)
{
    while ($row1 = $res1->fetch_assoc())
    {
        echo "<div>
<div id='card'>
            <div class='card' style='width: 18rem;'>
               <img src='".$row1["Image"]."' class='card-img-top' alt='None'>
               <div class='card-body'>
                  <h5 class='card-title'>".$row1["Name"]."</h5>
                    <h6 class='card-title'>Price:".$row1["Price"]."</h6>
                  <p class='card-text'>".$row1["Description"]."</p>
                    <p>".$row1["Origin"]."</p>
                  <a href='#' class='btn btn-primary'>Add to Cart</a>
               </div>
            </div>
         </div></div> ";
    }
}
else
{
    echo "<br><h2 class=\"text-center\">No Items in Inventory<h2>";
}

$conn->close();
?>

      </div>
   </body>
</html>

