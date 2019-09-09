<?php
$estado = filter_input(INPUT_GET, 'estado', FILTER_SANITIZE_NUMBER_FLOAT);
$viola = filter_input(INPUT_GET, 'viola', FILTER_SANITIZE_NUMBER_FLOAT);
$violac = filter_input(INPUT_GET, 'violac', FILTER_SANITIZE_NUMBER_FLOAT);

if (is_null($estado))	{
 if (is_null($viola))	{
 //Gravar log de erros
 die("Dados inválidos");
}
}
if (is_null($viola))	{
 if (is_null($estado))	{	
 //Gravar log de erros
 die("Dados inválidos");
 }
} 
//$estado = number_format($temp / 100, 2, '.', '.');
require_once('conecta.php');
echo "Connected successfully";
if(isset($estado)){
	$sql = "UPDATE alarme SET alarme_data= NOW(), alarme_estado = $estado, alarme_violado = $violac WHERE alarme_id = 1";
	echo "<br>Atualizando estado do Alarme";
	if (!$conn->query($sql)) {
	//Gravar log de erros
	die("Erro na gravação dos dados no BD");
	}
}

if(isset($viola)){
	$sql = "INSERT INTO alarme_rel (alarme_id, alarme_violado) VALUES (1, $viola)";
	echo "<br>Inserindo Violacao";
	if (!$conn->query($sql)) {
	//Gravar log de erros
	die("Erro na gravação dos dados no BD");
	}
	$sql = "UPDATE alarme SET alarme_violado = $violac WHERE alarme_id = 1";
	if (!$conn->query($sql)) {
	//Gravar log de erros
	die("Erro na gravação dos dados no BD");
	}
}
	$conn->close();
?>
