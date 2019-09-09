<html>
<head>
	<script language="JavaScript" src="js/resolu.js"></script>
	<script>
	     window.history.forward(1);
	</script>
</head>
<body>
<?php
$login_cookie = $_COOKIE['login'];
if(isset($_COOKIE['login'])){
require_once('conecta.php');
$sqll = "SELECT lamp_descricao FROM lampadas";
$result2 = $conn->query($sqll);
if ($result2->num_rows > 0) {
		// output data of each row
		$array2 = array();
		while($row1 = $result2->fetch_assoc()) {
		$array2[] = $row1["lamp_descricao"];
		}
}
        $descri1=$array2[0];
		$descri2=$array2[1];
		$descri3=$array2[2];
		$descri4=$array2[3];
		$descri5=$array2[4];
		
?>
<form action="lamprel.php" method="POST">
    <table class="tabelarel2" align="center">
		<tr>
			<td colspan="2" width="80%"><a class='texto'>Bem-Vindo,<?php echo $login_cookie; ?></td>
			<td colspan="1" width="20%"><a class="botaocadper" href="logout.php">SAIR</a></td>
			
		</tr>
		<tr>
			<td colspan="3" align="center"><img src="img/iot.jpg" class="imgcap"></img>
		</tr>
		<tr>
			<td width="40%">
				<a>Data Inicial</a>
				<input type="datetime-local" name="dataI" class="selectper" />
			</td>
			<td width="40%">
				<a>Data Final</a>
				<input type="datetime-local" name="dataF" class="selectper"/>
			</td>
			<td width="20%">
				<select name="id" class="selectper">
				<option value="">Lampada</option>
				<option value="1"><?php echo $descri1; ?></option>
				<option value="2"><?php echo $descri2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td colspan="3">
				<input type="submit" class="botaocadper"/>
				</form>
			</td>
	</table>
	<a class="textorel" align="center">
	<table	border="1"  class="tabelarel" align="center">
	<tr>
	<td colspan="3" border="0">
<?php
	if(empty($_POST['id']) && empty($_POST['dataI']) && empty($_POST['dataF'])){
		$sql = "SELECT lamp_id, lamp_data, lamp_estado FROM lampadas_rel ORDER BY lamp_sec DESC limit 10";
		echo "Ultimas 10 Ações";
	}elseif(isset($_POST['id']) && empty($_POST['dataI']) && empty($_POST['dataF'])){
		$sql = "SELECT lamp_id, lamp_data, lamp_estado FROM lampadas_rel WHERE lamp_id = '".$_POST['id']."' ORDER BY lamp_sec DESC limit 10";
		echo "Ultimas 10 Ações da lampada "; if($_POST['id']==1){echo $descri1;}else{echo $descri2;}
	}elseif(empty($_POST['id']) && isset($_POST['dataI']) && isset($_POST['dataF'])){
		$sql = "SELECT lamp_id, lamp_sec, lamp_estado, lamp_data FROM lampadas_rel WHERE lamp_data >= '".$_POST['dataI']."' AND lamp_data <= '".$_POST['dataF']."' ORDER BY  lamp_sec";
		$dt = Date('d/m/Y H:i:s',  strtotime($_POST['dataI']));
		$dt2 = Date('d/m/Y H:i:s',  strtotime($_POST['dataF']));
		echo "Ações do periodo ".$dt." até " .$dt2.""; 
	}elseif(isset($_POST['id']) && isset($_POST['dataI']) && isset($_POST['dataF'])){
		$sql = "SELECT lamp_id, lamp_sec, lamp_estado, lamp_data FROM lampadas_rel WHERE lamp_data >= '".$_POST['dataI']."' AND lamp_data <= '".$_POST['dataF']."' AND lamp_id = '".$_POST['id']."' ORDER BY  lamp_sec";
		$dt = Date('d/m/Y H:i:s',  strtotime($_POST['dataI']));
		$dt2 = Date('d/m/Y H:i:s',  strtotime($_POST['dataF']));
		echo "Ações do periodo ".$dt." até " .$dt2." da lampada "; if($_POST['id']==1){echo $descri1;}else{echo $descri2;}
	}else{
		$sql = "SELECT lamp_id, lamp_data, lamp_estado FROM lampadas_rel ORDER BY lamp_sec DESC limit 10";
		echo "Ultimas 10 Ações";
	}
		
$result = $conn->query($sql);
if ($result->num_rows > 0) {
    ?>
	</td>
	</tr>
	
	
	<tr><td><h4>DESCRIÇÃO</h4></td><td><h4>DATA</h4></td><td><h4>ESTADO</h4></td></tr>
	<?php
	while($row = $result->fetch_assoc()) {
        
	$data = Date('d/m/Y H:i:s',  strtotime($row["lamp_data"]));
	$status = "DESLIGADO";
	if ($row["lamp_estado"]==1){
		$status = "LIGADO";
	}
	$descr = $descri2;
	if(	$row["lamp_id"]==1){
	$descr = $descri1;	
	}
	
    
    echo "<tr><td>".$descr. "</td><td>" .$data. "</td><td>" .$status. "</td></tr>";
	 
	}
}	else {
    echo "Não foi encontrado nenhum resultado nesta busca!!";
}

	 ?>
	 <tr>
		<td colspan="3"><a class="botaocadper" href="lampadas.php">Voltar</a></td>
	 </tr>
	 </table>
    
	
<?php



$conn->close();
}else{
	  echo"Bem-Vindo, convidado <br>";
      echo" <font color='red'>Essas informações NÃO PODEM ser acessadas por você</font> ";
      echo"<br><a href='index.html'>Faça Login</a> Para ler o conteúdo";
}
//echo "<meta HTTP-EQUIV='refresh' CONTENT='5;URL=lamprel.php'>";
?>


	

</body>
</html>