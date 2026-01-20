#include <Arduino.h>
#include <Adafruit_TinyUSB.h>

Adafruit_USBD_HID usb_hid;

void sendKey(uint8_t keycode, uint8_t mod) {
  uint8_t keys[6] = { keycode, 0,0,0,0,0 };
  usb_hid.keyboardReport(0, mod, keys);
  delay(5);
  usb_hid.keyboardRelease(0);
  delay(5);
}

uint8_t ascii(uint8_t c, uint8_t &mod) {
  mod = 0;

  if (c >= 'a' && c <= 'z') return HID_KEY_A + (c - 'a');
  if (c >= 'A' && c <= 'Z') {
    mod = KEYBOARD_MODIFIER_LEFTSHIFT;
    return HID_KEY_A + (c - 'A');
  }

  if (c == ' ') return HID_KEY_SPACE;
  return 0;
}

void printDotHID(const char *s) {
  while (*s) {
    uint8_t mod;
    uint8_t key = ascii(*s, mod);
    if (key) sendKey(key, mod);
    s++;
  }
}

void setup() {
  USBDevice.setID(0xFED0, 0x2468);
  USBDevice.setManufacturerDescriptor("ICantMakeThings");
  USBDevice.setProductDescriptor("Example");
  USBDevice.setSerialDescriptor("ICMT");

  uint8_t const hid_report_descriptor[] = { TUD_HID_REPORT_DESC_KEYBOARD() };
  usb_hid.setReportDescriptor(hid_report_descriptor, sizeof(hid_report_descriptor));
  usb_hid.begin();

  while (!USBDevice.mounted()) delay(10);
  delay(1000);

  printDotHID("Example of keyboard printing thingy");
  delay(100);
  sendKey(HID_KEY_TAB, KEYBOARD_MODIFIER_LEFTALT);
  delay(100);
  sendKey(HID_KEY_T, KEYBOARD_MODIFIER_LEFTCTRL | KEYBOARD_MODIFIER_LEFTALT);
}

void loop() {}
