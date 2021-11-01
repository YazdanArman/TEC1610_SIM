bool MotionFlag = 1;
bool ZeroFlag = 1;
bool SignFlag = 1;
bool OverRange = 1;
bool OverCapacity = 1;
uint8_t DCPL = 5;
uint32_t sample ;
uint8_t weigh_array[5];
uint32_t weigh = 0X00000F4B;

/*
وزن = 1658
جايگاه مميز = 1
*/

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("this is weigh binary:");
  Serial.println(weigh, BIN);

  sample = weigh;

  for (int i = 4; i > 0 ; i--) {
    weigh_array[i] = sample & 0x7F ;
    sample >>= 7;
    //Serial.println(weigh_array[i] , BIN);
  }
  if (SignFlag) weigh_array[1] |= 0x08;
  if (OverCapacity) weigh_array[1] |= 0x10;
  if (OverRange) weigh_array[1] |= 0x20;

  weigh_array[0] = DCPL;
  if (ZeroFlag) weigh_array[0] |= 0x08;
  if (MotionFlag) weigh_array[0] |= 0x10;
  weigh_array[0] |= 0x80;

  Serial.println("this is bytes:");

  for (int i = 0; i < 5 ; i++) {

    Serial.println(weigh_array[i] , BIN);

  }
 
  Serial.write(weigh_array,40);
}

void loop() {
  // put your main code here, to run repeatedly:
}
