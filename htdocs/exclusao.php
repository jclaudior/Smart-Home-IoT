<html>
<head>
	<script language="JavaScript" src="js/resolu.js"></script-->
	<script>
	     window.history.forward(1);
	</script>
</head>

<body>
<?php
	$login_cookie = $_COOKIE['login'];
    if(isset($login_cookie)){?>	
<table class="tabelarel2" align="center" border="0">
	<tr>
		<td colspan="2" width="80%"><a class='texto'>Bem-Vindo,<?php echo $login_cookie; ?></td>
		<td colspan="1" width="20%"><a class="botaocadper" href="logout.php">SAIR</a></td>
	</tr>
	<tr>
		<td colspan="3" align="center"><img src="img/iot.jpg" class="imgcap"></img>
	</tr>
	<tr>
		<td colspan="3"><h4 class='texta1'align="center" >EXCLUSÃO DE USUÁRIO</h4></td>
	</tr>
<form action="exclusao.php" method="POST">
<?php
	require_once('conecta.php');
	$sql = "SELECT login FROM usuarios";
	$result = $conn->query($sql);
	if ($result->num_rows > 0) {
		while($row = $result->fetch_assoc()) {
		echo "<td colspan='4'><input type='radio' id='contactChoice1' name='Login' value='".$row["login"]."'><a class='texta3'> ".$row["login"]."</a></td></tr>";
		}
	}
	
	
	
	
?>
	<tr>
		<td colspan="3"><input type="submit" class="botaocadper" value="Excluir"></input></td>
	</tr>
	<tr>
		<td colspan="3"><a class="botaocadper" href="inicial.php">Voltar</a></td>
	</tr>
</form>
</table >
		
<?php
	if(isset($_POST['Login'])){
		$Login = $_POST['Login'];
		$sql = "DELETE FROM usuarios WHERE login ='".$Login."'";
		if (!$conn->query($sql)) {
			
		}else{
		echo "<script>alert ('Usuario ".$Login." Excluido com sucesso!!!!')</script>";
		}
	}
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