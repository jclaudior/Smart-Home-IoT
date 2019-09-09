
	function On() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/on=1");
    xmlhttp.send();
    }
	
	function Chmais() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/chmais");
    xmlhttp.send();
    }
	
	function Chmenos() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/chmenos");
    xmlhttp.send();
    }
	
	function Vlmais() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/vlmais");
    xmlhttp.send();
    }
	
	function Vlmenos() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/vlmenos");
    xmlhttp.send();
    }
	
	function Stop() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/solto");
    xmlhttp.send();
    }
	
