import imaplib
import time
import serial
import struct

ARDUINO_ID = 1
SOURCE_ID = 2
LED_PIN = 13
STATE = 13

serialPort = serial.Serial("COM1", baudrate=9600)

mail = imaplib.IMAP4_SSL("imap.gmail.com")
mail.login("lost.func@gmail.com", "rgzekyhzyfryrdbe")

def sendCommandToArduino(pin, state):
    message = [ARDUINO_ID, SOURCE_ID, pin, state]
    message = bytearray(message)
    serialPort.write(message)

# turn on LED if there are unread e-mails
# used with proteus project C11E1
while True:
    mail.select("inbox")
    # alternative search for unread e-mails with subject name
    # returnCode, response = mail.search(None, 'SUBJECT "on/off-led" UNSEEN')
    returnCode, response = mail.search(None, "UNSEEN")
    unread_messages_num = response[0].split()
    emails_num = len(unread_messages_num)

    if emails_num == 0:
        sendCommandToArduino(LED_PIN, 0)
        time.sleep(0.1)
        # if message is read and LED turned off
        # mail.store(message, "+FLAG", "\Seen")
        # mark above message as seen
    else:
        sendCommandToArduino(LED_PIN, 1)
        time.sleep(0.1)
    time.sleep(5)