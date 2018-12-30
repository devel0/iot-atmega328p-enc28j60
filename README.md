# iot-atmega328p-eth

minimal setup to debug atmega328p with enc28j60/w5500

<img src="doc/setup.jpg" width=640/>

- [prerequisites](#prerequisites)
- [config](#config)
- [wirings](#wirings)
- [sketch size](#sketch-size)
- [usage](#usage)
- [security considerations](#security-considerations)

## prerequisites

- software
  - install [vscode arduino](https://github.com/devel0/knowledge/blob/master/doc/vscode-arduino.md)
  - install [UIPEthernet](https://github.com/UIPEthernet/UIPEthernet)
- hardware
  - [atmega bare](https://github.com/devel0/iot-atmega-bare)
  - [enc28j60](https://www.microchip.com/wwwproducts/en/en022889) module or w5500

## config

- tune your network config MACADDRESS and MYIPADDR, MYIPMASK, MYDNS, MYGW if want static initialization
- choose between one of ethernet module type ( enc28j60 or w5500 )

## wirings

schematics here for w5500 [here](https://easyeda.com/editor#id=|7506cd41b26244d4b4f3a225eba49999) just skip sd card; if use enc28j60 power it from 3v3 setting JP2 to link VCC-3V3

## sketch size

*serial debug included, static ip*

**ENC28J60 (udp disabled)**

- `UIP_CONF_UDP=0` in `UIPEthernet/utility/uipethernet-conf.h`

```
Sketch uses 13364 bytes (40%) of program storage space. Maximum is 32768 bytes.
Global variables use 833 bytes (40%) of dynamic memory, leaving 1215 bytes for local variables. Maximum is 2048 bytes.
```

**W5500**

```
Sketch uses 12162 bytes (37%) of program storage space. Maximum is 32768 bytes.
Global variables use 317 bytes (15%) of dynamic memory, leaving 1731 bytes for local variables. Maximum is 2048 bytes.
```
## usage

```
telnet 10.10.2.5 1000
hi
```

- check serial `ctrl+shift+p arduino open serial`

```
received message : hi
```

## security considerations

- atmega web server with **NOT** crypted https: thing can faced to internet through a [nginx proxy](https://github.com/devel0/docker-nginx) with a valid certificate encryption
- if write ( acting or activators ) present in a internet face must present an api token ( and https of course )
- in LAN a paranoid setting suggest you have a router with firewall that allow access to the thing only to authorized frontends
