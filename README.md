# Add NICENANO / NRF52 SUPERMINI to PlatformIO
![image](https://github.com/user-attachments/assets/8b973aa3-b75f-4b1c-8cd1-29e77cf1d793)
(I will change SPI some day bc its in the way of the only 3 pins with ADC, my mistake. or go to the config `variant.h` and change it urself)
## INSTALL


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

IMPORTANT! 
P0.02 (SCK) moved to P1.11 (SCK)
P0.29 (MOSI) to P1.13 (MOSI)
P0.31 (MISO) to P1.15 (MISO)
P1.01 (SCL) to P1.06 (SCL)
P1.02 (SDA) to P1.04 (SDA) 
Why? So I2C is on a outer pin, and SPI was on the only 3 ADC pins. now you can develop easier and use ADC & SPI
