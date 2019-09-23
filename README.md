
![ESP32 GPIO Map](https://i.imgur.com/djuJF6L.png)
The Free and Open Source Software (FOSS) ATM, dump that stinky loose fiat change for glorious sats!

The Fossa is an extension of the Physically Faucet project, by adding support for a coin mechanism.

![ESP32 GPIO Map](https://i.imgur.com/aHgQsTC.jpg)

# Parts (Project cost £50)
- ST7735 1.8 TFT, ESP32 NodeMCU 32s, 5v Relay, Multi Coin Acceptor Mechanism, Storage Box, 12v Lead Acid Battery (optional, 12v power supply could be used), DC 12V to 5V/ 3A Voltage Converter with Dual USB 

![ESP32 GPIO Map](https://i.imgur.com/kxu5Xmo.png)
# Workflow
- User puts in chnage (we use Euros, but the mech can be programmed for any fiat, up to 6 different coins)
- Coin mech sends pulses to the ESP32, 1 pulse for every 10cents
- ESP32 calcualtes how much as been entered (capped for demo purposes at 1.50)
- ESP32 connects to lightning.gifts, and generates an invoice for the amount
- ESP32 connects to an LND instance and pays the invoice on lightning.gifts (This project uses a local copy of Zap as an admin macaroon is required so funds should be limited!
- ESP32 fetches the LNURL generated by lightning.gifts 

*note currently LNURL is only supported by "Bitcion Lightning Wallet" and "Bluewallet"


# Installing arduino + libraries

Install the Arduino IDE,<br>
https://www.arduino.cc/en/Main/Software

Install the ESP32 hardware,<br>
https://github.com/espressif/arduino-esp32#installation-instructions

From "Manage Libraries" install,<br>
- Ucglib
- ArduinoJson
- qrcode (By Richard Moore)

![a](https://i.imgur.com/mCfnhZN.png)

# ESP32 NodeMCU-32S GPIO map

*Details on wiring can be found at the header of each ino file*

![ESP32 GPIO Map](https://i.imgur.com/PLP3YBG.jpg)
