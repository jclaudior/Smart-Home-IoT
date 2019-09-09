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

uint16_t rawliga[75] = {9076, 4504, 572, 608, 552, 608, 552, 608, 552, 608, 552, 608, 552, 608, 552, 608, 552, 612, 548, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 608, 552, 1664, 572, 608, 552, 608, 552, 608, 552, 1664, 572, 608, 552, 608, 552, 1664, 572, 608, 552, 1664, 572, 1664, 572, 1664, 572, 608, 552, 1668, 568, 39352, 9084, 2244, 572, 30200, 9084, 2244, 568};

uint16_t rawstop[75]= {9096, 4500, 572, 608, 552, 612, 552, 608, 552, 608, 552, 612, 552, 608, 552, 608, 552, 612, 552, 1684, 552, 1664, 572, 1668, 572, 1664, 572, 1664, 572, 1664, 576, 1660, 576, 1664, 572, 608, 552, 1668, 572, 1664, 572, 608, 552, 612, 548, 612, 552, 1668, 568, 608, 552, 1668, 572, 608, 552, 608, 552, 1664, 576, 1664, 572, 1664, 572, 608, 552, 1668, 572, 39376, 9088, 2252, 564, 30260, 9088, 2244, 572}; 

uint16_t rawmute[75]= {9056, 4552, 524, 636, 524, 640, 524, 636, 524, 636, 524, 636, 524, 636, 524, 640, 524, 636, 524, 1692, 544, 1692, 544, 1692, 544, 1692, 544, 1692, 544, 1692, 544, 1692, 548, 1688, 548, 1688, 548, 1688, 548, 1692, 544, 636, 524, 640, 524, 636, 524, 1688, 552, 632, 528, 636, 524, 636, 524, 636, 528, 1688, 548, 1688, 548, 1688, 548, 636, 528, 1688, 556, 39376, 9072, 2256, 572, 30216, 9084, 2244, 576};

uint16_t rawmode[75]= {9072, 4524, 548, 636, 524, 636, 528, 636, 524, 636, 524, 636, 528, 636, 524, 636, 524, 640, 520, 1692, 548, 1688, 548, 1688, 548, 1688, 548, 1688, 548, 1688, 548, 1688, 548, 1692, 544, 636, 524, 636, 524, 1692, 548, 636, 524, 636, 524, 636, 524, 1692, 544, 636, 528, 1688, 548, 1688, 548, 636, 524, 1692, 544, 1708, 532, 1688, 544, 636, 524, 1692, 548, 39372, 9068, 2268, 548, 30236, 9060, 2268, 544};

uint16_t rawretro[75]= {9056, 4540, 548, 636, 528, 636, 524, 636, 528, 636, 528, 636, 524, 636, 528, 636, 528, 636, 524, 1692, 548, 1688, 548, 1692, 548, 1708, 532, 1688, 548, 1692, 548, 1688, 548, 1692, 548, 636, 528, 636, 524, 636, 528, 636, 524, 640, 524, 636, 528, 1688, 548, 636, 528, 1688, 548, 1692, 548, 1692, 548, 1688, 548, 1692, 548, 1688, 548, 636, 528, 1688, 548, 39400, 9068, 2284, 548, 30272, 9080, 2276, 548};

uint16_t raweq[75]= {9056, 4536, 548, 636, 524, 636, 524, 640, 524, 636, 524, 636, 528, 636, 524, 636, 524, 636, 524, 1692, 548, 1688, 548, 1692, 544, 1692, 544, 1692, 548, 1692, 544, 1688, 548, 1708, 528, 1692, 544, 1692, 544, 640, 524, 636, 524, 636, 524, 636, 524, 1708, 532, 636, 524, 636, 524, 636, 524, 1712, 528, 1688, 548, 1688, 548, 1692, 544, 636, 524, 1692, 544, 39392, 9040, 2284, 548, 30260, 9028, 2292, 548};

uint16_t rawant[75]= {9060, 4520, 576, 608, 552, 608, 552, 608, 552, 608, 552, 608, 552, 608, 552, 612, 548, 608, 552, 1664, 572, 1664, 572, 1668, 572, 1660, 572, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 1660, 576, 608, 552, 608, 552, 608, 552, 608, 552, 608, 552, 608, 552, 608, 552, 608, 552, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 1664, 572, 39360, 9076, 2244, 572, 30228, 9048, 2272, 548};

