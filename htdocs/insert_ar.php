<?php
$est = filter_input(INPUT_GET, 'est', FILTER_SANITIZE_NUMBER_FLOAT);
$temp = filter_input(INPUT_GET, 'temp', FILTER_SANITIZE_NUMBER_FLOAT);

if (is_null($est && $temp))	{
 //Gravar log de erros
 die("Dados inválidos");
} 
//$estado = number_format($temp / 100, 2, '.', '.');
require_once('conecta.php');
echo "Connected successfully";

$sqll = "UPDATE ar SET ar_data= NOW(), ar_estado = $est, ar_temp = $temp WHERE ar_id = 1";

//$sql = "INSERT INTO lampadas_rel (lamp_id, lamp_estado) VALUES (1, $estado)";
echo " estado recebido .$est. e temperatura .$temp." ;
if (!$conn->query($sqll)) {
  //Gravar log de erros
  
  die("Erro na gravação dos dados no BD");
}

$conn->close();
?>
