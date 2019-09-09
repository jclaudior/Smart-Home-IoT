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

int est;
int temp;
int estant;
int tempant;
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
uint16_t rawliga[199] = {4476, 4548, 520, 1676, 544, 592, 516, 1676, 540, 1680, 540, 592, 516, 592, 520, 1676, 544, 588, 516, 596, 516, 1676, 548, 584, 516, 592, 520, 1676, 540, 1680, 540, 592, 516, 1676, 552, 580, 520, 592, 516, 592, 516, 1680, 544, 1672, 540, 1680, 540, 1676, 544, 1676, 548, 1672, 540, 1676, 540, 1680, 540, 588, 520, 592, 516, 592, 520, 608, 500, 612, 496, 592, 516, 1680, 540, 588, 520, 592, 516, 1676, 548, 588, 516, 592, 516, 592, 520, 1676, 548, 584, 516, 1676, 548, 1672, 544, 588, 520, 1676, 548, 1672, 544, 1672, 540, 5372, 4504, 4528, 548, 1684, 536, 584, 520, 1676, 540, 1688, 532, 588, 520, 592, 516, 1676, 548, 588, 516, 592, 516, 1676, 544, 592, 516, 592, 516, 1680, 548, 1668, 540, 592, 520, 1676, 540, 592, 516, 592, 520, 592, 516, 1692, 524, 1680, 548, 1672, 536, 1680, 540, 1680, 544, 1672, 540, 1680, 540, 1676, 540, 592, 516, 592, 520, 612, 496, 592, 516, 592, 516, 592, 520, 1676, 548, 584, 520, 588, 520, 1676, 548, 588, 516, 604, 504, 592, 516, 1680, 540, 588, 520, 1676, 540, 1676, 548, 588, 516, 1676, 544, 1696, 528, 1688, 536};


uint16_t rawdesliga[199]= {4480, 4528, 544, 1672, 544, 592, 516, 1676, 544, 1676, 540, 592, 520, 588, 520, 1676, 540, 592, 520, 588, 520, 1676, 544, 588, 520, 588, 520, 1676, 544, 1676, 540, 592, 516, 1676, 544, 592, 516, 1676, 544, 1676, 540, 1676, 544, 1692, 524, 592, 520, 1672, 544, 1676, 544, 1692, 524, 592, 520, 588, 520, 588, 520, 592, 516, 1676, 544, 588, 520, 592, 516, 1688, 532, 1676, 540, 1676, 544, 592, 516, 592, 520, 588, 520, 588, 520, 592, 516, 592, 520, 588, 520, 588, 520, 1676, 544, 1672, 544, 1676, 544, 1676, 540, 1676, 544, 5372, 4504, 4528, 540, 1676, 544, 588, 520, 1676, 544, 1676, 540, 592, 516, 592, 520, 1672, 544, 592, 516, 592, 520, 1676, 540, 592, 520, 588, 520, 1676, 540, 1676, 544, 588, 520, 1676, 544, 588, 520, 1676, 544, 1672, 544, 1692, 528, 1672, 544, 592, 520, 1672, 544, 1676, 544, 1672, 544, 588, 520, 592, 516, 592, 520, 588, 520, 1676, 544, 588, 520, 592, 516, 1676, 544, 1692, 524, 1676, 544, 588, 520, 592, 516, 612, 500, 588, 520, 592, 516, 592, 516, 592, 520, 588, 520, 1676, 540, 1676, 544, 1676, 540, 1676, 544, 1684, 536};


uint16_t rawtemp17[199]= {4500, 4504, 564, 1656, 564, 560, 548, 1668, 552, 1648, 568, 560, 548, 564, 548, 1656, 560, 564, 544, 564, 548, 1652, 564, 564, 548, 560, 548, 1652, 564, 1656, 564, 560, 548, 1656, 564, 560, 548, 560, 548, 564, 548, 1648, 568, 1652, 568, 1652, 564, 1652, 568, 1648, 568, 1652, 568, 1652, 564, 1672, 548, 560, 548, 560, 548, 564, 548, 560, 548, 560, 548, 564, 544, 564, 548, 560, 548, 560, 548, 1652, 568, 560, 548, 564, 544, 564, 548, 1652, 564, 1652, 568, 1648, 568, 1656, 564, 560, 548, 1652, 568, 1652, 564, 1656, 564, 5348, 4528, 4504, 564, 1656, 564, 560, 548, 1652, 568, 1652, 564, 564, 544, 564, 548, 1652, 564, 564, 548, 560, 548, 1652, 564, 564, 548, 560, 548, 1652, 568, 1652, 564, 560, 548, 1652, 568, 560, 548, 560, 548, 564, 548, 1652, 564, 1652, 568, 1652, 564, 1652, 568, 1652, 564, 1656, 564, 1652, 564, 1656, 564, 560, 548, 564, 548, 560, 548, 560, 548, 564, 544, 564, 548, 560, 548, 560, 548, 564, 544, 1652, 568, 560, 548, 564, 544, 564, 548, 1648, 572, 1648, 568, 1652, 564, 1672, 548, 560, 548, 1652, 568, 1652, 564, 1652, 568};


