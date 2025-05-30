# Add NICENANO / NRF52 SUPERMINI to PlatformIO
![image](https://github.com/user-attachments/assets/8b973aa3-b75f-4b1c-8cd1-29e77cf1d793)
old image, will change, for updated pinouts, scroll down.


## INSTALL
Before installing, make sure PlatformIO is fully installed, and so is nrf52 package, (make a project using any of the adafruit nrf52840 boards, build it, and you can follow the next steps: 

- Download ZIP 
- Unzip

  ![image](https://github.com/user-attachments/assets/15e68cbc-84a0-4206-aa21-608623714ee3)
  
- Go to the downloaded .platformio and where .platformio is installed in another file manager window



![image](https://github.com/user-attachments/assets/2cd42f54-15ef-4c13-80e7-aa7c0f10fa4d)

- Drag and drop the downloaded .platformio NEXT TO where your real .platformio is. (NOT INTO)

![image](https://github.com/user-attachments/assets/45752379-0a17-4621-8da2-1dc316be7df9)

- merge

![image](https://github.com/user-attachments/assets/e9d5e8df-f2aa-43e5-a4c5-737aa5b28ad9)

- make sure to check the "Apply this action to all files and folders"

What about if theres a update? delete the files and do the same, youll manage.
#### Note, if you dont have hidden files shown, you wont see the .platformio folder downloaded. (on linux at least)

## USAGE
This'll work with any one of thoes aliexpress nrf52840 devkits. they have silkscreens of like, 
102 for eg, which corresponds to the physical pin P1.02. In firmware you define it as PIN_102 eg. `digitalWrite(PIN_102, HIGH);`
I think thats easy enough...
Works with bluefruit and and all the fun lib's!

## Extra info
I didnt do a pull req or anything bc it'd require making 2 pull requests in 2 diferent repo's which.. idk wouldent work i think. plus idk how to.
If you wanna do a pull req or add it into platformio then go right ahead. ik thisll help at least 1 person.

#### To not need to worry about support, make sure to add this library in platformio.ini:

`lib_deps = 
	https://github.com/adafruit/Adafruit_nRF52_Arduino`

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

IMPORTANT! As of the latest update of the .platformio folder:
P0.02 (SCK) moved to P1.11 (SCK)
P0.29 (MOSI) to P1.13 (MOSI)
P0.31 (MISO) to P1.15 (MISO)
P1.01 (SCL) to P1.06 (SCL)
P1.02 (SDA) to P1.04 (SDA) 
Why? So I2C is on a outer pin, and SPI was on the only 3 ADC pins. now you can develop easier and use ADC & SPI at once.

More info:

#### how do you change the i2c pins for example? 

if you want to change where i2c or spi pins are, you can go to `variant.h` which is in:
`.platformio/packages/framework-arduinoadafruitnrf52/variants/nicenano/variant.h`

currently its set to:
`#define PIN_WIRE_SDA 36
#define PIN_WIRE_SCL 38`

scroll up in the file, youll see `#define PIN_104  36  // P1.04` so 36 is `PIN_104`, wanna change it to `PIN_102`? youll see
`#define PIN_102  34  // P1.02` that the definition is `34` so just change `#define PIN_WIRE_SDA 36` to `#define PIN_WIRE_SDA 34`
