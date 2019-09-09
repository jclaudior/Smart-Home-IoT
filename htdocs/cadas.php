<?php 
 
$login = $_POST['login'];
$senha =($_POST['senha']);
$exis = 1;
require_once('conecta.php');
$sql = "SELECT login FROM usuarios WHERE login = '$login'";
$result = $conn->query($sql);
   $array = array();
   if($login == "" || $login == null || $senha == "" || $senha == null ){
    echo"<script language='javascript' type='text/javascript'>alert('O campo login ou senha devem estar preenchidos!!');window.location.href='cadastro.html';</script>";
  
    }else{
		$senha= md5($senha);
		while($row = $result->fetch_assoc()) {
			$array[] = $row["login"];
			
			if($login == $row["login"] ){
 
				echo"<script language='javascript' type='text/javascript'>alert('Esse login já existe');window.location.href='cadastro.html';</script>";
				$exis = 0;
				die();
			}
		}
    
		if ($exis>0){
			$sqll = "INSERT INTO usuarios (login,senha) VALUES ('$login','$senha') ";
			$sqlll="INSERT INTO permicoes (login,per_per,per_cad,per_acesso,per_ace1,per_ace2,per_ar,per_lampadas,per_lamp1,Per_lamp2,per_tv,per_alarme,per_cortinas) VALUES ('$login',0,0,0,0,0,0,0,0,0,0,0,0)";
			if (!$conn->query($sqll)) {
				//Gravar log de erros
				echo"<script language='javascript' type='text/javascript'>alert('Não foi possível cadastrar esse usuário');window.location.href='cadastro.php'</script>";
			}else{
				echo"<script language='javascript' type='text/javascript'>alert('Usuário cadastrado com sucesso!!!');window.location.href='cadastro.php'</script>";
			}	
			if (!$conn->query($sqlll)) {
			//Gravar log de erros
			die("Erro na gravação dos dados no BD");
			}
         
        
		}
    
	}
   
?>