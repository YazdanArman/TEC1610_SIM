void TEC1610_data_preparation()
{
  if (weigh < 0)
  {
    weigh *= -1;
    sign_flag = 1;
  }

  weigh_co = weigh;

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

  if (serial_debug)
  {
    for (int i = 0; i < 5 ; i++)
    {
      Serial_debug_port.print("Byte ");
      Serial_debug_port.print(i);
      Serial_debug_port.print(" : ");
      Serial_debug_port.print("0x");
      Serial_debug_port.println(weigh_array[i] , HEX);
    }
  }
}
