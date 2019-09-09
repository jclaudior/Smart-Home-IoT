
function Horario() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/horario=1");
    xmlhttp.send();
    }
function AntHorario() {
	
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/anthorario=1");
    xmlhttp.send();
    }
function Stop() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.137.55/stop=1");
    xmlhttp.send();
    }