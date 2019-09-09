<?php
$estado = filter_input(INPUT_GET, 'estado', FILTER_SANITIZE_NUMBER_FLOAT);

if (is_null($estado))	{
 //Gravar log de erros
 die("Dados inválidos");
} 
//$estado = number_format($temp / 100, 2, '.', '.');
require_once('conecta.php');
echo "Connected successfully";

$sqll = "UPDATE lampadas SET lamp_data= NOW(), lamp_estado = $estado WHERE lamp_id = 1";

$sql = "INSERT INTO lampadas_rel (lamp_id, lamp_estado) VALUES (1, $estado)";

if (!$conn->query($sqll)) {
  //Gravar log de erros
  die("Erro na gravação dos dados no BD");
}

if (!$conn->query($sql)) {
  //Gravar log de erros
  die("Erro na gravação dos dados no BD");
}
$conn->close();
?>
