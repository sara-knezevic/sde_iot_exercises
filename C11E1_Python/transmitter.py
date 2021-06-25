import serial
import time

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
            state = 0 if state == 1 else 1
        pass

    print ("{} {} {} {}".format(ARDUINO_ID, SOURCE_ID, pin, state))
    message = [ARDUINO_ID, SOURCE_ID, pin, state]
    message = bytearray(message)
    serialPort.write(message)

    time.sleep(1)

serialPort.close()