#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// Preencha com os dados de autenticação do seu WiFi 
const char ssid[] = "acesso";
const char psw[] = "12345678";
const char http_site[] = "http://192.168.137.1";
const int http_port = 80;
#define drinkI 14
#define drinkII 12
#define drinkIII 13
#define drinkIV 15

// Variáveis globais
WiFiClient client;
//IP do ESP (para voce acessar pelo browser - voce TEM que mudar este IP tambem)
IPAddress ip(192, 168, 137, 70);

//IP do roteador da sua rede wifi
IPAddress gateway(192, 168, 137, 1);

//Mascara de rede da sua rede wifi
IPAddress subnet(255, 255, 255, 0);

IPAddress server1(192,168,137,1); //Endereço IP do servidor - http_site 

WiFiServer server(80);

void setup() {
 Serial.begin(9600); /* begin serial for debug */
 Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
 delay(1000);
  pinMode(drinkI, OUTPUT); 
  pinMode(drinkII, OUTPUT); 
  pinMode(drinkIII, OUTPUT); 
  pinMode(drinkIV, OUTPUT); 
 
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
   digitalWrite(drinkI , LOW);
    digitalWrite(drinkII , LOW);
     digitalWrite(drinkIII , LOW);
      digitalWrite(drinkIV , LOW);
  
}

void loop() {

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
 
  boolean estadorele = digitalRead(13);
  if (request.indexOf("/drink=1") != -1) {
    Serial.println("Drink I Selecionado");  
    digitalWrite(drinkI , !drinkI);
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write("a");  /* sends hello string */
    Wire.endTransmission();    /* stop transmitting */
  }
  if (request.indexOf("/drink=2") != -1) {
    Serial.println("Drink II Selecionado");  
    digitalWrite(drinkII , !drinkII);
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write("b");  /* sends hello string */
    Wire.endTransmission();    /* stop transmitting */
  }
  if (request.indexOf("/drink=3") != -1) {
    Serial.println("Drink III Selecionado");  
    digitalWrite(drinkIII , !drinkIII);
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write("c");  /* sends hello string */
    Wire.endTransmission();    /* stop transmitting */
  }
  if (request.indexOf("/drink=4") != -1) {
    Serial.println("Drink IV Selecionado");  
    digitalWrite(drinkIV , !drinkIV);
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write("d");  /* sends hello string */
    Wire.endTransmission();    /* stop transmitting */
  }



  



 
}
