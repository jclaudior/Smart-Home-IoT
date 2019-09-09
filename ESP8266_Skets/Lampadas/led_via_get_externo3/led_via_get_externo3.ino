#include <ESP8266WiFi.h>
#include <WiFiClient.h>
// Preencha com os dados de autenticação do seu WiFi 
const char ssid[] = "acesso";
const char psw[] = "12345678";
const char http_site[] = "http://192.168.137.1";
const int http_port = 80;
int estado = 0;
int estadoantes;
#define sensor 12

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
  delay(1000);
  pinMode(13, OUTPUT); //Led interno da placa. 
  pinMode(sensor,INPUT);
  estadoantes = digitalRead(sensor);
  Serial.begin(9600); // Vamos usar para debug
 
  // Conectando à rede WiFi
  Serial.println();
  Serial.println();
  Serial.print("Conectando com: ");
  Serial.println(ssid);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, psw);
  //while (WiFi.status() != WL_CONNECTED) {
  //  delay(500);
  //  Serial.print(".");
 // }
  delay(10000);
  Serial.println("");
  Serial.println("WiFi conectado com sucesso");
  // Startando o servidor
  server.begin();
  Serial.print("Servidor startado em ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
 
void loop() {
  // Aguardando requisições do cliente
  int leitura= digitalRead(sensor);
  
  if (leitura == HIGH){
   Serial.println("Ligado");    
  }
  if (leitura == LOW){
   Serial.println("Desligado");    
  }
  if(leitura == LOW){
    estado=0;
  }
  else{
    estado=1;
  }
  
  if (estado == estadoantes){
    if ( !getPage((int)estado) ) {
      Serial.println("GET request failed");
    }
  estadoantes = !estado;
  }
  
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // Leitura da requisição
  Serial.print("Mensagem do cliente: ");
  //while(!client.available()) {
    //delay(1);
  //}
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Muda situação do LED, caso o parâmetro seja detectado 
  //if (request.indexOf("ONOFF") != -1) {
    //digitalWrite(13, !digitalRead(13));
  //}
 
  boolean estadorele = digitalRead(13);
  if (request.indexOf("1") != -1 || request.indexOf("0") != -1) {
    digitalWrite(13,!estadorele);
    Serial.print("rele porta energizada");
  }

  
  //if (request.indexOf("0") != -1 && leitura == HIGH) {
   // digitalWrite(13,!leitura);
    //Serial.print("rele porta desligada");
  //}
  

  if (estadorele = 1){
   Serial.print("liiiiiiiiiiiiiigado"); 
  }
  if (estadorele = 0){
   Serial.print("Apagaaaaaaaaaaaado"); 
  }
  
  //Resposta padrão
  //client.println("HTTP/1.1 200 OK");
  //client.println("Content-Type: text/html");
  //client.println(""); 
  //client.println("<!DOCTYPE HTML>");
  //client.println("<html>");
  //client.println("<head><title>ESP8266 Web Server Exemplo</title></head>");  
  //client.println("<body>ESP8266 Web Server Exemplo</body>");
  //client.println("</html>");
  
}
  
// Executa o HTTP GET request no site remoto
//
bool getPage(int estado) {
  if ( !client.connect(server1, http_port) ) {
    Serial.println("Falha na conexao com o site ");
    return false;
  }
  
  String param = "?estado=" + String(estado); //Parâmetros com as leituras
  client.println("GET /insert_lampada.php" + param);
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
//estadoantes = !estado;
//}

  
}
  


