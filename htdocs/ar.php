<html>

<head>
<script src="js/ar_get.js"></script>
<script language="JavaScript" src="js/resolu.js"></script>
<?php 
require_once('temp_amb.php');

?>
	
</head>

<body>
<?php
$login_cookie = $_COOKIE['login'];
if(isset($login_cookie)){?>	
<div class="container">
<table border="0" align="center"  height="20%" class="tablear2">
	<tr >
			<td colspan="4" width="80%"><a class='texto'>Bem-Vindo,<?php echo $login_cookie; ?></td>
			<td colspan="1" width="20%"><a class="botaocadper" href="logout.php">SAIR</a></td>
	</tr>
</table>
<table border="0" align="center" width="80%" height="20%" class="tablear">
    <tr>
		<td colspan="5" align="center"><img src="img/iot.jpg" class="imgcap"></img></td>
	</tr>
	<tr>
		<td colspan="5" align="center" height="20%"><a class="texta2">Ar-Condicionado<a></td>
	</tr>
    <tr>
   
		<td colspan="3" width="70%" height="30%"><?php echo '<a onclick="Liga_ar();" href="#" class="botaoverd">LIGA</a>' ?> </td>
		<td colspan="2" width="30%" height="30%"><?php echo '<a onclick="Desliga_ar();" href="#" class="botaoverm">DESLIGA</a>' ?> </td>
		
     
	</tr>
	<tr >
		<td colspan="5"><legend class="texta2 legend1"></legend></td>
	</tr>
	<tr >
		<td colspan="5"><legend class="texta2 legend1">Temperatura:</legend></td>
	</tr>
	<tr>
		<td width="5%" align="center"><a class="texta1">-</a></td>
		<td colspan="2" width="45%">
        <?php echo "<input id='temp' type='range' min='17' max='24' value='".$tempe."' onchange='mostrarIdade(this.value)' class='inputarasta'/>"?>
		
		</td>
		<td width="5%" align="center"><a class="texta1">+</a></td>
		<td width="50%">
		<span id="exibeIdade" class="texta2"><?php echo $tempe; ?></span><a class="texta2">ºC</a>
		</td>
	</tr>
	<tr >
		<td colspan="5"><legend class="texta1 legend1">Ambiente:</legend></td>
	</tr>
	<tr>
		<td colspan="3"><a class="texta1"><?php echo "Temperatura: " . $temp. "ºC"  ; ?></a></td>
		<td colspan="2"><a class="texta1"><?php echo " Humidade: " .$humid."%"; ?></a></td>
	</tr>
		<tr>
			<td colspan="3" width="50%"><a class="botaocadper" href="temperatura_rel.php">Relatorio</a></td>
			<td colspan="2" width="50%"><a class="botaocadper" href="inicial.php">Voltar</a></td>
		</tr>
		
	<?php
	echo "<meta HTTP-EQUIV='refresh' CONTENT='3;URL=ar.php'>";
	?>
	
	
	
	
	






</table>






</div>
<?php			
    }else{
      echo"Bem-Vindo, convidado <br>";
      echo" <font color='red'>Essas informações NÃO PODEM ser acessadas por você</font> ";
      echo"<br><a href='index.html'>Faça Login</a> Para ler o conteúdo";
    }
	?>
</body>


</html>