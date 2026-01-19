# Add NICENANO / NRF52 SUPERMINI to PlatformIO
![Pinout](https://github.com/ICantMakeThings/Nicenano-NRF52-Supermini-PlatformIO-Support/blob/main/ICMTPINOUTNRF52840.svg)
<img width="1322" height="891" alt="image" src="https://github.com/user-attachments/assets/a486b65d-29d1-4438-9c63-7d7d08bc4ee4" />


## USAGE
This'll work with any one of thoes aliexpress nrf52840 devkits.

like; TENSTAR ROBOT ProMicro NRF52840

Super NRF52840 (the seedstudio xiao looking ripoff) 

they have silkscreens of like, 
102 for eg, which corresponds to the physical pin P1.02. In firmware you define it as PIN_102 eg. `digitalWrite(PIN_102, HIGH);`
I think thats easy enough...
Works with bluefruit and and all the fun lib's!

**It seems like you need to press upload twice for it to upload. just a note,**

#### Make sure to add this library in platformio.ini:

`lib_deps = 
	https://github.com/adafruit/Adafruit_nRF52_Arduino`
 
##### Pinouts:

SPI
`P1.11 (SCK),
P1.13 (MOSI),
P1.15 (MISO)`

I2C
`P1.06 (SCL),
P1.04 (SDA)`

Serial1
`P0.06 (TX)
P0.08 (RX)`
Serial1.begin(9600);

#### how do you change the i2c pins for example? 

if you want to change where i2c or spi pins are, you can go to `variant.h` which is in:
`.platformio/packages/framework-arduinoadafruitnrf52/variants/nicenano/variant.h`

currently its set to:
`#define PIN_WIRE_SDA 36
#define PIN_WIRE_SCL 38`

scroll up in the file, youll see `#define PIN_104  36  // P1.04` so 36 is `PIN_104`, wanna change it to `PIN_102`? youll see
`#define PIN_102  34  // P1.02` that the definition is `34` so just change `#define PIN_WIRE_SDA 36` to `#define PIN_WIRE_SDA 34`



## INSTALL
#### Option 1
Before installing, make sure PlatformIO is fully installed, and so is nrf52 package, (make a project using any of the adafruit nrf52840 boards, build it, and you can follow the next steps: 

- Download ZIP 
- Unzip

  ![image](https://github.com/user-attachments/assets/15e68cbc-84a0-4206-aa21-608623714ee3)
  
- Go to the downloaded .platformio and where .platformio is installed in another file manager window

#### Note, if you dont have hidden files shown, you wont see the .platformio folder downloaded. (on linux at least)

![image](https://github.com/user-attachments/assets/2cd42f54-15ef-4c13-80e7-aa7c0f10fa4d)

- Drag and drop the downloaded .platformio NEXT TO where your real .platformio is. (NOT INTO)

![image](https://github.com/user-attachments/assets/45752379-0a17-4621-8da2-1dc316be7df9)

- merge

![image](https://github.com/user-attachments/assets/e9d5e8df-f2aa-43e5-a4c5-737aa5b28ad9)

- make sure to check the "Apply this action to all files and folders"

#### Option 2

* clone the source code using git
  `git clone https://github.com/bertrik/nicenano-example`
* enter the arduino source tree
  `cd nicenano-example/supermini`
  (for windows I think it's `\` instead of `/`) 
* create python virtual env
  `python3 -m venv .venv`
  (on windows change python3 to `python3.13` or whatever specific version you have) 
* activate the virtual env
  `source .venv/bin/activate`
  (on windows it's `.venv\Scripts\activate`) 
* install platformio
  `pip3 install platformio`
* build the example program
  `pio run`

#### Once done:
The .ini is:
```
[env:nicenano]
platform = nordicnrf52
board = nicenano
framework = arduino
lib_deps =  https://github.com/adafruit/Adafruit_nRF52_Arduino
```
and the name of the board is:
<img width="533" height="49" alt="image" src="https://github.com/user-attachments/assets/36a89642-3c58-4cb8-9baf-9f258f2c1423" />


## Extra Info

Why does my nRF take so much power?
Most likely because the charging IC is very leaky, if you want to use as little power as possible, use the "VDD" smd pad in the bottom side of the board, where the debugging pins are. 

Zephyr = [here](https://docs.zephyrproject.org/latest/boards/others/promicro_nrf52840/doc/index.html)

If you want to use n-able:
```
[env:pro_micro_nrf52840]
platform = https://github.com/LeeorNahum/platform-n-able-pro-micro-nrf52840.git#master
board = pro_micro_nrf52840
framework = arduino

lib_deps =
  https://github.com/h2zero/NimBLE-Arduino.git#master
```