uint16_t rawtemp18[199]= {4504, 4500, 572, 1648, 568, 560, 548, 1668, 552, 1648, 568, 560, 548, 564, 548, 1652, 564, 560, 552, 560, 548, 1652, 568, 556, 552, 560, 548, 1652, 564, 1652, 568, 560, 548, 1652, 568, 560, 548, 560, 548, 564, 548, 1648, 568, 1652, 568, 1668, 548, 1652, 564, 1656, 564, 1652, 564, 1656, 564, 1656, 560, 564, 548, 560, 548, 564, 544, 564, 544, 564, 548, 564, 544, 564, 544, 564, 544, 1656, 564, 1656, 564, 560, 548, 564, 544, 564, 544, 1656, 572, 1656, 556, 1656, 584, 540, 572, 536, 552, 1664, 556, 1648, 560, 1656, 564, 5352, 4528, 4504, 576, 1644, 580, 544, 560, 1640, 588, 1632, 580, 544, 548, 564, 544, 1656, 576, 548, 548, 564, 544, 1668, 556, 560, 556, 552, 556, 1648, 568, 1648, 564, 560, 548, 1656, 564, 560, 548, 560, 552, 560, 548, 1652, 568, 1648, 588, 1632, 584, 1636, 588, 1644, 548, 1672, 572, 1628, 588, 1632, 588, 536, 572, 540, 572, 536, 572, 536, 576, 536, 556, 552, 568, 540, 548, 564, 544, 1656, 564, 1656, 548, 576, 536, 572, 572, 540, 544, 1656, 564, 1652, 568, 1652, 564, 564, 548, 560, 548, 1668, 548, 1652, 568, 1652, 564}; 


uint16_t rawtemp19[199]= {4500, 4504, 564, 1652, 568, 560, 548, 1652, 568, 1652, 564, 564, 548, 560, 548, 1652, 568, 560, 548, 560, 548, 1652, 568, 560, 548, 560, 548, 1652, 568, 1652, 564, 564, 548, 1652, 564, 560, 548, 564, 548, 560, 548, 1652, 568, 1668, 548, 1652, 568, 1652, 564, 1652, 568, 1652, 564, 1652, 568, 1652, 568, 560, 548, 560, 548, 564, 544, 564, 548, 560, 548, 560, 548, 560, 548, 1652, 568, 1652, 568, 1652, 564, 564, 544, 564, 548, 560, 548, 1652, 568, 1652, 564, 560, 548, 564, 548, 560, 548, 1652, 568, 1656, 560, 1668, 552, 5348, 4528, 4500, 568, 1652, 568, 560, 548, 1652, 568, 1652, 564, 564, 548, 560, 548, 1652, 568, 560, 548, 560, 548, 1652, 568, 560, 548, 560, 548, 1652, 568, 1652, 564, 564, 548, 1652, 564, 564, 544, 564, 548, 560, 548, 1652, 568, 1648, 568, 1652, 568, 1652, 564, 1652, 568, 1652, 564, 1656, 564, 1652, 568, 560, 548, 560, 548, 560, 548, 564, 548, 560, 548, 560, 548, 564, 548, 1648, 568, 1652, 568, 1652, 564, 560, 548, 564, 548, 560, 548, 1652, 568, 1652, 564, 560, 548, 564, 548, 560, 548, 1652, 568, 1664, 552, 1652, 568};


