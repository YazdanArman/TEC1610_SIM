
#define RS_Enable_Pin PB1

#define Serial_debug_port Serial1
#define RS485_serial_port Serial3

#define Heart_Beat_LED_Pin PC13

unsigned long now;
unsigned long last_sent = 0;
const unsigned long interval = 100;

bool Heart_Beat_state = 0;

void setup()
{
  Serial_debug_port.begin(115200);
  RS485_serial_port.begin(9600);
  pinMode(Heart_Beat_LED_Pin, OUTPUT);
}

void loop()
{
  now = millis();

  if (now - last_sent >= interval)
  {
    last_sent = now;
    Heart_Beat_state ^= 1;
    digitalWrite(Heart_Beat_LED_Pin, Heart_Beat_state);
  }
}
