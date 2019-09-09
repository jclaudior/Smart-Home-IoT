#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>

// Preencha com os dados de autenticaÃ§Ã£o do seu WiFi 
//variavel que armazena NOME da Rede WIFI(SSID)
const char ssid[] = "acesso";
//variavel que armazena Senha da Rede WIFI
const char psw[] = "12345678";
//IP do servidor do Site para comunicaÃ§Ã£o de recebimento de informaÃ§Ã£o
const char http_site[] = "http://192.168.137.1";
//Porta para comunicaÃ§Ã£o com o servidor do Site 80 padrÃ£o
const int http_port = 80;
//variavel para manipulaÃ§Ã£o dos dados do sensor

int botao = 0;

// VariÃ¡veis globais
WiFiClient client;
//IP do ESP (para voce acessar pelo browser - voce TEM que mudar este IP tambem)
IPAddress ip(192, 168, 137, 55);

//IP do roteador da sua rede wifi
IPAddress gateway(192, 168, 137, 1);

//Mascara de rede da sua rede wifi
IPAddress subnet(255, 255, 255, 0);

//IP do servidor do Site para comunicaÃ§Ã£o envio de informaÃ§Ã£o
IPAddress server1(192,168,137,1); 
//Porta do servidor do ESP 80 padrÃ£o
WiFiServer server(80);

#define IR_LED 4  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(IR_LED);  // Set the GPIO to be used to sending the message.

// Example of data captured by IRrecvDumpV2.ino

uint16_t rawliga[75] = {8932, 4536, 540, 616, 516, 620, 512, 1728, 524, 616, 516, 636, 496, 620, 512, 612, 520, 616, 516, 1732, 520, 1708, 540, 616, 516, 1728, 524, 1712, 536, 1712, 540, 1712, 536, 1712, 540, 616, 516, 616, 516, 616, 520, 1708, 540, 612, 520, 636, 496, 616, 516, 632, 500, 1712, 540, 1712, 536, 1716, 536, 616, 516, 1712, 540, 1712, 536, 1712, 540, 1712, 536, 39620, 8952, 2304, 540, 30388, 8952, 2304, 524};


uint16_t rawcanalmais[79]= {8972, 4516, 536, 612, 520, 612, 520, 1728, 524, 612, 520, 612, 520, 612, 520, 612, 520, 612, 520, 1712, 536, 1712, 544, 608, 524, 1708, 544, 1708, 540, 1708, 544, 1704, 548, 1704, 548, 604, 524, 608, 528, 604, 524, 608, 528, 604, 528, 604, 528, 604, 528, 604, 528, 1704, 552, 1696, 556, 1696, 552, 1700, 552, 1712, 536, 1696, 556, 1696, 556, 1696, 552, 39712, 8972, 2276, 556, 30484, 8968, 2280, 548, 30492, 8968, 2280, 564};


uint16_t rawcanalmenos[83]= {8932, 4556, 528, 632, 480, 628, 512, 1736, 532, 600, 568, 608, 480, 608, 556, 600, 500, 628, 504, 1752, 488, 1740, 532, 624, 516, 1712, 532, 1732, 528, 1728, 504, 1728, 520, 1728, 536, 1716, 528, 604, 528, 632, 492, 640, 484, 648, 512, 620, 500, 604, 516, 620, 512, 620, 544, 1708, 520, 1728, 528, 1724, 544, 1704, 512, 1764, 496, 1748, 520, 1712, 540, 39728, 8940, 2312, 524, 30524, 8964, 2288, 552, 30488, 8940, 2312, 536, 30528, 8928, 2304, 536};


uint16_t rawvolumemais[79]= {8996, 4496, 560, 588, 544, 588, 544, 1704, 548, 588, 532, 600, 532, 600, 524, 596, 544, 600, 528, 1708, 560, 1692, 540, 592, 556, 1696, 560, 1688, 560, 1692, 564, 1688, 560, 1700, 536, 600, 548, 1704, 548, 588, 540, 588, 548, 588, 544, 588, 544, 588, 544, 588, 568, 1676, 552, 588, 544, 1704, 548, 1688, 564, 1688, 560, 1708, 544, 1704, 548, 1704, 544, 39624, 8980, 2276, 544, 30408, 8952, 2304, 540, 30412, 8980, 2276, 544}; 


uint16_t rawvoluemenos[79]= {8972, 4512, 556, 596, 536, 596, 532, 1700, 556, 596, 532, 600, 532, 600, 532, 600, 536, 596, 536, 1696, 556, 1696, 556, 576, 552, 1700, 556, 1692, 560, 1692, 556, 1696, 556, 1692, 560, 1692, 556, 1712, 540, 592, 540, 596, 532, 600, 532, 600, 532, 600, 532, 600, 532, 600, 532, 600, 536, 1696, 556, 1696, 556, 1692, 556, 1696, 556, 1696, 556, 1696, 556, 39616, 8968, 2284, 552, 30400, 8972, 2280, 536, 30412, 8972, 2276, 540};



void setup() {
 
  //Serial.begin(9600); // Vamos usar para debug
  irsend.begin();
  Serial.begin(9600, SERIAL_8N1, SERIAL_TX_ONLY);

  Serial.println();
  Serial.println();
  Serial.print("Conectando com: ");
  Serial.println(ssid);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, psw);

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
  //Espera o recebimento de um camando enviado via GET pelo servidor
  if ( botao == 1){
    irsend.sendRaw(rawcanalmais, 79, 38);
    Serial.println("Canal +");
    delay(500);
  }
  else if (botao == 2){
     irsend.sendRaw(rawcanalmenos, 83, 38);
     Serial.println("Canal -");
     delay(500); 
  }
  else if(botao == 3){
    irsend.sendRaw(rawvolumemais, 79, 38);
    Serial.println("Volume +");
    delay(500); 
  }
  else if(botao == 4){
    irsend.sendRaw(rawvoluemenos, 79, 38);
    Serial.println("Volume -");
    delay(500);
  }
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // Leitura do comando recebido
  Serial.print("Mensagem do cliente: ");
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  if (req.indexOf("on=1") != -1)
  {
    irsend.sendRaw(rawliga, 75, 38); 
    Serial.println("Ligando/Desligando");
  }
  else if (req.indexOf("chmais") != -1)
  {
    botao  = 1; 
  }
  else if (req.indexOf("chmenos") != -1)
  {
    botao  = 2;
  }
  else if (req.indexOf("vlmais") != -1)
  {
    botao  = 3;
  }
  else if (req.indexOf("vlmenos") != -1)
  {
    botao  = 4; 
  }
  else if (req.indexOf("solto") != -1)
  {
    botao = 0;
    Serial.println("solto"); 
  }
  
  
}