uint16_t rawtemp20[199]= {4480, 4528, 544, 1692, 524, 592, 516, 1676, 544, 1676, 544, 588, 520, 608, 500, 1676, 544, 588, 520, 592, 516, 1676, 544, 588, 520, 592, 516, 1676, 544, 1676, 544, 588, 520, 1676, 544, 588, 520, 588, 520, 592, 516, 1680, 540, 1676, 540, 1676, 544, 1676, 544, 1672, 544, 1676, 544, 1672, 544, 1680, 540, 588, 520, 592, 520, 588, 520, 592, 516, 592, 516, 592, 520, 588, 520, 1676, 544, 588, 520, 1672, 544, 592, 520, 588, 520, 592, 516, 1676, 544, 1676, 544, 596, 512, 1676, 540, 592, 520, 1676, 540, 1676, 544, 1676, 540, 5376, 4504, 4544, 524, 1676, 544, 588, 520, 1676, 544, 1676, 540, 592, 516, 596, 516, 1692, 524, 592, 520, 588, 520, 1676, 540, 592, 520, 588, 520, 1676, 544, 1672, 544, 608, 500, 1680, 540, 592, 520, 588, 520, 588, 520, 1676, 544, 1672, 544, 1676, 544, 1672, 544, 1676, 544, 1676, 540, 1696, 524, 1676, 544, 588, 520, 592, 516, 592, 516, 592, 520, 588, 520, 588, 520, 592, 520, 1672, 544, 592, 516, 1692, 528, 588, 520, 596, 516, 588, 520, 1676, 544, 1672, 544, 588, 520, 1676, 544, 588, 520, 1676, 544, 1676, 540, 1676, 544};


uint16_t rawtemp21[199]= {4460, 4544, 528, 1692, 532, 604, 496, 1696, 532, 1668, 540, 612, 500, 612, 496, 1692, 528, 612, 496, 612, 496, 1676, 544, 612, 496, 612, 496, 1680, 548, 1684, 532, 608, 496, 1676, 548, 608, 496, 612, 496, 612, 496, 1696, 528, 1688, 536, 1684, 524, 1696, 524, 1692, 536, 1684, 532, 1684, 528, 1688, 536, 604, 496, 612, 500, 612, 496, 612, 496, 612, 500, 612, 496, 1692, 532, 1680, 532, 612, 500, 1676, 548, 604, 496, 612, 500, 612, 496, 1684, 544, 604, 496, 612, 496, 1696, 532, 604, 496, 1696, 524, 1676, 548, 1668, 548, 5380, 4492, 4528, 556, 1680, 536, 600, 500, 1676, 540, 1696, 532, 604, 496, 612, 500, 1688, 536, 604, 496, 612, 500, 1692, 528, 608, 500, 612, 496, 1684, 544, 1684, 532, 604, 500, 1692, 536, 600, 496, 612, 500, 612, 496, 1696, 528, 1688, 532, 1672, 552, 1676, 536, 1688, 524, 1692, 536, 1676, 532, 1692, 532, 608, 496, 612, 500, 608, 500, 612, 496, 612, 496, 612, 500, 1692, 524, 1692, 528, 612, 496, 1692, 536, 604, 496, 612, 496, 612, 500, 1692, 524, 612, 500, 608, 500, 1692, 528, 608, 500, 1692, 524, 1696, 524, 1676, 548};


uint16_t rawtemp22[199]= {4464, 4544, 524, 1692, 528, 612, 496, 1692, 528, 1692, 536, 600, 500, 612, 496, 1692, 532, 604, 500, 612, 496, 1692, 532, 608, 496, 612, 496, 1692, 528, 1692, 532, 604, 500, 1676, 544, 608, 500, 612, 496, 612, 496, 1688, 532, 1692, 532, 1688, 524, 1692, 528, 1676, 540, 1696, 524, 1692, 528, 1684, 540, 604, 500, 608, 500, 612, 496, 612, 496, 612, 500, 612, 496, 1692, 532, 1684, 528, 1676, 544, 1692, 532, 600, 504, 612, 496, 612, 496, 1696, 524, 612, 496, 608, 504, 608, 500, 612, 496, 1692, 536, 1684, 528, 1672, 552, 5384, 4484, 4548, 532, 1684, 528, 612, 496, 1692, 532, 1688, 528, 608, 500, 608, 500, 1692, 528, 608, 500, 608, 500, 1692, 528, 608, 500, 612, 496, 1692, 528, 1672, 552, 604, 500, 1692, 524, 612, 500, 608, 500, 612, 496, 1692, 532, 1688, 524, 1696, 524, 1692, 532, 1668, 544, 1696, 524, 1676, 540, 1696, 536, 600, 496, 612, 500, 612, 496, 612, 496, 612, 500, 612, 496, 1676, 544, 1676, 544, 1688, 532, 1684, 536, 604, 500, 612, 496, 612, 496, 1696, 532, 580, 520, 612, 496, 612, 500, 612, 496, 1680, 540, 1692, 524, 1676, 544};


