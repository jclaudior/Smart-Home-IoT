<?php
require_once('conecta.php');
$sql = "SELECT lamp_estado, lamp_descricao FROM lampadas ORDER BY lamp_id";
$result = $conn->query($sql);
	if ($result->num_rows > 0) {
		// output data of each row
		
		$array = array();
		$array2 = array();
		while($row = $result->fetch_assoc()) {
		$array[] = $row["lamp_estado"];
		$array2[] = $row["lamp_descricao"];
		}
	}
	$estado1=$array[0];
	$estado2=$array[1];
	$estado3=$array[2];
	$estado4=$array[3];
	$estado5=$array[4];
	
	$descri1=$array2[0];
	$descri2=$array2[1];
	$descri3=$array2[2];
	$descri4=$array2[3];
	$descri5=$array2[4];
	
?>