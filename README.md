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

wirings

- GND common to 3V3, 5V breadboard rails + atmega328p + usbasp + enc28j60 + arduino nano (optional for serial debug)
- 3V3 : enc28j60
- 5V : atmega328p
- arduino nano RXD to atmega TXD
- `RST MISO MOSI SCK` between atmega-usbasp
- enc28j60 `CS SI SCK SO` to atmega `SS MOSI SCK MISO`

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
