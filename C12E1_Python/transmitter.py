import serial
import time
import struct

serialPort = serial.Serial('COM1', baudrate=9600)

SOURCE_ID = 2
ARDUINO_ID = 1

state = 1
pin = 13

while True:
    if (serialPort.in_waiting > 0):
        pin -= 1
        if pin < 11:
            pin = 13
            # state = 0 if state == 1 else 1

        receivedMessage = serialPort.read(8)
        dst, source, pin, value = struct.unpack('BBHf', receivedMessage)
        print ("DST: {}\nSRC: {}\nPIN: {}\nVALUE: {}".format(dst, source, pin, value))

        pass

    message = struct.pack(">BBHI", ARDUINO_ID, SOURCE_ID, pin, state)
    serialPort.write(message)

    time.sleep(1)

serialPort.close()