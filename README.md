# iot-atmega328p-enc28j60

minimal setup to debug atmega328p with enc28j60

## prerequisites

- software
  - install [vscode arduino](https://github.com/devel0/knowledge/blob/master/electronics/vscode-arduino.md)
  - install [UIPEthernet](https://github.com/UIPEthernet/UIPEthernet)
- hardware
  - [atmega bare](https://github.com/devel0/iot-atmega-bare)
  - [enc28j60](https://www.microchip.com/wwwproducts/en/en022889) module

## setup

<img src="doc/setup.jpg" width=640/>

```
Sketch uses 19990 bytes (61%) of program storage space. Maximum is 32768 bytes.
Global variables use 1102 bytes (53%) of dynamic memory, leaving 946 bytes for local variables. Maximum is 2048 bytes.
```

### wirings

- **GND** `GND` common to atmega328p + usbasp + enc28j60 + usb ttl serial
- **enc28j60** `VCC` from atmega bare **3.3V** `CS SI SCK SO` to atmega `SS MOSI SCK MISO`
- **atmega328p** `VCC` from atmega bare 3.3V but can work 5V cause enc28j660 digital pin are 5V tolerant
- **usb ttl serial** `RXD` to atmega `TXD`
- **usbasp** : `GND RST MISO MOSI SCK` to corresponding atmega ( use ICSP bare connector )

### troubleshoot

If experiencing signal lost after some period major causes are:
- out of memory ( check free memory using [FREERAM_PRINT](https://github.com/Locoduino/MemoryUsage) )
- bad cable connections ( this happens to me frequently using breadboard due to instable not tight pin connection ), to solve proceed to solder on an experimental board )

## usage

- tune your network config MACADDRESS and MYIPADDR, MYIPMASK, MYDNS, MYGW if want static initialization

```
telnet 10.10.2.5 1000
hi
```

- check serial `ctrl+shift+p arduino open serial`

```
received message : hi
```
