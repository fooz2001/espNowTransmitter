# espNowTransmitter
This project involves a data transmission device utilizing the ESP-NOW protocol. It is programmed for communication and data transfer to facilitate the control and operation of various types of robots and smart vehicles.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)

## installation
this project need to install ,Arduino ide, esp8266 bords in the ide

## usage
To use this device correctly, you need to change the MAC address of the device to which you want to send data and switch the channel to channel 9. Additionally, data should be received according to the DATA structure specified in the code(upload esp code to esp8266-01 and arduino code to arduino uno r3).

## features
 - Feature 1: This device features two separate ESP controllers to utilize the chosen protocol, along with an Arduino to support a greater number of channels
 - Feature 2: The device can reliably transmit data over a range of up to 300 meters. It can achieve even greater distances by using an ESP controller that supports an     external transmitter
 - Feature 3: This device can currently transmit six separate sets of data simultaneously(6 channels), and it can easily expand to support up to 12 channels
 - Feature 4: The device can determine its current status, specifically whether it is connected to the robot or not
 - Feature 5: The device can detect whether the data has been sent and received correctly to understand if we are experiencing a loss of the transmitted information
