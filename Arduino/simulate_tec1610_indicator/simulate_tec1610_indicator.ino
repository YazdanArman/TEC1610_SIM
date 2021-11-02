bool motion_flag = 1;
bool zero_flag = 0;
bool sign_flag = 0;
bool over_range = 0;
bool over_capacity = 0;
uint8_t Decimal_Point_Location = 0 ;
uint32_t weigh_co ;
uint8_t weigh_array[5] = {0} ;
double weigh = 5865.123 ;
int count = 0;

/*
  وزن = 1658
  جايگاه مميز = 1
*/

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  //weigh_to_Integer = weigh;

  if (weigh < 0) {
    weigh *= -1;
    sign_flag = 1;
  }
  Serial.println(weigh);
  Serial.println(((int)weigh));
  Serial.println(weigh != ((int)weigh));

  while (weigh != ((int)weigh))
  {
    count++;
    weigh = weigh * 10;
  }
  Decimal_Point_Location = count;
  Serial.println(weigh);
  Serial.println(Decimal_Point_Location);
  weigh_co = weigh;

  if (weigh > 16777215) {
    Serial.println("over capacity");
    over_capacity  = 1;
  }

  if (weigh > 16777215) {
    Serial.println("over capacity");
    over_range     = 1;
  }
  //Serial.println("this is weigh binary:");
  Serial.println(weigh);
  //  Serial.println(weigh, BIN);
  // Serial.println(weigh, HEX);



  for (int i = 4; i > 0 ; i--) {
    weigh_array[i] = weigh_co & 0x7F ;
    weigh_co >>= 7;
    //Serial.println(weigh_array[i] , BIN);
  }
  if (sign_flag)      weigh_array[1] |= 0x08;
  if (over_capacity)  weigh_array[1] |= 0x10;
  if (over_range)     weigh_array[1] |= 0x20;

  weigh_array[0] = Decimal_Point_Location;
  if (weigh == 0) weigh_array[0] |= 0x08;
  if (motion_flag) weigh_array[0] |= 0x10;
  weigh_array[0] |= 0x80;

  Serial.println("this is bytes:");

  for (int i = 0; i < 5 ; i++) {

    Serial.println(weigh_array[i] , BIN);

  }

  Serial.write(weigh_array, 5);
}

void loop() {
  // put your main code here, to run repeatedly:
}
