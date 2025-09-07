# Add NICENANO / NRF52 SUPERMINI to PlatformIO
![Pinout](https://github.com/ICantMakeThings/Nicenano-NRF52-Supermini-PlatformIO-Support/blob/main/ICMTPINOUTNRF52840.svg)


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


## Extra Info

Why does my nRF take so much power?
Most likely because the charging IC is very leaky, if you want to use as little power as possible, use the "VDD" smd pad in the bottom side of the board, where the debugging pins are. 

I have a Zephyr branch but there is also something about this board on there [website](https://docs.zephyrproject.org/latest/boards/others/promicro_nrf52840/doc/index.html)

If you want to use n-able, here is what to put in [platformio.ini](https://github.com/LeeorNahum/platform-n-able-pro-micro-nrf52840?tab=readme-ov-file#updated-usage-for-pro-micro-nrf52840)
