<?php
$nome = $_COOKIE['login'];
//$estado = number_format($temp / 100, 2, '.', '.');
require_once('conecta.php');
echo "Connected successfully";

$sql = "INSERT INTO acesso_rel (acesso_id, acesso_nome, acesso_data) VALUES (1, '$nome', NOW() )";

if (!$conn->query($sql)) {
  //Gravar log de erros
  die("Erro na gravação dos dados no BD");
}

header("Location:acesso.php");

$conn->close();
?>