#include <SoftwareSerial.h>

#define UART_RX 0
#define UART_TX 1
#define SOFT_RX 2
#define SOFT_TX 3

#define BAUD_RATE 115200

// Configure inverted serial
SoftwareSerial soft_serial_invert(SOFT_RX, SOFT_TX, true);
SoftwareSerial soft_serial(8, 9);
bool isInverted = false;
bool isData = false;

void setup()
{
  Serial.begin(9600);

  soft_serial.begin(BAUD_RATE);
  soft_serial_invert.begin(BAUD_RATE);
}

void loop()
{
  static uint8_t rx;
  if (soft_serial_invert.available() > 0)
  {
    rx = soft_serial_invert.read();
    isInverted = true;
    isData = true;
  }
  else if (soft_serial.available() > 0)
  {
    rx = soft_serial.read();
    isData = true;
  }

  if (isData)
  {
    String logicType = isInverted ? "[inverted]" : "";
    String msg = "Data received " + logicType + ": ";
    Serial.print(msg);
    Serial.println(rx, HEX);
  }

  isInverted = false;
  isData = false;
}
