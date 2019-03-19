import RPi.GPIO as GPIO # Import Raspberry Pi GPIO library
from time import sleep # Import the sleep function from the time module
import requests
import json
GPIO.setwarnings(False) # Ignore warning for now
GPIO.setmode(GPIO.BOARD) # Use physical pin numbering



def setupPins(sensor, greenLed, redLed):
 GPIO.setup(greenLed, GPIO.OUT, initial=GPIO.LOW) # Set pin 8 to be an output pin and set initial value to low (off)
 GPIO.setup(redLed, GPIO.OUT, initial=GPIO.LOW) # Set pin 8 to be an output pin and set initial value to low (off)
 GPIO.setup(sensor, GPIO.IN) #input for the proximity detector
 return

r = requests.get('http://blynk-cloud.com/8e009d4641f44d9186d2d7405feb43dc/project')
print(r.json())
setupPins(10,8,29)
#setupPins(36,12,31)
#setupPins(38,37,33)

def evaluatePins(sensorPin, greenLed, redLed):
 if GPIO.input(sensorPin) == GPIO.HIGH:
  r = requests.get('http://blynk-cloud.com/8e009d4641f44d9186d2d7405feb43dc/update/v2?color=%2323C48E')
  GPIO.output(greenLed, GPIO.HIGH) # Turn on
  GPIO.output(redLed, GPIO.LOW) # Turn off
 else:
  r = requests.get('http://blynk-cloud.com/8e009d4641f44d9186d2d7405feb43dc/update/v2?color=%23D3435C')
  GPIO.output(greenLed, GPIO.LOW)
  GPIO.output(redLed, GPIO.HIGH)
 return

while True: # Run forever
 evaluatePins(10, 8, 29)
 #evaluatePins(36, 12, 31)
 #evaluatePins(38, 37, 33)
