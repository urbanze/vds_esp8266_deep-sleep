#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define BOTtoken "1659677:AberDacEJadpENQS_mUTIvLfGQ5f6dQe"//Define o token do BOT.

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

String ldr;

void setup()
{
   WiFi.mode(WIFI_STA);//Define o ESP como Station.
   WiFi.begin("SUA REDE", "SUA SENHA");//Conecta na rede.

   while (WiFi.status() != WL_CONNECTED)//Espera a conexão se estabelecer.
   {
      delay(1);
   }

   ldr += analogRead(A0);//Le o LDR.

   bot.sendSimpleMessage("SEU ID", ldr, "");//Envia o valor do LDR para o chat.

   ESP.deepSleep(1 * 60000000);//Dorme por 1 Minuto (Deep-Sleep em Micro segundos).
}

void loop()
{

}
