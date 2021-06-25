import http.client, urllib
import time, json

READ_KEY = 'SXQT97OOEOE60HB0'

value = 20.0
connection = http.client.HTTPSConnection("api.thingspeak.com")

numOfResults = 5
urlChannel = "/channels/1250625/feeds.json?api_key={}&results={}".format(READ_KEY, numOfResults) # read entire channel

fieldNumber = 1
urlField = "/channels/1250625/fields/{}.json?api_key={}&results={}".format(fieldNumber, READ_KEY, numOfResults) # read one field

connection.request("GET", urlChannel)
response = connection.getresponse()
data = response.read()
print ("DATA channel:\n", json.loads(data.decode('utf-8')))

connection.request("GET", urlField)
response = connection.getresponse()
data = response.read()
print ("DATA field {}:\n".format(fieldNumber), json.loads(data.decode('utf-8')))

connection.close()