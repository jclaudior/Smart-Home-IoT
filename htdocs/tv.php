<html>

<head>
<script language="JavaScript" src="js/resolu.js"></script>
<script src="js/tv_get.js"></script>
</head>

<body>
<?php
	$login_cookie = $_COOKIE['login'];
    if(isset($login_cookie)){
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
			<td colspan="4" align="center"><a class="texta2" >TV</a></img></td>
		</tr>
		<tr>
			<td colspan="4" align="center"><input type="button" value="Liga/Desliga" Onclick="On()" class="botaoverme" ></input></td>
		</tr>
		<tr>
			<td  colspan="2" align="center" width="50%"><input type="button" value="CH+" onmousedown="Chmais()" onmouseup="Stop()" ontouchstart="Chmais()" ontouchend="Stop()" class="botaogold"></input></td>
			<td colspan="2" align="center" width="50%"><input type="button" value="VL+" onmousedown="Vlmais()" onmouseup="Stop()" ontouchstart="Vlmais()" ontouchend="Stop()" class="botaogold"></input></td>
		</tr>
		<tr>
			<td  colspan="2" align="center" width="50%"><input type="button" value="CH-" onmousedown="Chmenos()" onmouseup="Stop()" ontouchstart="Chmenos()" ontouchend="Stop()" class="botaogold"></input></td>
			<td colspan="2" align="center" width="50%"><input type="button" value="VL-" onmousedown="Vlmenos()" onmouseup="Stop()" ontouchstart="Vlmenos()" ontouchend="Stop()" class="botaogold"></input></td>
		</tr>
		<tr>
			<td colspan="4"><a class="botaocadper" href="inicial.php">Voltar</a></td>
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
