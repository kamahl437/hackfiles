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
