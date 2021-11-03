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
  Serial.begin(9600);

  if (weigh < 0)
  {
    weigh *= -1;
    sign_flag = 1;
  }

  weigh_co = weigh;

  //Serial.println("this is weigh binary:");
  //Serial.println(weigh);
  //Serial.println(weigh, BIN);
  //Serial.println(weigh, HEX);

  for (int i = 4; i > 0 ; i--)
  {
    weigh_array[i] = weigh_co & 0x7F ;
    weigh_co >>= 7;
  }

  if (sign_flag)      weigh_array[1] |= 0x08;
  if (over_capacity)  weigh_array[1] |= 0x10;
  if (over_range)     weigh_array[1] |= 0x20;

  weigh_array[0] = decimal_point_location;
  if (weigh == 0) weigh_array[0] |= 0x08;
  if (motion_flag) weigh_array[0] |= 0x10;
  weigh_array[0] |= 0x80;

  //Serial.println("this is bytes:");
  
  if (serial_debug)
  {
    for (int i = 0; i < 5 ; i++)
    {
      Serial.print("Byte ");
      Serial.print(i);
      Serial.print(" : ");
      Serial.print("0x");
      Serial.println(weigh_array[i] , HEX);
    }
  }
  
  //Serial.write(weigh_array, 5);
}

void loop()
{
   Serial.write(weigh_array, 5);
   delay(1000);
}
