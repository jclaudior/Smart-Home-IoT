#include <ESP8266WiFi.h>
#include <WiFiClient.h>
// Preencha com os dados de autenticação do seu WiFi 
const char ssid[] = "acesso";
const char psw[] = "12345678";
const char http_site[] = "http://192.168.137.1";
const int http_port = 80;

#define rele D7
#define sensor D6
int estadorele = 0;
int estado = 0;
int estadoant = 1; 
unsigned long Inicio;
byte contando = false;

// Variáveis globais
WiFiClient client;
//IP do ESP (para voce acessar pelo browser - voce TEM que mudar este IP tambem)
IPAddress ip(192, 168, 137, 55);

//IP do roteador da sua rede wifi
IPAddress gateway(192, 168, 137, 1);

//Mascara de rede da sua rede wifi
IPAddress subnet(255, 255, 255, 0);

IPAddress server1(192,168,137,1); //Endereço IP do servidor - http_site 

WiFiServer server(80);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT_PULLUP);
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
  if (digitalRead(sensor) == 0){
    estado = 0;
    Serial.println("estado fechado");
  }
  if (digitalRead(sensor) == 1){
    estado = 1;
    Serial.println("estado aberto");
  }
  if (estado != estadoant){
    if ( !getPage((int)estado) ) {
        Serial.println("GET request failed");
       }
       estadoant = estado;
  }
  if(estadorele  == 1 && digitalRead(sensor) == 0){
    trava();
    Serial.println("rele1 sensor0");
  }
  if (estadorele == 1 && digitalRead(sensor) == 1 ){
    trava2();
    Serial.println("rele1 sensor1");
  }
  
  
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();


  if (request.indexOf("/abrir") != -1) {
   digitalWrite(rele,1);
   Serial.println("Porta Aberta");
   contando = true;
   Inicio = millis();
   estadorele = 1;
  
  }

  

 delay(1000);
}

void trava(){
  Serial.println("esta na trava");
  if(((millis() - Inicio) > 10000) and contando == true){
      contando = false;
      digitalWrite(rele,0);
      Serial.println("Porta fechada");
      estadorele = 0; 
  }
  
}


void trava2(){
  Serial.println("esta na trava2");
  if(((millis() - Inicio) > 2000) and contando == true){
      contando = false;
      digitalWrite(rele,0);
      Serial.println("Porta fechada");
      estadorele = 0;
  }
  
}


// Executa o HTTP GET request no site remoto
//
bool getPage(int estado) {
  if ( !client.connect(server1, http_port) ) {
    Serial.println("Falha na conexao com o site ");
    return false;
  }
  
  String param = "?estado=" + String(estado); //Parâmetros com as leituras
  client.println("GET /insert_acesso.php" + param);
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



