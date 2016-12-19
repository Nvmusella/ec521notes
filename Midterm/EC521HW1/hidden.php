<?php
if (strpos($_SERVER['HTTP_REFERER'],"woot") != false) {   # only show if linked from hidden.html
echo "Your Super Secret Password is '".strtr($_SERVER['REMOTE_ADDR'],"0123456789.","ABCDEFGHIJK")."'";
}
else {
echo "Nothing to see here ... please move on.";
}
?>
