<html>

<head>
	<script language="JavaScript" src="js/resolu.js"></script>
</head>


<body>

<?php
  $login_cookie = $_COOKIE['login'];
    if(isset($login_cookie)){?>
<body>
<table align="center" border="0" class="tabelatopcad">
	<tr>
		<td><a class='texto' height="90%">Bem-Vindo,<?php echo $login_cookie; ?></a></td>
		<td align="center"><a class="botaocadper" href="logout.php">SAIR</a></td>
	</tr>
</table>

<table align="center" border="0" class="tabelalogin">
    <tr>
		<td colspan="2"><img src="img\iot.jpg" class="bannerlogin"></img> </td>
	</tr>
	<tr>
		<form method="POST" action="cadas.php">
		<td><label class="labellogin">Login:</label></td>
		<td><input type="text" name="login" id="login" class="inputlogin"></td>
	</tr>
	<tr>
		<td><label class="labellogin">Senha:</label></td>
		<td><input type="password" name="senha" id="senha" class="inputsenha"></td>
	</tr>
	<tr>
		<td align="center" colspan="2"><input type="submit" value="Cadastrar" id="cadastrar" name="cadastrar" class="botaoentrar"></td>
	</tr>
	<tr>
		<td colspan="2"><a class="botaocadper" href="inicial.php">Voltar</a></td>
	</tr>
</table>
</body>
</html>

<?php			
    }else{
      echo"Bem-Vindo, convidado <br>";
      echo" <font color='red'>Essas informações NÃO PODEM ser acessadas por você</font> ";
      echo"<br><a href='index.html'>Faça Login</a> Para ler o conteúdo";
    }
?>