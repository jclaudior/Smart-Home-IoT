<?php
$estado = filter_input(INPUT_GET, 'estado', FILTER_SANITIZE_NUMBER_FLOAT);

if (is_null($estado))	{
 //Gravar log de erros
 die("Dados inválidos");
} 
//$estado = number_format($temp / 100, 2, '.', '.');
require_once('conecta.php');
echo "Connected successfully";

$sqll = "UPDATE acesso SET acesso_data= NOW(), acesso_estado = $estado WHERE acesso_id = 1";


if (!$conn->query($sqll)) {
  //Gravar log de erros
  die("Erro na gravação dos dados no BD");
}

$conn->close();
?>