uint16_t rawtemp23[199]= {4480, 4544, 528, 1672, 544, 588, 524, 1672, 544, 1676, 544, 588, 520, 592, 520, 1672, 544, 588, 520, 592, 520, 1672, 544, 588, 524, 588, 520, 1676, 544, 1672, 544, 588, 524, 1672, 544, 588, 520, 592, 520, 588, 520, 1676, 544, 1680, 536, 1676, 544, 1672, 548, 1672, 544, 1688, 532, 1672, 544, 1676, 544, 592, 516, 588, 524, 588, 520, 588, 520, 588, 524, 588, 520, 1672, 548, 584, 524, 1672, 544, 1676, 544, 588, 520, 592, 520, 588, 520, 1676, 544, 584, 524, 1672, 548, 584, 524, 588, 520, 1692, 528, 1672, 544, 1676, 544, 5368, 4508, 4528, 544, 1672, 548, 584, 524, 1680, 540, 1672, 544, 588, 520, 588, 524, 1672, 544, 588, 524, 588, 520, 1672, 548, 588, 520, 588, 520, 1676, 544, 1672, 544, 588, 524, 1672, 544, 588, 524, 588, 520, 588, 520, 1676, 544, 1676, 544, 1672, 544, 1676, 544, 1672, 544, 1676, 544, 1672, 548, 1672, 544, 588, 524, 588, 520, 588, 520, 588, 524, 588, 520, 588, 520, 1676, 544, 588, 520, 1672, 548, 1672, 544, 588, 524, 584, 524, 588, 520, 1672, 548, 588, 520, 1672, 548, 588, 520, 588, 520, 1676, 544, 1672, 548, 1672, 544};


uint16_t rawtemp24[199]= {4504, 4500, 572, 1648, 572, 556, 552, 1648, 568, 1652, 568, 560, 548, 560, 548, 1652, 568, 560, 548, 560, 552, 1648, 568, 560, 552, 556, 552, 1648, 568, 1652, 568, 560, 548, 1648, 572, 560, 548, 560, 552, 560, 548, 1648, 572, 1656, 560, 1648, 572, 1648, 568, 1652, 568, 1648, 572, 1648, 568, 1648, 572, 560, 548, 560, 548, 560, 552, 560, 548, 560, 548, 564, 548, 1648, 568, 560, 552, 560, 548, 1652, 564, 564, 548, 560, 548, 560, 548, 1652, 568, 560, 548, 1652, 568, 1648, 572, 560, 548, 1648, 572, 1648, 568, 1648, 572, 5344, 4532, 4504, 568, 1648, 568, 560, 552, 1664, 552, 1652, 568, 560, 548, 560, 552, 1648, 568, 560, 552, 560, 548, 1648, 572, 556, 552, 560, 548, 1652, 568, 1648, 568, 560, 552, 1648, 568, 560, 552, 560, 548, 560, 548, 1660, 560, 1648, 568, 1652, 568, 1652, 568, 1648, 568, 1648, 572, 1648, 568, 1652, 568, 560, 548, 560, 552, 560, 548, 560, 548, 560, 552, 560, 548, 1648, 572, 560, 548, 560, 548, 1652, 568, 560, 548, 560, 548, 564, 548, 1648, 568, 560, 552, 1648, 568, 1652, 568, 560, 548, 1648, 572, 1648, 572, 1648, 568};


