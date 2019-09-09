<html>

<head>
	<script language="JavaScript" src="js/resolu.js"></script>
	<script>
	     window.history.forward(1);
	</script>
<?php
	require_once('conecta.php');
	$login_cookie = $_COOKIE['login'];
?>

</head>
<body>
	<table align="center" class="tabelaperm2" border="0">
		<tr>
			<td colspan="" width="80%"><a class='texto'>Bem-Vindo,<?php echo $login_cookie; ?></td>
			<td colspan="" width="20%"><a class="botaocadper" href="logout.php">SAIR</a></td>
			
		</tr>
		<tr>
			<td colspan="2" align="center"><img src="img/iot.jpg" class="imgcap"></img>
		</tr>
		<tr>
			<td>
			<?php
				$sqll="SELECT login FROM permicoes";
				echo"<form action='permicao.php' method='POST' name='usuario'>";
				echo"<select name='user' class='selectper'>";
				echo "<option value='1' >Selecione o Usuario</option>";
				$result = $conn->query($sqll);
				
				if ($result->num_rows > 0) {
					while($row = $result->fetch_assoc()) {
						$nome = $row['login'];
						echo "<option value='".$nome."'>".$nome."</option>";
					}
				}
			?>

				</select>
			</td>
			<td height="10px">
				<input type="submit" class="botaocadper"/>
			</td>
			</form>
		</tr>
	</table>
