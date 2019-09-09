<?php
setcookie('login');
session_start();
if(session_destroy())
{
header('Location: index.html');
}
?>