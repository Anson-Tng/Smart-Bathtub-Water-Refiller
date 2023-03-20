# Smart Bathtub Water Refiller

Nowadays, smart home devices have been ingrained in our daily lives. Individuals utilise smart home gadgets in their homes and appliances, automobile accessories, electronics, workplace products, and mobile phone accessories. The majority of smart gadgets simplify the user experience by automating specific procedures and operations [1].

Hence, I would like to take this opportunity to explore more to launch the concept of solving the real-life problem and save time. The invention idea of a smart bathtub water refiller sparked when I realised that I could help my family save their time by designing an appliance to automatically fill up the water and wake them up in the morning for a nice shower. For the device, all the features will be built as automation as it brings the convenience of time saving and enhancing the quality of life.

# With the following features, the device made will perform in several ways:
•	The device will automatically turn on the shower tub at 7 AM and turn it off when the water is filled.

•	When the bathtub is filled, the filled bathtub will trigger the alarm clock to wake up the user for taking the shower bath.

# Background 

Based on the previous studies, one of the studies says that houses with smart gadgets play an important role in urban life. At the same time, the findings emphasise the importance of continuing research into the social and environmental benefits associated with the implementation of creative technologies in smart homes [2]. Furthermore, another area of research is automation with Arduino, to assist individuals who have less time to perform any task, and automation is a simple approach to ensure that any equipment or machine works as desired [3]. The paper's theme is home appliances controlled via a smart home's user-friendly interface, low-cost design, and ease of installation. Hence, the invention idea of this project would be workable with Arduino and achieving the goal of brings convenience and a modern lifestyle to humans. 

# AI Method and Tools

The purpose of this project is to use tools and code to create a “smart bathtub water refiller” appliance. The appliance is assembled with various Arduino components with the codes written in the Arduino IDE. The code is then uploaded to the mainboard Arduino MEGA 2560 using a USB connector, in order to execute its designed features as below:

•	Timer: Turn on the water when its 7AM

•	Water Level: turn off the water when its reaches high water level.

•	Alarm: reaching high water level will trigger the users to wake up.


Figure 1: Arduino components
 
Figure 2: Mainboard Arduino MEGA 2560

# Learning progress

In order to learn how the Arduino works, I’ve referred to many online tutorials and followed the instructions step by step to connect all the components with wires on the breadboard, the list of the components is: 

•	Arduino MEGA 2560

•	Breadboard (Large)

•	Real Time Clock Module [4]

•	Buzzer with 100-ohm resistor [5]

•	LCD 16x2 with I2C [6]

•	Water sensor [7]

•	2 pin LED with 220-ohm resistor (Take place of water tap system) [8]

 
Figure 3: Breadboard with the components

For the illustrative purpose of building the prototype, following are the assumptions made for the design:

•	2 pin LED light indicator as a water tap

o	(LED light on = water tap on; pour in the water manually)

o	(LED light off = water tap off; stop pouring the water manually)

•	A small measuring cup as a replacement for the bathtub (Please refer to Figure 4).

Figure 4: Prototype



# Algorithm

Firstly, I have applied the algorithm (Appendix A) in this appliance. Following are the 3 libraries that are uses for code optimisation:

•	“virtuabotixRTC.h” for RTC module.

•	“Wire.h” for I2C that is connected wit 16x2 LCD Display panel. 

•	“LiquicdCrystal_I2C.h” for LCD display.

All the component’s variables are set in the Void setup (), and all the codes will be executing in the Void loop (). In order to make the appliance runs, the LCD display will be worked as a clock to show the current time. Once the clock reaches the pre-set water fill time 7A.M., then the 2 pin LED light will be turned on as an indicator of filling up water into the bathtub. Meanwhile, there is a water sensor that detects the water level in every second, until the water level reaches the pre-set level. Next, the 2 pin LED light will be turned off and Buzzer will be triggered to alert the user that the bathtub is ready with the words displayed on the LCD.



# Evaluation & Conclusion

 
Figure 5: Smart Bathtub water refiller Architecture

The Appliance diagram is made up of Cirkit Studio, as shown in Figure 5. Due to some of the Arduino components not being available in the Cirkit Studio, the Architecture built was for reference; the actual appliance picture will be attached in Appendix B.

Following are the details to show that the goals had been met for each manipulative variable:

# Goal 1

Expected Results:
•	When its 7AM, the execution on the water tap is triggered dependent on the water level
•	Turn off the water tap when the water is at the ideal level

Arduino components used: 
•	Real Time Clock Module is used to set-up the time for the device (Please note that the RTC module with battery will be still running even if the device is power off.)
•	2 pin LED light as an indicator for water tap
•	Water Sensor to detect water level
•	LCD display for time

# Resolution 1

To turn on the water on time (LED light on), the first IF statement is used when the time is at 7AM. Then the second IF statement is used with DO-WHILE statement to execute the following scenario: 
•	Scenario 1: If water is already at the ideal level, then no action on the water tap.
•	Scenario 2: If water is below the ideal level, then turn on the water tap (LED lights on).



