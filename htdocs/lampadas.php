<!DOCTYPE html>
<html lang="pt-br">
  <head>
    <title>Lampadas</title>
    <meta charset="utf-8">
    <!--meta name="viewport" content="width=device-width, initial-scale=1"-->
	<script language="JavaScript" src="js/resolu.js"></script>
    <script src="js/script_get.js"></script>
	<?php 
	//require_once('conecta.php');
	require_once('est_lamp.php');
	?>
  </head>
	<body >
				
				<?php
				if ($estado1==0){
					$estilo1="img\lampada_apagada.jpg";
					$funcao1="On1();";
					}
				else{
				$estilo1="img\lampada_acesa.jpg";
				$funcao1="Off1();";
				}
				if ($estado2==0){
					$estilo2="img\lampada_apagada.jpg";
					$funcao2="On2();";				}
				else{
				$estilo2="img\lampada_acesa.jpg";
				$funcao2="Off2();";
				}
				if ($estado3==0){
					$estilo3="img\lampada_apagada.jpg";
					$funcao3="On3();";				}
				else{
				$estilo3="img\lampada_acesa.jpg";
				$funcao3="Off3();";
				}
				if ($estado4==0){
					$estilo4="img\lampada_apagada.jpg";
					$funcao4="On4();";				}
				else{
				$estilo4="img\lampada_acesa.jpg";
				$funcao4="Off4();";
				}
				if ($estado5==0){
					$estilo5="img\lampada_apagada.jpg";
					$funcao5="On5();";				}
				else{
				$estilo5="img\lampada_acesa.jpg";
				$funcao5="Off5();";
				}
				//echo '<input class="button" type="button" id="'.$estilo.'" name="nome" value="'.$valor.'"/>'
				?>
	
	<?php
	$login_cookie = $_COOKIE['login'];
    if(isset($login_cookie)){?>	
	<table align="center" border="0" class="tablelamp">
		<tr>
			<td colspan="3"><a class='texto'>Bem-Vindo,<?php echo $login_cookie; ?></td>
			<td colspan="1"><a class="botaocadper" href="logout.php">SAIR</a></td>
		</tr>
		<tr>
			<td colspan="4"><img src="img\iot.jpg" class="imgcaplamp"></img></td>
		</tr>
		<tr>
			<td colspan="4" align="center"><a class="texta2" >ILUMINAÇÃO</a></img></td>
		</tr>
		<tr align="center">
			<td width="25%" rowspan="3"></td>
			<td width="25%"><a class="textolamp" >DESCRIÇÃO</a></td>
			<td width="25%"><a class="textolamp">ESTADO</a></td>
			<td width="25%" rowspan="3"></td>
		</tr>
		<tr align="center">
			<td width="25%"><a class="textolamp"><?php echo  $descri1; ?></a></td>
			<td width="25%"><?php echo '<a onclick="'.$funcao1.'" href="#"><img src="'.$estilo1.'" class="lamp-img" ></a>' ?></td>
		</tr>
		<tr align="center">
			<td width="25%"><a class="textolamp"><?php echo  $descri2; ?></a></td>
			<td width="25%"><?php echo '<a onclick="'.$funcao2.'" href="#"><img src="'.$estilo2.'" class="lamp-img" ></a>' ?></td>
						
		</tr>
		<!--tr>
			<td><a class="textt"><?php echo  $descri3; ?></a></td>
			<td><?php echo '<a onclick="'.$funcao3.'" href="#"><img src="'.$estilo3.'" class="lamp-img" ></a>' ?></td>
		</tr>
		<tr>
			<td><a class="textt"><?php echo  $descri4; ?></a></td>
			<td><?php echo '<a onclick="'.$funcao4.'" href="#"><img src="'.$estilo4.'" class="lamp-img" ></a>' ?></td>
		</tr>
			<tr>
			<td><a class="textt"><?php echo  $descri5; ?></a></td>
			<td><?php echo '<a onclick="'.$funcao5.'" href="#"><img src="'.$estilo5.'" class="lamp-img" ></a>' ?></td>
		</tr-->
		<tr>
			<td colspan="2" width="50%"><a class="botaocadper" href="lamprel.php">Relatorio</a></td>
			<td colspan="2" width="50%"><a class="botaocadper" href="inicial.php">Voltar</a></td>
		</tr>
	</table>
		<?php
		echo "<meta HTTP-EQUIV='refresh' CONTENT='1;URL=lampadas.php'>";
		?>
	<?php			
    }else{
      echo"Bem-Vindo, convidado <br>";
      echo" <font color='red'>Essas informações NÃO PODEM ser acessadas por você</font> ";
      echo"<br><a href='index.html'>Faça Login</a> Para ler o conteúdo";
    }
	?>
	</body>
</html>