# java setup
Download java and eclipse
Start workspace, make new maven project
Add to pom:

  <repositories>
	<repository>
		<id>oss-snapshots-repo</id>
		<name>Sonatype OSS Maven Repository</name>
		<url>https://oss.sonatype.org/content/groups/public</url>
		<snapshots>
			<enabled>true</enabled>
			<updatePolicy>always</updatePolicy>
		</snapshots>
	</repository>
</repositories>
  <dependencies>
<dependency>
    <groupId>com.pi4j</groupId>
    <artifactId>pi4j-core</artifactId>
   <version>1.3-SNAPSHOT</version>
</dependency>
  </dependencies>

Use code like this:


package UAHS.ParkingSensor;

import com.pi4j.io.gpio.GpioController;
import com.pi4j.io.gpio.GpioFactory;
import com.pi4j.io.gpio.GpioPinDigitalOutput;
import com.pi4j.io.gpio.RaspiPin;

public class ParkingSensor {

	   public static void main(String[] args) {
		    try {
		        /** create gpio controller */
		        final GpioController gpio = GpioFactory.getInstance();

		        final GpioPinDigitalOutput ledPin = gpio.provisionDigitalOutputPin(RaspiPin.GPIO_15);
//		        final GpioPinDigitalOutput ledPin = gpio.provisionDigitalOutputPin(RaspiPin.GPIO_27);//this will be the input from the sensor

		        /** Blink every second */
		        ledPin.blink(1000, 15000);

		        /** keep program running until user aborts (CTRL-C) */
		        while (true) {
		        Thread.sleep(500);
		        }

		    } catch (Exception e) {
		        e.printStackTrace();
		    }
		    }
}


make a run config for the main method
Export as a runnable jar with the libraries packed in
shell on to the pi and install java:
sudo apt-get install oracle-java8-jdk


The following shouldn't be necessary and should only be done if problems are found - install the pi4j libs that allow you to talk to the gpio pins:
curl -s get.pi4j.com | sudo bash

verify your installation:
'which java' should print something like 'usr/bin/java'.  If that works it means you have java and its location
java -version should print some info about the installation.  This means you not only have java, but you can call it without it blowing up

Wiring for pi needs manually checked out, compiled for this to work(this is sketchy looking but widely reccomended):
http://wiringpi.com/download-and-install/

Move your jar over to the pi:
scp ParkingSensor.jar pi@raspberrypi.local:ParkingSensor.jar

sudo java -jar ParkingSensor.jar


