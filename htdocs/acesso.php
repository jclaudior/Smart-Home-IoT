<html>

<head>
	<script language="JavaScript" src="js/acesso.js"></script>
	<script language="JavaScript" src="js/resolu.js"></script>
</head>

<body>
<?php
	$login_cookie = $_COOKIE['login'];
    if(isset($login_cookie)){
	require_once('conecta.php');
	$sqll = "SELECT acesso_descricao,acesso_estado, acesso_js FROM acesso";
	$result2 = $conn->query($sqll);

?>
	<table align="center" border="0" class="tabletv">
		<tr>
			<td colspan="3" width="75%"><a class='texto'>Bem-Vindo,<?php echo $login_cookie; ?></td>
			<td colspan="1"><a class="botaocadper" href="logout.php">SAIR</a></td>
		</tr>
		<tr>
			<td colspan="4"><img src="img\iot.jpg" class="imgcaplamp"></img></td>
		</tr>
		<tr>
			<td colspan="4" align="center"><a class="texta2" >ACESSO</a></img></td>
		</tr>
		<?php 	
		if ($result2->num_rows > 0) {
			// output data of each row
			$cont = 0;
			while($row1 = $result2->fetch_assoc()) {
				if ( $row1["acesso_estado"] == 0 ){
					echo "<tr><td colspan='2' width='50%' align='right'><a class='texta2'>".$row1["acesso_descricao"]."</a></td><td colspan='2' width='50%' align='left'><a Onclick='".$row1["acesso_js"]."'><img src='img\puerta_fehada.png' class='puerta'></img></a></td></tr>";
				}else{
					echo "<tr><td colspan='2' width='50%' align='right'><a class='texta2'>".$row1["acesso_descricao"]."</a></td><td colspan='2' width='50%' align='left'><a Onclick='".$row1["acesso_js"]."'><img src='img\puerta.png' class='puerta'></img></a></td></tr>";
				}
				$descricao = $row1["acesso_descricao"];
				$estado = $row1["acesso_estado"];
			}
        } 
		?>
		<tr>
			<td colspan="2" width="50%"><a class="botaocadper" href="acessorel.php">Relatorio</a></td>
			<td colspan="2" width="50%"><a class="botaocadper" href="inicial.php">Voltar</a></td>
		</tr>
		
	</table>
<?php

		echo "<meta HTTP-EQUIV='refresh' CONTENT='5;URL=acesso.php'>";
		
}else{
      echo"Bem-Vindo, convidado <br>";
      echo" <font color='red'>Essas informações NÃO PODEM ser acessadas por você</font> ";
      echo"<br><a href='index.html'>Faça Login</a> Para ler o conteúdo";
    }
?>	

</body>

</html>