# Goal 2

Expected Results:
•	Reaching high water level will trigger the buzzer to wake user up.
Arduino components used: 
•	Buzzer
•	LCD display

# Resolution 2

To wake the user up, the IF Statement is used to trigger buzzer once the water reaches the high-water level. The buzzer will be ringing for 20 seconds, and LCD will display a message to tell user it is time to shower.









































# Results

10 appliance test runs were carried out and all the tests were examined with same method as shown below:

Test design: Two different time are set in the test run to ensure that the appliance is working consistently for at least two times.

The test run time was fixed as 8:59:55 PM. The water filling time has 2 set of time, which is 9PM and 9:0:40PM. Once the first pre-set time is reached, the LED light will be turned on. Then, I would be pouring the water into the container at a constant speed to simulate as a water tap. The water filling will be stopped after the water sensor is detected at the ideal level and buzzer will rings for few seconds.

In order to test the appliance stability, the water would be cleared after the first water filling time and waits for second water filing time to execute the same action.


Test is being ran for 10 times with the following outcome:

Attempt #	Success/Fail	Outcome/ problem

1	Fail	Buzzer wasn’t working, assembled wrongly.

2	Fail	Buzzer ringing too short, longer the duration in codes.

3	Fail	Water wasn’t detected with the water sensor.

4	Success	Success but water level needs better adjustment.

5	Success	Success and modify the alarm messages 

6	Success	Adjust the ideal water level variable. 

7	Fail	Arduino works faulty, time reset with no reason.

8	Fail	Wire failing (Appendix C.1 Video)

9	Success	All goes well, all was at the ideal level and time.

10	Success	Successful run (Appendix C.2 Video)

# Conclusion

The appliance can perform consistently as per designed:

-	User can set up a timer to automatically fill up the bathtub (experiment is set at 9PM)

-	When the bathtub is filled at ideal level, the buzzer rings to wake user up.

The goal reached where the appliance can consistently perform the above tasks after being tested for 10 test runs.

To conclude, the outcome of the results is as expected to save users time in waiting water to be filled in the morning. However, during the project has perceived significant enhancements can be done in future research, the following are the future enhancements for the project:

•	Implement a water tap automation system to Arduino (Requires water pump hardware).

•	Implement a control panel for user to make time changes.

•	Implement a new feature as smart control on water temperature.

•	Implement the association between the appliance with application on mobile phone.
  




# Acknowledgements
In this project, two libraries are implemented to allows the Arduino be working with write & read the time from RTC module; and enable the LCD to display what is written in code. The two libraries are implemented in the coding section, The following are the libraries implemented and credits: 

LCD library: Thanks to joaopedrosgs and fdebrabander
https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

RTC: Thanks to crhisfryer78
https://github.com/chrisfryer78/ArduinoRTClibrary


# References

[1] 	M. S. Gadget, “What is Smart Gadget?,” My Smart Gadget, [Online]. Available: https://mysmartgadget.com/what-is-smart-gadget/. [Accessed 10 October 2021].

[2] 	A. a. T. J. a. O. H. a. F. A. a. N. N. a. G. M. Ghaffarianhoseini, “The essence of smart homes: Application of intelligent technologies towards smarter urban future,” Artificial Intelligence: Concepts, Methodologies, Tools, and Applications, pp. 79-121, 2016. 

[3] 	V. Malav, “Research Paper On Home Automation Using Arduino,” 2019.

[4] 	Miliohm, “DS1302 RTC with Arduino Tutorial,” Miliohm.com, 22 September 2020. [Online]. Available: https://miliohm.com/ds1302-rtc-with-arduino-tutorial/. [Accessed 10 October 2021].

[5] 	SURYATEJA, “USE a BUZZER MODULE (PIEZO SPEAKER) USING ARDUINO,” Arduino, 5 June 2018. [Online]. Available: https://create.arduino.cc/projecthub/SURYATEJA/use-a-buzzer-module-piezo-speaker-using-arduino-uno-89df45. [Accessed 10 October 2021].

[6] 	A. Sharma, “LCD I2C Tutorial,” Arduino, 5 December 2018. [Online]. Available: https://create.arduino.cc/projecthub/Arnov_Sharma_makes/lcd-i2c-tutorial-664e5a. [Accessed 10 October 2021].

[7] 	M. Murray, “ARDUINO WATER LEVEL SENSOR TUTORIAL,” The Geek Pub, 19 August 2021. [Online]. Available: https://www.thegeekpub.com/236571/arduino-water-level-sensor-tutorial/. [Accessed 10 october 2021].

[8] 	S. Campbell, “GETTING STARTED WITH THE ARDUINO – CONTROLLING THE LED,” Circuit Basics, [Online]. Available: https://www.circuitbasics.com/arduino-basics-controlling-led/. [Accessed 10 October 2021].



