#define RS_Enable_Pin PB1

#define Serial_debug_port Serial1
#define RS485_serial_port Serial3

#define Heart_Beat_LED_Pin PC13

int Heart_Beat_previousMillis = 0;
int Heart_Beat_interval = 100;

int RS485_send_previousMillis = 0;
int RS485_send_interval = 1000;

bool motion_flag = 0;
bool zero_flag = 0;
bool sign_flag = 0;
bool over_range = 0;
bool over_capacity = 0;
uint8_t decimal_point_location = 0;
uint32_t weigh_co;
uint8_t weigh_array[5] = {0};
int32_t weigh = -1995;

bool serial_debug = false;

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
    TEC1610_data_preparation();
    preTransmission();
    RS485_serial_port.write(weigh_array, 5);
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
