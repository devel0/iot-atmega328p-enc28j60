# iot-atmega328p-enc28j60

minimal setup to debug atmega328p with enc28j60

## prerequisites

- software
  - install [vscode arduino](https://github.com/devel0/knowledge/blob/master/arduino/vscode-arduino.md)
  - install [UIPEthernet](https://github.com/UIPEthernet/UIPEthernet)
- hardware
  - arduino nano ( for serial debugging through [as serial reader](https://github.com/devel0/iot-arduino-nano-as-serial-reader) )
  - USBASP 2.0 ( as programmer )
  - atmega328p with 3.3V powered breadboard
  - enc28j60

## setup

![img](doc/setup.jpg)

- arduino nano (optional) to debug serial output from atmega328p wiring RXD serial of nano to atmega328p TXD (pin 3)
- power atmega328p with 3.3v using external power supply ( I used MB102 Breadboard Power Supply Module ams1117 based )
- connect programmer USBASP V2.0 ( jumper to 3.3v ) to atmega ( `VCC GND RST MISO MOSI SCK` )
- connect Enc28j60 to atmega ( `VCC GND CS->SS SI->MOSI SCK SO->MISO` ) ; note that programmer not influenced by presence of enc28j60 during programming but required breadboard to be 3.3v powered

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
