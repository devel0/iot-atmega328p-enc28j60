//==============================================================================
//
//-------------------- PLEASE REVIEW FOLLOW VARIABLES ------------------
//

// choose one of follow two interface
//#define USE_ENC28J60
#define USE_W5500

#define MACADDRESS 0x30, 0xca, 0x8d, 0x9f, 0x5b, 0x89
#define MYIPADDR 10, 10, 4, 110
#define MYIPMASK 255, 255, 255, 0
#define MYDNS 10, 10, 0, 6
#define MYGW 10, 10, 0, 1
#define LISTENPORT 1000

// EDIT DebugMacros to set SERIAL_SPEED and enable/disable DPRINT_SERIAL

//
//==============================================================================

#ifdef USE_ENC28J60
#include <UIPEthernet.h>
// edit UIPEthernet/utility/uipethernet-conf.h to customize
// - define UIP_CONF_UDP=0 to reduce flash size
#endif

#ifdef USE_W5500
#include <Ethernet.h>
#endif

#include <DPrint.h>
#include <Util.h>
using namespace SearchAThing::Arduino;

EthernetServer server = EthernetServer(LISTENPORT);

void setup()
{
  uint8_t mac[6] = {MACADDRESS};
  uint8_t myIP[4] = {MYIPADDR};
  uint8_t myMASK[4] = {MYIPMASK};
  uint8_t myDNS[4] = {MYDNS};
  uint8_t myGW[4] = {MYGW};

  // dhcp
  //Ethernet.begin(mac);

  // static
  Ethernet.begin(mac, myIP, myDNS, myGW, myMASK);

  DPrintCls pr;

  DPrint(F("my ip : "));  
  Ethernet.localIP().printTo(pr);
  DPrintln();

  server.begin();
}

void loop()
{
  size_t size;

  if (EthernetClient client = server.available())
  {
    DPrint(F("received message : "));

    while ((size = client.available()) > 0)
    {
      auto msg = (uint8_t *)malloc(size + 1);
      memset(msg, 0, size + 1);
      size = client.read(msg, size);

      DPrintln((char *)msg);

      free(msg);
    }

    client.stop();
  }
}
