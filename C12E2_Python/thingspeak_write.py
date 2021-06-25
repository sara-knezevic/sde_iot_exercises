import http.client, urllib
import time

WRITE_KEY = 'GKS2XLJCBA5X2D95'

value = 20.0
connection = http.client.HTTPSConnection("api.thingspeak.com")
url = "/update?api_key={}&field2={:.2f}".format(WRITE_KEY, value)
connection.request("POST", url)

response = connection.getresponse()
connection.close()