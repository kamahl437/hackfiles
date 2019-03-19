/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  =>
  =>          USB HOWTO: http://tiny.cc/BlynkUSB
  =>

  Blynk using a LED widget on your phone!

  App project setup:
    LED widget on V1
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT SwSerial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
    
#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

WidgetLED led1(V1);
WidgetLED led2(V2);
WidgetLED led3(V3);

BlynkTimer timer;
bool ledStatus = false;
int sensor1 = 2;
int redLED1 = 3;
int greenLED1 = 4;

int sensor2 = 7;
int redLED2 = 6;
int greenLED2 = 5;

int sensor3 = 11;
int redLED3 = 12;
int greenLED3 = 13;

#define BLYNK_GREEN     "#23C48E"
#define BLYNK_BLUE      "#04C0F8"
#define BLYNK_YELLOW    "#ED9D00"
#define BLYNK_RED       "#D3435C"
#define BLYNK_DARK_BLUE "#5F7CD8"

// V1 LED Widget is blinking
void blinkLedWidget()
{
  int sensorval1 = digitalRead(sensor1);
  int sensorval2 = digitalRead(sensor2);
  int sensorval3 = digitalRead(sensor3);
  int spotsRemaining = 0;
//  Serial.print("sensorval1: ");
//  Serial.println(sensorval1);
  if(sensorval1 == 0) {
     digitalWrite(redLED1, HIGH);
     digitalWrite(greenLED1, LOW);
     led1.setColor(BLYNK_RED);
   } else {
     digitalWrite(redLED1, LOW);
     digitalWrite(greenLED1, HIGH);
     led1.setColor(BLYNK_GREEN);
     spotsRemaining++;
   }

   if(sensorval2 == 0) {
     digitalWrite(redLED2, HIGH);
     digitalWrite(greenLED2, LOW);
     led2.setColor(BLYNK_RED);
   } else {
     digitalWrite(redLED2, LOW);
     digitalWrite(greenLED2, HIGH);
     led2.setColor(BLYNK_GREEN);
     spotsRemaining++;
   }

  if(sensorval3 == 0) {
     digitalWrite(redLED3, HIGH);
     digitalWrite(greenLED3, LOW);
     led3.setColor(BLYNK_RED);
   } else {
     digitalWrite(redLED3, LOW);
     digitalWrite(greenLED3, HIGH);
     led3.setColor(BLYNK_GREEN);
     spotsRemaining++;
   }

  Blynk.virtualWrite(V0, spotsRemaining);
}

void setup()
{
  // Debug console
  SwSerial.begin(9600);
  Serial.println("in setup");
  SwSerial.println("in setup 2");

  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);

  pinMode(sensor1, INPUT);
  pinMode(redLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);

  pinMode(sensor2, INPUT);
  pinMode(redLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);

  pinMode(sensor3, INPUT);
  pinMode(redLED3, OUTPUT);
  pinMode(greenLED3, OUTPUT);

  // Turn LED on, so colors are visible
  led1.on();
  led2.on();
  led3.on();
  // Setup periodic color change
  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
