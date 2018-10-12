//#define ARDUINO 18070

#define SERIAL_DEBUG
#define MACADDRESS 0x30, 0xcf, 0x8d, 0x9f, 0x5b, 0x89
#define MYIPADDR 10, 10, 2, 5
#define MYIPMASK 255, 255, 255, 0
#define MYDNS 10, 10, 0, 6
#define MYGW 10, 10, 0, 1
#define LISTENPORT 1000

#include <UIPEthernet.h>
#include <arduino-utils.h>
#include <Printable.h>

EthernetServer server = EthernetServer(LISTENPORT);

#include <Arduino.h>
#include <arduino-utils.h>

void setup()
{
#ifdef SERIAL_DEBUG
  Serial.begin(115200);
#endif

  uint8_t mac[6] = {MACADDRESS};
  uint8_t myIP[4] = {MYIPADDR};
  uint8_t myMASK[4] = {MYIPMASK};
  uint8_t myDNS[4] = {MYDNS};
  uint8_t myGW[4] = {MYGW};

  // dhcp
  Ethernet.begin(mac);

  // static
  //Ethernet.begin(mac, myIP, myDNS, myGW, myMASK);

#ifdef SERIAL_DEBUG
  DEBUG_PRINT("my ip : ");
  Ethernet.localIP().printTo(Serial);
  DEBUG_PRINTLN();
#endif

  server.begin();
}

void loop()
{    
  size_t size;

  if (EthernetClient client = server.available())
  {
    DEBUG_PRINT("received message : ");

    while ((size = client.available()) > 0)
    {
      auto msg = (uint8_t *)malloc(size + 1);
      memset(msg, 0, size + 1);
      size = client.read(msg, size);

      DEBUG_PRINTBUF(msg, size);

      free(msg);
    }

    client.stop();
  }
}