uint16_t rawtemp25[199]= {4460, 4544, 528, 1692, 528, 608, 500, 1692, 528, 1688, 528, 612, 496, 612, 500, 1692, 524, 612, 500, 608, 500, 1692, 528, 608, 500, 612, 496, 1692, 528, 1688, 532, 608, 500, 1692, 524, 612, 500, 612, 496, 612, 496, 1692, 532, 1688, 528, 1692, 524, 1692, 528, 1692, 528, 1688, 528, 1692, 528, 1688, 536, 604, 500, 608, 500, 612, 496, 612, 500, 608, 500, 1692, 528, 1688, 528, 612, 496, 612, 500, 1692, 524, 612, 500, 612, 496, 612, 496, 612, 500, 608, 500, 1692, 532, 1688, 524, 612, 500, 1688, 528, 1692, 528, 1692, 524, 5392, 4488, 4544, 528, 1688, 528, 612, 496, 1684, 536, 1692, 528, 608, 500, 612, 496, 1688, 532, 612, 496, 612, 500, 1688, 528, 612, 496, 612, 500, 1692, 528, 1688, 528, 612, 496, 1692, 528, 612, 496, 612, 500, 608, 500, 1692, 528, 1692, 524, 1692, 536, 1684, 528, 1672, 544, 1692, 528, 1692, 524, 1692, 528, 612, 496, 612, 500, 608, 500, 612, 496, 612, 500, 1688, 528, 1692, 528, 612, 496, 612, 496, 1692, 528, 612, 496, 612, 500, 612, 496, 612, 496, 612, 500, 1688, 528, 1692, 528, 612, 496, 1692, 528, 1692, 524, 1692, 528};


uint16_t rawtemp26[199]= {4480, 4544, 524, 1676, 544, 592, 516, 1676, 544, 1676, 544, 588, 520, 588, 520, 1676, 544, 588, 520, 588, 524, 1672, 544, 588, 520, 592, 520, 1676, 540, 1692, 528, 588, 520, 1676, 544, 588, 520, 592, 520, 588, 520, 1672, 548, 1672, 544, 1676, 544, 1676, 540, 1680, 540, 1676, 544, 1676, 540, 1676, 544, 588, 520, 592, 520, 588, 520, 592, 516, 592, 520, 1684, 532, 1676, 544, 588, 520, 1676, 544, 1692, 524, 592, 520, 588, 520, 588, 520, 592, 520, 588, 520, 1676, 544, 588, 520, 588, 520, 1676, 548, 1672, 540, 1676, 544, 5372, 4504, 4528, 548, 1672, 552, 580, 520, 1676, 552, 1664, 556, 580, 524, 584, 528, 1668, 560, 572, 528, 584, 528, 1668, 556, 572, 532, 580, 532, 1660, 564, 1656, 560, 572, 536, 1660, 560, 572, 536, 572, 540, 572, 532, 1660, 568, 1652, 560, 1660, 560, 1660, 556, 1660, 564, 1660, 556, 1656, 560, 1660, 564, 568, 536, 576, 532, 576, 536, 572, 540, 572, 540, 1652, 568, 1652, 568, 564, 540, 1656, 568, 1652, 564, 568, 540, 568, 544, 564, 544, 568, 544, 564, 544, 1652, 568, 564, 544, 564, 548, 1668, 548, 1652, 568, 1648, 568};


uint16_t rawtemp27[199]= {4480, 4524, 548, 1672, 544, 588, 520, 1676, 544, 1692, 528, 588, 520, 588, 520, 1676, 544, 588, 520, 588, 524, 1672, 552, 580, 524, 588, 520, 1672, 552, 1668, 552, 584, 520, 1672, 552, 580, 524, 584, 528, 584, 528, 1664, 560, 1660, 560, 1660, 556, 1660, 564, 1656, 560, 1656, 564, 1660, 560, 1656, 564, 568, 536, 576, 532, 576, 536, 572, 536, 572, 540, 1668, 560, 560, 540, 572, 536, 1660, 568, 1668, 552, 560, 540, 572, 540, 568, 540, 568, 544, 1652, 568, 1648, 572, 564, 540, 568, 544, 1652, 568, 1648, 572, 1648, 572, 5344, 4532, 4500, 572, 1648, 568, 564, 544, 1652, 568, 1648, 572, 560, 548, 564, 544, 1652, 568, 564, 544, 564, 544, 1652, 572, 560, 544, 564, 544, 1652, 572, 1648, 572, 560, 540, 1676, 548, 564, 540, 568, 544, 568, 540, 1652, 572, 1656, 564, 1644, 572, 1660, 560, 1648, 568, 1648, 572, 1652, 568, 1648, 568, 564, 540, 568, 540, 572, 540, 568, 540, 568, 540, 1656, 572, 560, 540, 568, 544, 1652, 572, 1648, 572, 560, 540, 572, 540, 568, 540, 568, 544, 1652, 568, 1648, 572, 564, 540, 568, 544, 1652, 568, 1648, 572, 1648, 572};


