<?php
$cookie_name = "IWP";
$cookie_value = "COLOR";
setcookie($cookie_name, $cookie_value, time() + (86400 * 3), "/");
?>
<html>

<body>

    <?php
    if (!isset($_COOKIE[$cookie_name])) {
        echo "Cookie named '" . $cookie_name . "' is not set!";
    } else {
        echo "Cookie '" . $cookie_name . "' is set!<br>";
        echo "Value is: " . $_COOKIE[$cookie_name];
    }
    ?>

</body>

</html>