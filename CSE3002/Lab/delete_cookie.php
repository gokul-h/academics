<?php
// set the expiration date to one hour ago
setcookie("IWP", "", time() - 3600);
?>
<html>

<body>

    <?php
    echo "Cookie 'IWP' is deleted.";
    ?>

</body>

</html>