uint16_t rawtemp28[199]= {4464, 4528, 560, 1656, 560, 572, 520, 1676, 560, 1656, 560, 576, 520, 588, 520, 1676, 556, 576, 520, 588, 520, 1676, 556, 576, 520, 592, 520, 1672, 556, 1664, 556, 576, 520, 1676, 556, 580, 516, 592, 520, 588, 520, 1672, 556, 1664, 556, 1664, 556, 1660, 560, 1660, 560, 1660, 560, 1656, 564, 1656, 564, 568, 520, 592, 520, 588, 520, 588, 520, 592, 520, 1672, 560, 572, 524, 588, 520, 588, 520, 1676, 560, 572, 520, 588, 520, 592, 520, 588, 520, 1688, 548, 1660, 564, 1652, 568, 564, 520, 1676, 568, 1652, 568, 1648, 568, 5348, 4508, 4524, 572, 1648, 568, 564, 536, 1660, 568, 1652, 568, 564, 536, 572, 536, 1680, 548, 564, 540, 568, 540, 1656, 568, 564, 544, 568, 540, 1652, 572, 1652, 564, 564, 548, 1648, 572, 560, 548, 564, 544, 564, 544, 1652, 568, 1648, 572, 1648, 568, 1668, 552, 1648, 572, 1648, 568, 1652, 568, 1648, 568, 564, 548, 564, 544, 564, 544, 564, 548, 564, 544, 1648, 572, 564, 544, 564, 544, 564, 548, 1648, 568, 564, 548, 564, 544, 564, 544, 564, 548, 1648, 568, 1648, 572, 1648, 572, 560, 548, 1660, 560, 1648, 568, 1652, 568};


uint16_t rawtemp29[199]= {4476, 4528, 544, 1676, 544, 588, 520, 1676, 544, 1684, 536, 584, 524, 592, 516, 1676, 544, 588, 520, 592, 516, 1676, 544, 588, 520, 592, 520, 1672, 544, 1676, 544, 588, 520, 1676, 544, 588, 520, 588, 524, 588, 520, 1676, 540, 1676, 544, 1676, 544, 1672, 544, 1676, 544, 1676, 544, 1676, 540, 1676, 544, 588, 520, 592, 520, 588, 520, 592, 516, 592, 520, 1676, 540, 592, 520, 1676, 540, 592, 516, 1676, 544, 592, 516, 592, 520, 588, 520, 592, 516, 1696, 524, 592, 520, 1672, 544, 592, 516, 1676, 544, 1676, 544, 1676, 540, 5376, 4504, 4528, 544, 1672, 544, 592, 520, 1676, 540, 1676, 544, 588, 520, 588, 520, 1676, 544, 588, 520, 592, 520, 1672, 544, 592, 520, 588, 520, 1676, 544, 1672, 544, 592, 520, 1672, 544, 592, 516, 592, 520, 592, 516, 1676, 544, 1676, 540, 1676, 544, 1676, 544, 1676, 540, 1676, 544, 1676, 544, 1672, 544, 592, 520, 588, 520, 592, 516, 592, 520, 588, 520, 1676, 544, 588, 520, 1676, 544, 588, 520, 1676, 540, 592, 520, 588, 520, 588, 524, 588, 520, 1672, 544, 592, 520, 1672, 544, 592, 520, 1672, 544, 1676, 544, 1696, 524};


uint16_t rawtemp30[199]= {4480, 4528, 540, 1676, 544, 592, 516, 1676, 544, 1672, 548, 588, 520, 592, 516, 1676, 544, 592, 516, 592, 516, 1676, 544, 592, 520, 588, 520, 1676, 540, 1676, 544, 592, 516, 1680, 540, 592, 516, 604, 508, 588, 520, 1676, 544, 1672, 544, 1676, 544, 1676, 544, 1672, 544, 1676, 544, 1672, 548, 1676, 540, 596, 516, 588, 520, 588, 520, 592, 516, 592, 520, 1676, 540, 592, 520, 1676, 540, 1676, 544, 1676, 544, 588, 520, 592, 516, 592, 520, 588, 520, 1676, 544, 588, 520, 592, 516, 592, 520, 1672, 544, 1676, 544, 1688, 532, 5372, 4504, 4528, 544, 1676, 540, 592, 520, 1676, 540, 1680, 540, 592, 516, 592, 520, 1672, 544, 592, 520, 588, 520, 1676, 544, 588, 520, 592, 516, 1676, 544, 1676, 544, 588, 520, 1676, 544, 588, 520, 588, 520, 592, 520, 1676, 540, 1676, 544, 1684, 532, 1676, 544, 1672, 548, 1676, 540, 1696, 524, 1676, 544, 588, 520, 592, 516, 592, 520, 588, 520, 588, 520, 1696, 524, 592, 516, 1676, 544, 1676, 544, 1676, 540, 592, 516, 592, 520, 592, 516, 600, 508, 1676, 544, 592, 516, 592, 520, 592, 516, 1676, 544, 1672, 544, 1676, 544};


