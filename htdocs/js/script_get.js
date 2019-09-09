
	function On1() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=1");
    xmlhttp.send();
    }
	
	function Off1() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=1");
    xmlhttp.send();
    }
	
	function On2() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.3/LED=1");
    xmlhttp.send();
    }
	
	function Off2() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.55/LED=0");
    xmlhttp.send();
    }
	
	function On3() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.4/LED=1");
    xmlhttp.send();
    }
	
	function Off3() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.4/LED=0");
    xmlhttp.send();
    }
	
	
	function chamarPhpAjax() {
   $.ajax({
      url:'insert_lampada.php',
      complete: function (response) {
         alert(response.responseText);
      },
      error: function () {
          alert('Erro');
      }
  });  

  return false;
}
	
	function On4() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.5/LED=1");
    xmlhttp.send();
    }
	
	function Off4() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.5/LED=0");
    xmlhttp.send();
    }
	
	function On5() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.6/LED=1");
    xmlhttp.send();
    }
	
	function Off5() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.6/LED=0");
    xmlhttp.send();
    }
    