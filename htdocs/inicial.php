<html>

<head>
	<script language="JavaScript" src="js/resolu.js"></script>
	<?php 
		header("Expires: Mon, 26 Jul 1997 05:00:00 GMT");
		header("Last-Modified:" .gmdate("D, d M Y H:i:s"). "GMT");
		header("Cache-Control: no-store,no-cache,must-revalidate");
		header("Cache-Control: post-check=0,pre-check=0",false);
		header("Pragma: no-cache");
		
		
	
	
	?>
</head>


<body>

<?php
  require_once('conecta.php');
  $login_cookie = $_COOKIE['login'];
  $sqll = "SELECT per_per,per_cad,per_exc,per_acesso,per_ar,per_lampadas,per_tv,per_alarme,per_cortinas FROM permicoes WHERE login = '$login_cookie'";
  $result2 = $conn->query($sqll);
  if ($result2->num_rows > 0) {
		// output data of each row
		$array2 = array();
		while($row1 = $result2->fetch_assoc()) {
			$cadastro=$row1["per_cad"];
			$exclusao=$row1["per_exc"];
			$permicao=$row1["per_per"];
			$acesso=$row1["per_acesso"];
			$ar=$row1["per_ar"];
			$lampadas=$row1["per_lampadas"];
			$tv=$row1["per_tv"];
			$alarme=$row1["per_alarme"];
			$cortinas=$row1["per_cortinas"];
		
		}
  }
  ?>
  <?php
  if($cadastro== 1){
	  $cadastro = "cadastro.php";
  }else{
	  $cadastro = "#";
  }
  if($exclusao== 1){
	  $exclusao = "exclusao.php";
  }else{
	  $exclusao = "#";
  }
  if($permicao== 1){
	  $permicao = "permicao.php";
  }else{
	  $permicao = "#";
  }
  if($acesso== 1){
	  $acesso = "acesso.php";
  }else{
	  $acesso = "#";
  }
  if($ar== 1){
	  $ar = "ar.php";
  }else{
	  $ar = "#";
  }
  if($lampadas== 1){
	  $lampadas = "lampadas.php";
  }else{
	  $lampadas = "#";
  }
  if($tv== 1){
	  $tv = "tv.php";
  }else{
	  $tv = "#";
  }
    if($alarme== 1){
	  $alarme = "alarme.php";
  }else{
	  $alarme = "#";
  }
    if($cortinas== 1){
	  $cortinas = "cortina.php";
  }else{
	  $cortinas = "#";
  }
  
  ?>
  <?php
    if(isset($login_cookie)){
	?>

		<table align="center" border="0" class="tableinicial">
			<tr>
				<td colspan="3"><a class='texto'>Bem-Vindo,<?php echo $login_cookie; ?></a></td>
				<td align="center"><a class="botaocadper" href="logout.php">SAIR</a></td>
			</tr>
			<tr>
				<td colspan="6"><img src="img/iot.jpg" class="imgcap"></img></td>
			</tr>
			<tr>
				<td width="10%" colspan="1"><a class="botaocadper" href="<?php echo $cadastro; ?>">CADASTRO</a></td>
				<td width="10%" colspan="2"><a class="botaocadper" href="<?php echo $permicao; ?>">PERMISSÕES</a></td>
				<td width="10%" colspan="1"><a class="botaocadper" href="<?php echo $exclusao; ?>">EXCLUSÃO</a></td>
				
			</tr >
			    <td align="center" width="25%"><a href="<?php echo $acesso; ?>"><img src="img/puerta.png" class="imgobj1"></a></img></td>
				<td align="center" width="25%"><a class="texto" href="<?php echo $acesso; ?>">ACESSO</a></td>
				<td align="center" width="25%"><a href="<?php echo $ar; ?>"><img src="img/ar.png" class="imgobj"></a></img></td>
				<td align="center" width="25%"><a class="texto" href="<?php echo $ar; ?>">AR-CONDI.</a></td>
			<tr>
			</tr>
			<tr>
				<td align="center" width="25%"><a href="<?php echo $lampadas; ?>"><img src="img/lampada_acesa.jpg" class="imgobj"></a></img></td>
				<td align="center" width="25%"><a class="texto" href="<?php echo $lampadas; ?>">LAMPADAS</a></td>
				<td align="center" width="25%"><a href="<?php echo $tv; ?>"><img src="img/tv.png" class="imgobj2"></a></td>
				<td align="center" width="25%"><a class="texto" href="<?php echo $tv; ?>">TV</a></td>
			</tr>
			<tr>
				<td align="center" width="25%"><a href="<?php echo $alarme; ?>"><img src="img/sirene.jpg" class="imgobj2"></a></td>
				<td align="center" width="25%"><a class="texto" href="<?php echo $alarme; ?>">ALARME</a></td>
				<td align="center" width="25%"><a href="<?php echo $cortinas; ?>"><img src="img/cortina.png" class="imgobj2"></td>
				<td align="center" width="25%"><a class="texto" href="<?php echo $cortinas; ?>">CORTINAS</a></td>
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