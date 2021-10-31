

uint8_t transmitted_data[5] = {0x90, 0x00, 0x00, 0x0F, 0x4B};

bool Motion;
bool Zero;
bool SignFlag;
bool OverRange;
bool OverCapacity;
// decimal point location DCP 3bit
uint32_t weigh = 0XF3450F4B;
uint32_t sample = 0;
uint8_t weigh_array[4];
bool first_bit;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println(weigh, HEX);

  sample = weigh;
  
  for (int i = 0; i < 4; i++) {
    
    sample >>= 7;
    first_bit=sample % 2;
    Serial.println(weigh_array[i] , HEX);
    Serial.println(first_bit , HEX);
    weigh_array[i] = sample & 0x7F;
    sample >>= 1;
    
  }
  
 // for (int i = 0; i < 4 ; i++)
  //  Serial.println(weigh_array[i] , HEX);


}

void loop() {
  // put your main code here, to run repeatedly:



}
