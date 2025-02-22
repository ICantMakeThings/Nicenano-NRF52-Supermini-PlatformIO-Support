# NiceNano
Add NICENANO / NRF52 SUPERMINI to PlatformIO

Copy .platformio from repo into your local .platformio and when it asks to replace files, click skip. done!

This'll work with any one of thoes aliexpress nrf52840 devkits. they have silkscreens of like, 102 for eg, which corresponds to the physical pin P1.02. In firmware you define it as PIN_102 eg. `digitalWrite(PIN_102, HIGH);`
I think thats easy enough...

I didnt do a pull req or anything bc it'd require making 2 pull requests in 2 diferent repo's which.. idk wouldent work i think. plus idk how to.
If you wanna do a pull req or add it into platformio then go right ahead. ik thisll help at least 1 person.
