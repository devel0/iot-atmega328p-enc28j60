# iot-atmega328p-enc28j60

minimal setup to debug atmega328p with enc28j60

## prerequisites

- software
  - install [vscode arduino](https://github.com/devel0/knowledge/blob/master/arduino/vscode-arduino.md)
  - install [UIPEthernet](https://github.com/UIPEthernet/UIPEthernet)
- hardware
  - arduino nano ( for serial debugging through [as serial reader](https://github.com/devel0/iot-arduino-nano-as-serial-reader) )
  - USBASP 2.0 ( as programmer )
  - atmega328p with 3.3V/5V powered breadboard ( I used MB102 Breadboard Power Supply Module ams1117 based )
  - enc28j60

## setup

![img](doc/setup.jpg)

### wirings

- **GND** `GND` common to 3V3/5V breadboard rails + atmega328p + usbasp + enc28j60 + arduino nano
- **atmega328p** ( `VCC` from 5V rail but can work at 3V3 )
- **enc28j60** ( `VCC` from 3V3 rail ) `CS SI SCK SO` to atmega `SS MOSI SCK MISO`
- **arduino nano** `GND`; `RXD` to atmega `TXD`
- **usbasp** : `GND RST MISO MOSI SCK` to corresponding atmega

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

## references

- [pins and summary datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Summary.pdf)
