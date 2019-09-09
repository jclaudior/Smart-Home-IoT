
/* ESP8266 e Banco de Dados - Requisições HTTP
 * 2016 por José Cintra
 * www.josecintra.com/blog
 */ 

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include "DHT.h"


// WiFi - Coloque aqui suas configurações de WI-FI
const char ssid[] = "AP_CENTRAL";
const char psw[] = "1921685252";

// Site remoto - Coloque aqui os dados do site que vai receber a requisição GET
const char http_site[] = "http://192.168.1.2";
const int http_port = 80;

// Variáveis globais
WiFiClient client;
//IP do ESP (para voce acessar pelo browser - voce TEM que mudar este IP tambem)
IPAddress ip(192, 168, 1, 150);

//IP do roteador da sua rede wifi
IPAddress gateway(192, 168, 1, 254);

//Mascara de rede da sua rede wifi
IPAddress subnet(255, 255, 255, 0);

//Criando o servidor web na porta 80
//WiFiServer server(80);

IPAddress server(192,168,1,2); //Endereço IP do servidor - http_site
//int pinDHT11 = D2;
//SimpleDHT11 dht11;
#define DHTPIN 13 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  delay(30000); //Aguarda 30 segundos 
  Serial.begin(9600);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, psw);
  //while (WiFi.status() != WL_CONNECTED) {
   // delay(100);
  //  Serial.print(".");
  //}
  //while (WiFi.status() != WL_CONNECTED) {
   // delay(500);
 // }
  Serial.print("\nWI-FI conectado com sucesso: ");
  Serial.println(ssid);

}

void loop() {
  Serial.println("Tempo de leitura: 5m");
  delay(300000); //delay entre as leituras
 //Leitura do sensor DHT11
 // byte temp = 0;
 // byte humid = 0;
 float temp = dht.readTemperature();
 float humid = dht.readTemperature(true);
 
   if (isnan(humid) || isnan(temp)) {
   Serial.println("Falha na leitura do Sensor!");
   return;
  }
  
  Serial.println("Gravando dados no BD: ");
  Serial.print((float)temp); Serial.print(" *C, "); 
  Serial.print((float)humid); Serial.println(" %");

  // Envio dos dados do sensor para o servidor via GET
  if ( !getPage((float)temp,(float)humid) ) {
    Serial.println("GET request failed");
  }
}

// Executa o HTTP GET request no site remoto
bool getPage(float temp, float humid) {
  if ( !client.connect(server, http_port) ) {
    Serial.println("Falha na conexao com o site ");
    return false;
  }
  
  String param = "?temp=" + String(temp) + "&humid=" + String(humid); //Parâmetros com as leituras
  client.println("GET /insert_weather.php" + param);
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
