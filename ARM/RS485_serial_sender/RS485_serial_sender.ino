#define RS_Enable_Pin PB1

#define Serial_debug_port Serial1
#define RS485_serial_port Serial3

#define Heart_Beat_LED_Pin PC13

int Heart_Beat_previousMillis = 0;
int Heart_Beat_interval = 100;

int RS485_send_previousMillis = 0;
int RS485_send_interval = 1000;


void setup()
{
  enableDebugPorts();
  Serial.end();

  Serial_debug_port.begin(115200);
  RS485_serial_port.begin(9600);
  pinMode(Heart_Beat_LED_Pin, OUTPUT);
}

void loop()
{
  if (millis() - Heart_Beat_previousMillis > Heart_Beat_interval)
  {
    Heart_Beat_previousMillis = millis();
    digitalWrite(Heart_Beat_LED_Pin, !digitalRead(Heart_Beat_LED_Pin));
  }

  if (millis() - RS485_send_previousMillis > RS485_send_interval)
  {
    RS485_send_previousMillis = millis();
    //Serial_debug_port.println(millis());
    preTransmission();
    RS485_serial_port.println(millis());
    postTransmission();
  }
}



void preTransmission()
{
  digitalWrite(RS_Enable_Pin, HIGH);
}

void postTransmission()
{
  digitalWrite(RS_Enable_Pin, LOW);
}
