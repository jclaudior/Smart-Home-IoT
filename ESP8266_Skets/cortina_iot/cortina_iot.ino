#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Stepper.h>
#define fimt 4
#define fimb 0
// Preencha com os dados de autenticação do seu WiFi 
const char ssid[] = "acesso";
const char psw[] = "12345678";
const char http_site[] = "http://192.168.137.1";
const int http_port = 80;
char valor='c';
WiFiClient client;
//IP do ESP (para voce acessar pelo browser - voce TEM que mudar este IP tambem)
IPAddress ip(192, 168, 137, 55);

//IP do roteador da sua rede wifi
IPAddress gateway(192, 168, 137, 1);

//Mascara de rede da sua rede wifi
IPAddress subnet(255, 255, 255, 0);

IPAddress server1(192,168,137,1); //Endereço IP do servidor - http_site 

WiFiServer server(80);

const int stepsPerRevolution =295; 
 
//Inicializa a biblioteca utilizando as portas de 8 a 11 para 
//ligacao ao motor 
Stepper myStepper(stepsPerRevolution, D8,D6,D7,D5); 
 
void setup() 
{ 
  pinMode(fimt, INPUT_PULLUP);
  pinMode(fimb, INPUT_PULLUP);
  Serial.begin(9600);
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

 //Determina a velocidade inicial do motor 
 myStepper.setSpeed(100);
} 
 
void loop() 
{
  
 if (valor =='a' && digitalRead(fimt) != LOW ){
      myStepper.step(stepsPerRevolution);
      Serial.println("Horario ");
      delay(10);
 }

 if (valor =='b' && digitalRead(fimb) != LOW){
      myStepper.step(-stepsPerRevolution);
      Serial.println("AntHorario");
      delay(10);
 }

 if (valor =='c'){
   Serial.println("Parado");
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
  if (request.indexOf("/horario=1") != -1) {
    valor= 'a';

    }
  
  if (request.indexOf("/anthorario=1") != -1) {
    valor= 'b';

    }

  if (request.indexOf("/stop=1") != -1) {
    valor= 'c';
     
    }
 


  
}






