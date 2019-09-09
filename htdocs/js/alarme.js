function Ativa() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.50/ativado");
    xmlhttp.send();
    }
function Desativa() {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "http://192.168.1.50/desativado");
    xmlhttp.send();
    }