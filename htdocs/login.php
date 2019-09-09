<?php 
  $login = $_POST['login'];
  $entrar = $_POST['entrar'];
  $senha = md5($_POST['senha']);
  require_once('conecta.php');
    if (isset($entrar)) {
             
      $sql = "SELECT * FROM usuarios WHERE login = '$login' AND senha = '$senha'";
	  $result = $conn->query($sql);
        if ($result->num_rows <=0){
          echo"<script language='javascript' type='text/javascript'>alert('Login e/ou senha incorretos');window.location.href='index.html';</script>";
          die();
        }else{
          setcookie("login",$login);
          header("Location:inicial.php");
        }
    }
?>