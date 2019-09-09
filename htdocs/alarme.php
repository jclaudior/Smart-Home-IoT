<html>
<head>
<script src="js/alarme.js"></script>
<script language="JavaScript" src="js/resolu.js"></script>
</head>
<body>
<?php
	$login_cookie = $_COOKIE['login'];
    if(isset($login_cookie)){
		
	require_once('conecta.php');
	$sqll = "SELECT * FROM alarme";
	$result2 = $conn->query($sqll);
	if ($result2->num_rows > 0) {
		// output data of each row
		$array2 = array();
		while($row1 = $result2->fetch_assoc()) {
		$estado = $row1["alarme_estado"];
		$violado = $row1["alarme_violado"];
		}
	}
    ?>	
	
	<table align="center" border="0" class="tablealarme">
		<tr>
			<td colspan="3" width="75%"><a class='texto'>Bem-Vindo,<?php echo $login_cookie; ?></td>
			<td colspan="1"><a class="botaocadper" href="logout.php">SAIR</a></td>
		</tr>
		<tr>
			<td colspan="4"><img src="img\iot.jpg" class="imgcaplamp"></img></td>
		</tr>
		<tr>
			<td colspan="4" align="center"><a class="texta2" >ALARME</a></img></td>
		</tr>
		<tr>
			<td colspan="2" width="50%"><input type="button" value="Ativa" Onclick="Ativa()" class="botaoverde"></input></td>
			<td colspan="2"><input type="button" value="Desativa" Onclick="Desativa()" class="botaoverme"></input></td>
		</tr>
		<tr align="center">
			<td  colspan="4"><a class="textalar">ESTADO DO ALARME:</a><?php if($estado == 1){echo "<a class='textalar'>ATIVADO</a>";}else{echo "<a class='textalar'> DESATIVADO</a>";} ?> </td>
		</tr>
		<tr>
			<td colspan="4" align='center'><?php if($violado == 1){echo "<img  src='/img/sirene.jpg' class='alarme'></img>";}else{echo "<img src='/img/sirene2.jpg' class='alarme'></img>";} ?> </td>
		</tr>
		<tr>
			<td colspan="2"><a class="botaocadper" href="alarme_rel.php">Relatorio</a></td>
			<td colspan="2"><a class="botaocadper" href="inicial.php">Voltar</a></td>
		</tr>
	</table>
	
	<?php			
    }else{
      echo"Bem-Vindo, convidado <br>";
      echo" <font color='red'>Essas informações NÃO PODEM ser acessadas por você</font> ";
      echo"<br><a href='index.html'>Faça Login</a> Para ler o conteúdo";
    }
	?>
</body>

</html>