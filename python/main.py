import serial

ser = serial.Serial(
    port='COM6',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS
    # timeout=1
)

print("connected to: " + ser.portstr)

while 1:
    for byte_counter in range(5):
        cc = ser.read(1).hex()
        print("Byte {} : 0x{}".format(byte_counter, cc))
    print("--------------------")
