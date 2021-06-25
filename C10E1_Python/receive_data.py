import serial
import send_email

# READING DATA FROM ARDUINO/WHATEVER
# serialPort = serial.Serial("COM1")
# receivedData = serialPort.read()

# example -> receivedData = "13.231"
receivedData = "13.231"

message = "Temperature" + "\n" + receivedData
send_email.send_email("lost.func@gmail.com", "lost.func@gmail.com", message)

# serialPort.write(b'13-ON') <- example serial writing

# serialPort.close()