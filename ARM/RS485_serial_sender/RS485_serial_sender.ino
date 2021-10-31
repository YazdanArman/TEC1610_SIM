#define RS_Enable_Pin PB1

#define Serial_debug_port Serial1
#define RS485_serial_port Serial3

#define Heart_Beat_LED_Pin PC13

int previousMillis = 0;
int interval = 100;


void setup()
{
  Serial_debug_port.begin(115200);
  RS485_serial_port.begin(9600);
  pinMode(Heart_Beat_LED_Pin, OUTPUT);
}

void loop()
{
  if (millis() - previousMillis > interval)
  {
    previousMillis = millis();
    digitalWrite(Heart_Beat_LED_Pin, !digitalRead(Heart_Beat_LED_Pin));
  }
}