<?php
	if(isset($_POST['user']) && $_POST['user'] != 1){
		$user = $_POST['user'];
		$sql = "SELECT per_per,per_cad,per_exc,per_acesso,per_ar,per_lampadas,per_tv,per_alarme,per_cortinas FROM permicoes WHERE login = '$user'";
		$result2 = $conn->query($sql);
		
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
		if($cadastro == 0){
			$cad1= 0;
			$caddes1="Desabilitado";
			$cad2= 1;
			$caddes2="Habilitado";
		}else{
			$cad1= 1;
			$caddes1="Habilitado";
			$cad2= 0;
			$caddes2="Desabilitado";
		}
		if($exclusao == 0){
			$exc1= 0;
			$excdes1="Desabilitado";
			$exc2= 1;
			$excdes2="Habilitado";
		}else{
			$exc1= 1;
			$excdes1="Habilitado";
			$exc2= 0;
			$excdes2="Desabilitado";
		}
		if($permicao == 0){
			$per1= 0;
			$perdes1="Desabilitado";
			$per2= 1;
			$perdes2="Habilitado";
		}else{
			$per1= 1;
			$perdes1="Habilitado";
			$per2= 0;
			$perdes2="Desabilitado";
		}
		if($acesso == 0){
			$ace1= 0;
			$acedes1="Desabilitado";
			$ace2= 1;
			$acedes2="Habilitado";
		}else{
			$ace1= 1;
			$acedes1="Habilitado";
			$ace2= 0;
			$acedes2="Desabilitado";
		}
		if($ar == 0){
			$ar1= 0;
			$ardes1="Desabilitado";
			$ar2= 1;
			$ardes2="Habilitado";
		}else{
			$ar1= 1;
			$ardes1="Habilitado";
			$ar2= 0;
			$ardes2="Desabilitado";
		}
		if($lampadas == 0){
			$lam1= 0;
			$lamdes1="Desabilitado";
			$lam2= 1;
			$lamdes2="Habilitado";
		}else{
			$lam1= 1;
			$lamdes1="Habilitado";
			$lam2= 0;
			$lamdes2="Desabilitado";
		}
		if($tv == 0){
			$tv1= 0;
			$tvdes1="Desabilitado";
			$tv2= 1;
			$tvdes2="Habilitado";
		}else{
			$tv1= 1;
			$tvdes1="Habilitado";
			$tv2= 0;
			$tvdes2="Desabilitado";
		}
		if($alarme == 0){
			$ala1= 0;
			$alades1="Desabilitado";
			$ala2= 1;
			$alades2="Habilitado";
		}else{
			$ala1= 1;
			$alades1="Habilitado";
			$ala2= 0;
			$alades2="Desabilitado";
		}
		if($cortinas == 0){
			$cor1= 0;
			$cordes1="Desabilitado";
			$cor2= 1;
			$cordes2="Habilitado";
		}else{
			$cor1= 1;
			$cordes1="Habilitado";
			$cor2= 0;
			$cordes2="Desabilitado";
		}

		if(isset($_POST['user'])){
	
?>
	<table align="center" class="tabelaperm" border="0">
		<tr>
			<td>Usuario:</td>
			<td><?php echo $user; ?></td>
		</tr>
		<tr> 
			<form action="permicao.php" method="POST">
			<INPUT TYPE="hidden" NAME="user" VALUE="<?php echo $user; ?>">
			<td>Cadastro</td>
			<td>
				<select name="cadastro" class="selectper">
					<option value="<?php echo $cad1; ?>"><?php echo $caddes1; ?></option>
					<option value="<?php echo $cad2; ?>"><?php echo $caddes2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td>Exclusão</td>
			<td>
				<select name="exclusao" class="selectper">
					<option value="<?php echo $exc1; ?>"><?php echo $excdes1; ?></option>
					<option value="<?php echo $exc2; ?>"><?php echo $excdes2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td>Permisão</td>
			<td>
				<select name="permicao" class="selectper">
					<option value="<?php echo $per1; ?>"><?php echo $perdes1; ?></option>
					<option value="<?php echo $per2; ?>"><?php echo $perdes2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td>Acesso</td>
			<td>
				<select name="acesso" class="selectper">
					<option value="<?php echo $ace1; ?>"><?php echo $acedes1; ?></option>
					<option value="<?php echo $ace2; ?>"><?php echo $acedes2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td>Ar</td>
			<td>
				<select name="ar" class="selectper">
					<option value="<?php echo $ar1; ?>"><?php echo $ardes1; ?></option>
					<option value="<?php echo $ar2; ?>"><?php echo $ardes2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td>Lampadas</td>
			<td>
				<select name="lampadas" class="selectper">
					<option value="<?php echo $lam1; ?>"><?php echo $lamdes1; ?></option>
					<option value="<?php echo $lam2; ?>"><?php echo $lamdes2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td>TV</td>
			<td>
				<select name="tv" class="selectper">
					<option value="<?php echo $tv1; ?>"><?php echo $tvdes1; ?></option>
					<option value="<?php echo $tv2; ?>"><?php echo $tvdes2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td>Alarme</td>
			<td>
				<select name="alarme" class="selectper">
					<option value="<?php echo $ala1; ?>"><?php echo $alades1; ?></option>
					<option value="<?php echo $ala2; ?>"><?php echo $alades2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td>Cortinas</td>
			<td>
				<select name="cortinas" class="selectper">
					<option value="<?php echo $cor1; ?>"><?php echo $cordes1; ?></option>
					<option value="<?php echo $cor2; ?>"><?php echo $cordes2;?></option>
				</select>
			</td>
		</tr>
		<tr>
			<td colspan="3">
				<input type="submit" class="botaocadper"/>
			</td>
		</tr>
		</form>
	</table>


<?php
	}
	}
	if (isset($_POST['cadastro']) && isset($_POST['exclusao']) && isset($_POST['permicao']) && isset($_POST['acesso']) && isset($_POST['ar']) && isset($_POST['lampadas']) && isset($_POST['tv']) && isset($_POST['alarme']) && isset($_POST['cortinas'])){
		$cadastro = $_POST['cadastro']; $exclusao = $_POST['exclusao']; $permicao = $_POST['permicao']; $acesso = $_POST['acesso']; $ar=$_POST['ar']; $lampadas=$_POST['lampadas'];$tv = $_POST['tv'];$alarme = $_POST['alarme']; $cortinas = $_POST['cortinas'];
		$sql="UPDATE permicoes SET per_cad= $cadastro, per_exc= $exclusao, per_per = $permicao, per_acesso = $acesso, per_ar = $ar, per_lampadas = $lampadas, per_tv = $tv, per_alarme = $alarme, per_cortinas = $cortinas WHERE login = '$user'";
		if (!$conn->query($sql)) {
			echo "ERRO NA GRAVAÇÂO NO BANCO DE DADOS";
		}else{
			echo"<meta HTTP-EQUIV='refresh' CONTENT='0;URL=permicao.php'>";
		}
	}
?>
    <table align="center" class="tabelaperm2">
		<tr>
			    <td colspan="3">
				<a class="botaocadper" href="inicial.php">Voltar</a>
			</td>
		</tr>
	</table>


</body>

</html>