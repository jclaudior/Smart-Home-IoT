<?php
$temp = filter_input(INPUT_GET, 'temp', FILTER_SANITIZE_NUMBER_FLOAT);
$humid = filter_input(INPUT_GET, 'humid', FILTER_SANITIZE_NUMBER_FLOAT);

if (is_null($temp) || is_null($humid) ) {
 //Gravar log de erros
 die("Dados inválidos");
} 
$temp = number_format($temp / 100, 2, '.', '.');
$humid = number_format($humid / 100, 2, '.', '.');
require_once('conecta.php');
echo "Connected successfully";
$sql = "INSERT INTO weather (wea_temp, wea_humid,wea_name) VALUES ($temp, $humid, 'sensor1')";
//$sql = "UPDATE weather SET wea_date= NOW(), wea_temp = $temp, wea_humid = $humid WHERE wea_name = 'sensor1'";

if (!$conn->query($sql)) {
  //Gravar log de erros
  die("Erro na gravação dos dados no BD");
}
$conn->close();
?>
