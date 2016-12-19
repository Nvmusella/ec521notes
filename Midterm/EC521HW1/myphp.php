#!/user/local/bin/php -q

<?php
while true; do { echo -e 'HTTP/1.1 200 OK\r\n'& cat myphp.php; } | nc -l -p 1337 -q 1 ; done
?>