uint16_t rawdep[75]= {9060, 4540, 548, 636, 524, 636, 524, 636, 528, 636, 524, 636, 528, 636, 524, 636, 524, 640, 524, 1692, 544, 1696, 544, 1688, 548, 1692, 544, 1692, 548, 1688, 548, 1692, 544, 1692, 548, 1688, 548, 636, 524, 1696, 544, 636, 524, 1692, 548, 632, 528, 636, 524, 636, 528, 636, 524, 1692, 544, 636, 528, 1700, 536, 636, 528, 1708, 528, 1688, 548, 1692, 548, 39388, 9056, 2284, 548, 30256, 9060, 2284, 544};

uint16_t rawplay[75]= {9080, 4500, 572, 612, 552, 608, 552, 612, 552, 608, 552, 612, 552, 608, 552, 608, 556, 608, 552, 1664, 576, 1664, 572, 1664, 572, 1664, 572, 1668, 572, 1664, 572, 1668, 568, 1664, 576, 1660, 576, 608, 552, 608, 552, 1664, 572, 612, 552, 608, 552, 608, 552, 608, 552, 612, 552, 1664, 572, 1664, 572, 608, 556, 1660, 576, 1664, 572, 1664, 572, 1664, 572, 39364, 9072, 2244, 572, 30228, 9080, 2244, 572};

uint16_t rawvolumemenos[75]= {9044, 4548, 548, 636, 524, 636, 524, 636, 528, 636, 524, 636, 528, 636, 524, 636, 524, 636, 528, 1688, 548, 1712, 528, 1688, 548, 1692, 544, 1692, 548, 1688, 548, 1688, 548, 1688, 552, 632, 528, 1688, 548, 1692, 548, 636, 524, 1688, 548, 636, 528, 636, 524, 636, 524, 1692, 548, 636, 524, 636, 524, 1692, 548, 636, 524, 1692, 544, 1692, 548, 1692, 544, 39400, 9052, 2292, 544, 30280, 9036, 2292, 548};

uint16_t rawvolumemais[75]= {9040, 4552, 548, 636, 524, 636, 524, 636, 524, 636, 528, 636, 524, 636, 524, 636, 524, 640, 524, 1688, 548, 1688, 548, 1692, 544, 1692, 544, 1692, 548, 1688, 548, 1688, 548, 1688, 548, 1704, 532, 636, 524, 636, 524, 1692, 548, 1688, 548, 632, 528, 636, 524, 636, 524, 636, 524, 1692, 544, 1692, 548, 636, 524, 636, 524, 1688, 548, 1692, 544, 1692, 544, 39400, 9028, 2296, 544, 30280, 9032, 2292, 548};

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
    irsend.sendRaw(rawant, 75, 38);
    Serial.println("Ant <<");
    delay(500);
  }
  else if (botao == 2){
     irsend.sendRaw(rawdep, 75, 38);
     Serial.println("Dep >>");
     delay(500); 
  }
  else if(botao == 3){
    irsend.sendRaw(rawvolumemais, 75, 38);
    Serial.println("Volume +");
    delay(500); 
  }
  else if(botao == 4){
    irsend.sendRaw(rawvolumemenos, 75, 38);
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
  if (req.indexOf("liga") != -1)
  {
    irsend.sendRaw(rawliga, 75, 38); 
    Serial.println("Ligando/Desligando");
  }
  else if (req.indexOf("ant") != -1)
  {
    botao  = 1; 
  }
  else if (req.indexOf("dep") != -1)
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
  else if (req.indexOf("stop") != -1)
  {
    irsend.sendRaw(rawstop, 75, 38); 
    Serial.println("Stop");
  }
  else if (req.indexOf("mute") != -1)
  {
    irsend.sendRaw(rawmute, 75, 38); 
    Serial.println("Mute");
  }
  else if (req.indexOf("mode") != -1)
  {
    irsend.sendRaw(rawmode, 75, 38); 
    Serial.println("Mode");
  }
  else if (req.indexOf("retro") != -1)
  {
    irsend.sendRaw(rawretro, 75, 38); 
    Serial.println("Retro");
  }
  else if (req.indexOf("eq") != -1)
  {
    irsend.sendRaw(raweq, 75, 38); 
    Serial.println("EQ");
  }
  else if (req.indexOf("play") != -1)
  {
    irsend.sendRaw(rawplay, 75, 38); 
    Serial.println("Play");
  }
  
  
}


