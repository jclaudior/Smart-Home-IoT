//função GET para o ESP utilizando seu endereço de IP mandando a informação 1 pra ele alterar o estado do relé
	function Liga_ar() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=1");
    xmlhttp.send();
    }
	
	function Desliga_ar() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=2");
    xmlhttp.send();
    }
	
	function temp17() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=3");
    xmlhttp.send();
    }
	
	function temp18() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=4");
    xmlhttp.send();
    }
	
	function temp19() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=5");
    xmlhttp.send();
    }
	
	function temp20() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=6");
    xmlhttp.send();
    }
	function temp21() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=7");
    xmlhttp.send();
    }
	function temp22() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=8");
    xmlhttp.send();
    }
	function temp23() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=9");
    xmlhttp.send();
    }
	function Temp_24() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/LED=0");
    xmlhttp.send();
    }
	
	
	function mostrarIdade(novoValor) {
            document.getElementById("exibeIdade").innerHTML = novoValor;
			w=document.getElementById("temp").value;
			if(w==17){
				var xmlhttp = new XMLHttpRequest();
					xmlhttp.open("GET", "http://192.168.137.55/LED=3");
			        xmlhttp.send();
				
			}
			if(w==18){
				var xmlhttp = new XMLHttpRequest();
				xmlhttp.open("GET", "http://192.168.137.55/LED=4");
				xmlhttp.send();
				
			}
			if(w==19){
				var xmlhttp = new XMLHttpRequest();
					xmlhttp.open("GET", "http://192.168.137.55/LED=5");
			        xmlhttp.send();
				
			}
			if(w==20){
				var xmlhttp = new XMLHttpRequest();
					xmlhttp.open("GET", "http://192.168.137.55/LED=6");
			        xmlhttp.send();
				
			}
			if(w==21){
				var xmlhttp = new XMLHttpRequest();
					xmlhttp.open("GET", "http://192.168.137.55/LED=7");
			        xmlhttp.send();
				
			}
			if(w==22){
				var xmlhttp = new XMLHttpRequest();
					xmlhttp.open("GET", "http://192.168.137.55/LED=8");
			        xmlhttp.send();
				
			}
			if(w==23){
				var xmlhttp = new XMLHttpRequest();
					xmlhttp.open("GET", "http://192.168.137.55/LED=9");
			        xmlhttp.send();
				
			}
			if(w==24){
				
				var xmlhttp = new XMLHttpRequest();
					xmlhttp.open("GET", "http://192.168.137.55/LED=0");
			        xmlhttp.send();
				
			}
        }