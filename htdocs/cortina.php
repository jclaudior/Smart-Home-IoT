<html>
<head>
<script language="JavaScript" src="js/resolu.js"></script>
<script src="js/cortina_get.js"></script>
<script src="js/hover.js"></script>
</head>


<body>
<?php
	$login_cookie = $_COOKIE['login'];
    if(isset($login_cookie)){?>	
	<table align="center" border="0" class="tablecort">
		<tr>
			<td colspan="3"><a class='texto'>Bem-Vindo,<?php echo $login_cookie; ?></td>
			<td colspan="1"><a class="botaocadper" href="logout.php">SAIR</a></td>
		</tr>
		<tr>
			<td colspan="4"><img src="img\iot.jpg" class="imgcaplamp"></img></td>
		</tr>
		<tr>
			<td colspan="3" align="center"><a class="texta2" >CORTINA</a></img></td>
		</tr>
		<tr>
			<td colspan="3" rowspan="2" width="80%" height="300px" valign="top" align="center"><div class="cort1"> </div><div id="cort" class="cort"> </div></td>
			<td colspan="1" align="center"><a id="up" onmousedown="AntHorario()" onmouseup="Stop()" ontouchstart="AntHorario()" ontouchend="Stop()"><img src="img\up.png" class="btupdown"></img></a></td>
		</tr>
		<tr>
			
			<td colspan="1" align="center"><a id="down" onmousedown="Horario()"  onmouseup="Stop()" ontouchstart="Horario()" ontouchend="Stop()"><img src="img\down.png" class="btupdown"></img></a></td>
		</tr>
		<tr>
			<td colspan="4" width="50%"><a class="botaocadper" href="inicial.php">Voltar</a></td>
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