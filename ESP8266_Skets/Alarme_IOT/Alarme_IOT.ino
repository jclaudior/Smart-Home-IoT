#include <ESP8266WiFi.h>
#include <WiFiClient.h>
// Preencha com os dados de autenticação do seu WiFi 
const char ssid[] = "Joao c";
const char psw[] = "vadesai20";
const char http_site[] = "http://192.168.1.10";
const int http_port = 80;

#define rele D7
#define sensor D8
int estado = 0;
int estadoantes = 1;
int viola = 0;
int violaantes = 0;
// Variáveis globais
WiFiClient client;
//IP do ESP (para voce acessar pelo browser - voce TEM que mudar este IP tambem)
IPAddress ip(192, 168, 1, 50);

//IP do roteador da sua rede wifi
IPAddress gateway(192, 168, 1, 1);

//Mascara de rede da sua rede wifi
IPAddress subnet(255, 255, 255, 0);

IPAddress server1(192,168,1,10); //Endereço IP do servidor - http_site 

WiFiServer server(80);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(rele, OUTPUT);

// Conectando à rede WiFi
  Serial.println();
  Serial.println();
  Serial.print("Conectando com: ");
  Serial.println(ssid);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, psw);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  delay(10000);
  Serial.println("");
  Serial.println("WiFi conectado com sucesso");
 
  // Startando o servidor
  server.begin();
  Serial.print("Servidor startado em ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  delay(5000);

}

void loop() {
if (estado == 1){
  if (digitalRead(sensor) == HIGH){
    Serial.println("Sensor ativo");
    digitalWrite(rele, 1);
    viola = 1;
    if (viola != violaantes){
       if ( !getPage2((int)viola) ) {
        Serial.println("GET request failed");
       }
        violaantes = viola;
       } 
  delay(2000);
  }
}

if (estado != estadoantes){
  if ( !getPage((int)estado) ) {
        Serial.println("GET request failed");
      }
  estadoantes = estado;
}
WiFiClient client = server.available();
  if (!client) {
    return;
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

if (request.indexOf("/ativado") != -1) {
  estado=1;
  Serial.println("Alarme Ativado");
  
}
if (request.indexOf("/desativado") != -1) {
  estado=0;
  viola = 0;
  violaantes = 0;
  digitalWrite(rele,0);
  Serial.println("Alarme Desativado");
    
}


}

// Executa o HTTP GET request no site remoto
//
bool getPage(int estado) {
  if ( !client.connect(server1, http_port) ) {
    Serial.println("Falha na conexao com o site ");
    return false;
  }
  
  String param = "?estado=" + String(estado)+ "&violac=" + String(viola); //Parâmetros com as leituras
  client.println("GET /insert_alarme.php" + param);
  client.println("HTTP/1.1");
  Serial.println("User-Agent: Arduino");
  client.println("Accept: text/html");
  client.println("Host:");
  client.println(http_site);
  client.println("\r\n\r\n");
  client.println("Connection: close\r\n\r\n");
  client.println();
  client.println();

    // Informações de retorno do servidor para debug
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  return true;


  
}

bool getPage2(int viola) {
  if ( !client.connect(server1, http_port) ) {
    Serial.println("Falha na conexao com o site ");
    return false;
  }
  
  String param = "?viola=" + String(viola)+ "&violac=" + String(viola); //Parâmetros com as leituras
  client.println("GET /insert_alarme.php" + param);
  client.println("HTTP/1.1");
  Serial.println("User-Agent: Arduino");
  client.println("Accept: text/html");
  client.println("Host:");
  client.println(http_site);
  client.println("\r\n\r\n");
  client.println("Connection: close\r\n\r\n");
  client.println();
  client.println();

    // Informações de retorno do servidor para debug
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  return true;


  
}
