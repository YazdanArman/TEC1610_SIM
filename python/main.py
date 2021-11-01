import serial

ser = serial.Serial(
    port='COM6',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=2
)

print("connected to: " + ser.portstr)

while True:
    cc = str(ser.readline())
    print(cc)
    # print(cc[2:][:-5])
