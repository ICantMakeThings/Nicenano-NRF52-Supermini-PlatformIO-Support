//credits to https://github.com/cat5e-inv for making the readBatteryVoltage function

#include <Arduino.h>

float readBatteryVoltage() {
  // The volatile keyword is a type qualifier in C/C++ that tells the compiler a variable's value might change in ways that the compiler cannot detect from the code alone. 
  // Essentially, it says: "Don't optimize access to this variable because its value might change unexpectedly."
  volatile uint32_t raw_value = 0;
  // Configure SAADC
  NRF_SAADC->ENABLE = 1;
  NRF_SAADC->RESOLUTION = SAADC_RESOLUTION_VAL_12bit;
  
  NRF_SAADC->CH[0].CONFIG = 
    (SAADC_CH_CONFIG_GAIN_Gain1_4 << SAADC_CH_CONFIG_GAIN_Pos) |
    (SAADC_CH_CONFIG_MODE_SE << SAADC_CH_CONFIG_MODE_Pos) |
    (SAADC_CH_CONFIG_REFSEL_Internal << SAADC_CH_CONFIG_REFSEL_Pos);
  
  NRF_SAADC->CH[0].PSELP = SAADC_CH_PSELP_PSELP_VDDHDIV5;
  NRF_SAADC->CH[0].PSELN = SAADC_CH_PSELN_PSELN_NC;
  
  // Sample
  NRF_SAADC->RESULT.PTR = (uint32_t)&raw_value;
  NRF_SAADC->RESULT.MAXCNT = 1;
  NRF_SAADC->TASKS_START = 1;
  while (!NRF_SAADC->EVENTS_STARTED);
  NRF_SAADC->EVENTS_STARTED = 0;
  NRF_SAADC->TASKS_SAMPLE = 1;
  while (!NRF_SAADC->EVENTS_END);
  NRF_SAADC->EVENTS_END = 0;
  NRF_SAADC->TASKS_STOP = 1;
  while (!NRF_SAADC->EVENTS_STOPPED);
  NRF_SAADC->EVENTS_STOPPED = 0;
  NRF_SAADC->ENABLE = 0;

  // Force explicit double-precision calculations
  double raw_double = (double)raw_value;
  double step1 = raw_double * 2.4;
  double step2 = step1 / 4095.0;
  double vddh = 5.0 * step2;

  return (float)vddh;
}


void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  float voltage = readBatteryVoltage();
  Serial.print("Batt Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  delay(100);
}