void setup() {
 
  //Serial.begin(9600); // Vamos usar para debug
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);

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

    Serial.println("Ligando");  
    irsend.sendRaw(rawliga, 199, 38);  // Send a raw data capture at 38kHz.
    est = 1;
    estant = est;

    delay(2000);

    Serial.println("Temperatura: 17 ºC");  
    irsend.sendRaw(rawtemp17, 199, 38);  // Send a raw data capture at 38kHz.
    temp = 17;
    tempant = temp;

     if ( !getPage((int)est,(int)temp) ) {
      Serial.println("GET request failed");
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (est != estant || temp != tempant){
    if ( !getPage((int)est,(int)temp) ) {
      Serial.println("GET request failed");
    }
    estant = est;
    tempant = temp;
  }
  //Espera o recebimento de um camando enviado via GET pelo servidor
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // Leitura do comando recebido
  Serial.print("Mensagem do cliente: ");
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  if (request.indexOf("/LED=1") != -1) {
    Serial.println("Ligando");  
    irsend.sendRaw(rawliga, 199, 38);  // Send a raw data capture at 38kHz.
    est = 1;
  }
  if (request.indexOf("/LED=2") != -1) {
    Serial.println("Desligado");  
    irsend.sendRaw(rawdesliga, 199, 38);  // Send a raw data capture at 38kHz.
    est = 0;
  }
  if (request.indexOf("/LED=3") != -1) {
    Serial.println("Temperatura: 17 ºC");  
    irsend.sendRaw(rawtemp17, 199, 38);  // Send a raw data capture at 38kHz.
    temp = 17;
  }
  if (request.indexOf("4") != -1) {
    Serial.println("Temperatura: 18 ºC");  
    irsend.sendRaw(rawtemp18, 199, 38);  // Send a raw data capture at 38kHz.
    temp = 18;
  }
  if (request.indexOf("5") != -1) {
    Serial.println("Temperatura: 19 ºC");  
    irsend.sendRaw(rawtemp19, 199, 38);  // Send a raw data capture at 38kHz.
    temp = 19;
  }
  if (request.indexOf("6") != -1) {
    Serial.println("Temperatura: 20 ºC");  
    irsend.sendRaw(rawtemp20, 199, 38);  // Send a raw data capture at 38kHz.
    temp = 20;
  }
  if (request.indexOf("7") != -1) {
    Serial.println("Temperatura: 21 ºC");  
    irsend.sendRaw(rawtemp21, 199, 38);  // Send a raw data capture at 38kHz.
    temp = 21;
  }
  if (request.indexOf("8") != -1) {
    Serial.println("Temperatura: 22 ºC");  
    irsend.sendRaw(rawtemp22, 199, 38);  // Send a raw data capture at 38kHz.
    temp = 22;
  }
   if (request.indexOf("9") != -1) {
    Serial.println("Temperatura: 23 ºC");  
    irsend.sendRaw(rawtemp23, 199, 38);  // Send a raw data capture at 38kHz.
    temp = 23;
  }
  
  if (request.indexOf("/LED=0") != -1) {
    Serial.println("Temperatura: 24 ºC");  
    irsend.sendRaw(rawtemp24, 199, 38);  // Send a raw data capture at 38kHz.
    temp = 24;
  }
  

}

bool getPage(int est, int temp) {
  if ( !client.connect(server1, http_port) ) {
    Serial.println("Falha na conexao com o site ");
    return false;
  }
  
  String param = "?est=" + String(est) + "&temp=" + String(temp); //Parâmetros com as leituras
  client.println("GET /insert_ar.php" + param);
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
