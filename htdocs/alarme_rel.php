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
?>
<form action="alarme_rel.php" method="POST">
    <table class="tabelatemrel2" align="center">
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
			<td colspan="3">
				<input type="submit" class="botaocadper"/>
			</td>
		</tr>
		
	</table>
	</form>
	<table border ="1" align="center" class="tabelatemrel">
	<tr>
	<td colspan="4">
	<h4>
<?php
	require_once('conecta.php');
	
	if(empty($_POST['dataI'])&& empty($_POST['dataF'])){
		$sql = "SELECT alarme_data FROM alarme_rel ORDER BY alarme_sec DESC limit 10";
		echo "10 Ultimas gravacoes de Violacao do Alarme";
	}elseif(isset($_POST['dataI']) && isset ($_POST['dataF'])){
		$sql = "SELECT alarme_data FROM alarme_rel WHERE alarme_data >= '".$_POST['dataI']."' AND alarme_data <= '".$_POST['dataF']."' ORDER BY alarme_sec DESC";
		$dtaI = $_POST['dataI'];
		$dtaF = $_POST['dataF'];
		echo "Gravacoes de Violacao do alarme entre '".$dtaI."' e '".$dtaF."' ";
	}
	
	$result = $conn->query($sql);

?>
	</h4>
	</td>
	</tr>
	<tr>
		<td><h3>DATA DA VIOLAÇÃO</h3></td>
	</tr>
	

<?php
if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        
	 $data = Date('d/m/Y H:i:s',  strtotime($row["alarme_data"]));
     echo "<tr><td> " .$data."</td></tr>";
	 
	}
} else {
    echo "0 results";
}
$conn->close();
//echo "<meta HTTP-EQUIV='refresh' CONTENT='5;URL=temperatura_rel.php'>";
}else{
	  echo"Bem-Vindo, convidado <br>";
      echo" <font color='red'>Essas informa??es N?O PODEM ser acessadas por voc?</font> ";
      echo"<br><a href='index.html'>Fa?a Login</a> Para ler o conte?do";
}
?>
<tr>
		<td colspan="4"><a class="botaocadper" href="alarme.php">Voltar</a></td>
</tr>
</table>
</body>
</html>