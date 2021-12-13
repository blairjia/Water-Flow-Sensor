# CS435-FINAL
Water Flow Sensor Project for Embedded Systems
Blair Jia and Zayn Makdessi - Fall 2021

## Introduction

This project is a culmination of all of the hardware based material we have learned in the course, as well as the important ethical discussions about implementing systems. When we first started brainstorming for this project, we originally had some ideas on implementing a sensor system for older vehicles, but we quickly realized the importance of promoting greener systems as the next generation of computer scientists. We therefore decided to implement a water flow tracker, to help promote the saving of water, the most important resource on this planet. Using the ESP32 Feather microcontroller, a buzzer, a flow sensor, as well as some data analytics, we have implemented a small and budget friendly system for everybody.

Our project allows users to monitor their water usage of certain faucets, taps, hoses, or small pipes, displaying the amount of water used. For the forgetful, if a tap is left on for too long, a buzzer warns them about their water usage, reminding them of the importance of saving water. The internet savy will also be able to go online, and find visualizations of their water usage, to see their trends.

INSERT DIAGRAM HERE...

## Methods
**Adafruit HUZZAH32 – ESP32 Feather Board**
This was the [microcontroller](https://www.adafruit.com/product/3405) we used for this project. We chose to use it because of the in-built WiFi capabilities. It is also simple to use and it has a substantial number of GPIO pins. It was also very convenient to choose an OLED.

**Adafruit 128x64 OLED FeatherWing**
We chose [this](https://learn.adafruit.com/adafruit-128x64-oled-featherwing?view=all) OLED because it sits on top of the ESP32 Feather Board which makes our whole setup more compact. We used the arduino’s [wire library](https://www.arduino.cc/en/reference/wire) to communicate with the feather’s primary I2C bus. Adafruit’s [GFX library](https://learn.adafruit.com/adafruit-gfx-graphics-library) holds graphics functions for the display including text. The Adafruit [SH110X library](https://www.arduino.cc/reference/en/libraries/adafruit-sh110x/) is the OLED driver library for monochrome displays with SH1107 drivers.

**Water Flow Sensor - YF-S201**
This [water flow sensor](https://www.hobbytronics.co.uk/yf-s201-water-flow-meter) is the heart of our project. This water flow sensor uses the hall effect (measures magnetic field presence) to measure the flow of water. The way it measures the flow is that it has a piece of magnet on one of the arms of the cog that creates a magnetic field when it passes by the sensor. Each time the sensor detects the magnetic field, it sends a pulse to our microcontroller. We set the pin connected to it to input, and attached an interrupt on the rising edge of that pin. The amount of pulses in a set period of time determine the flow. 

**ThingSpeak**
ThingSpeak is a platform service that allows you to visualize live data in the cloud. Using the [WiFi library](https://www.arduino.cc/en/Reference/WiFi), we connected to the WiFi, then used the [ThingSpeak library](https://www.arduino.cc/reference/en/libraries/thingspeak/) to connect to our channel with our Channel_ID and Channel_API_key. We chose to use Thingspeak because it already had an Arduino library. Also, for the future it would allow us to use different analysis on the data we are collecting.

**Piezo Buzzer**
We chose to use the [Piezo Buzzer](https://www.adafruit.com/product/160) to notify the user when a certain amount of time has passed with the water on to remind them to not waste water.




## Results
Potato

(Calibration of Sensor)

<img width="454" alt="Screen Shot 2021-12-12 at 9 00 36 PM" src="https://user-images.githubusercontent.com/86205354/145741704-1919c8fd-9896-4313-b1ed-e85cbe6ba79d.png">


## Accessibility
To start off with our project, we had to make some assumptions to make a bass implementation. Our assumptions include that users have: the mobility to turn on/off the tap/shower/hose/etc, the ability to read, ability to access the internet, ability to access water from pipes, and the ability to have some sort of power source near the flow sensor. Since our implementation, some of our current issues relating to accessibility include the screen size and clarity, and the price.The Featherwing LCD is very convenient to work with our MCU, but it might not be the best in terms of accessibility as the display is rather small, leading to smaller characters getting displayed on the screen, but also the text is only in 1 color. This could lead to some problems with some users who might be visually impaired. The second main issue is price. Although our project parts were actually the cheapest out of all the projects this semester, and somewhere in the ballpark of 70$ USD is very reasonable for a technology such as this one, if we want to implement this system worldwide, we have to make it cheaper, to make it more affordable and hence accessible in poorer parts of the world.

## Ethical Implications

###### Privacy/Security
When we first started out with this project, we really didn't think we would have any big security or privacy issues, as we thought the only data we would be seeing would be the water usage. However, as the project went on, we started to think just how problematic this could be if someone looking to cause harm was able to access this information. For private use, some person might be able to find out when the water in the household is being used, to track morning routines, or to find out implicitly when people might not be home, or might be asleep. This is a huge violation of privacy and security, and could also lead to a whole host of other security breaches. We have to make sure that our data is fully secured for the sake of our future users.

###### E-Waste
Our project is not very expensive to implement here in the US, nor are the individual parts scarce, nor is the wiring very difficult. The problem with this, is that because of the wide avalibility and cheap parts, in case anything gets broken, people might not feel compelled to grab a screwdriver to try to fix the issue, and just toss the broken parts for new parts. This produces a lot of unnecessary waste, especially because usually, fixing these issues could be very simple financially, just requiring a bit of know how on the actual parts. 

###### Highscore/Tomfoolery
This issue comes from an anecdote from Blair. When he was in fourth grade, he witnessed two eighth graders walk up to his school's newly installed water bottle filler machine, brand new with a counter that showed how much water was being used. He watched as these older students place tape over the sensor, to keep the water bottle filler running, just so they could see how high of a score they could get the counter to go. This may be an issue for our project as we have a screen which shows helpful information, INCLUDING a total amount used, and depending on where we implement the system, there could be other immature pranksters who might do the same thing that Blair witnessed. This is problematic because the whole purpose of our implementation was to promote water saving, but this type of action could derail our whole entire project's purpose.


## Schedule

ATTACH SCHEDULE ABOVE...
As you can see above, our plan of attack was very different than what we ended up doing. We had scheduled so checkpoints were weekly set goals to help manage our time. However, as you can see by the actual schedule of when we got our checkpoints complete, the vast majority of the project was done in a week. We think this reflects on just how busy college students are with deadlines, and although we did not follow our schedule timewise or order wise, we still used it as a checkpoint. One of the reasons why we also didn't go in order, was because that for some checkpoints, we would run into some problems, and instead of struggling and not making any progress, we would move on because we realized that a lot of steps were actually independent from each other.   

## Issues
blah blah
blah

(Issues with Flow sensor)

<img width="479" alt="Screen Shot 2021-12-12 at 9 02 22 PM" src="https://user-images.githubusercontent.com/86205354/145741628-183b687c-ebff-4688-8be5-5dc8dfce81df.png">



## Future Work

###### HTTP vs MQTT
The arduino library of Thingspeak, actually uses http calls when communicating with the device and the online server, which we didn’t really know what it meant until mqtt was introduced to us in class after the implementation. We realized that for our usage, http calls were not nearly as efficient as mqtt calls, and that is something we want to switch to in the coming future.

###### Real Time Updates
Right now under the free version of Thingspeak, we can only send data every 15 seconds, which is not very good for short bursts of data.(especially for a value like flow rate) An example of this could be someone using the tap for less than 15 seconds.  An upgraded version of ThingSpeak would enable us to send data every second, which would also help us reach another goal of compiling data together to send user information once a month about their consumption. Thingspeak has an alerts API, and we could use that to notify users via email their consumption rates at set time intervals (Weekly, monthly, or yearly).

(An example of Thingspeak Alerts API)

<img width="350" alt="Screen Shot 2021-12-12 at 9 02 31 PM" src="https://user-images.githubusercontent.com/86205354/145741410-2d514011-3fdd-4625-a49f-95572b59b2fb.png">


## Far Future

###### Sustainability Office at Middlebury
When we brought out the ideas of this project to Professor Vaccari, he suggested for us to contact the Sustainability Office at Middlebury, to tell them about our project planning. After some careful consideration, we realized that we probably wanted something tangible before contacting the office about anything. Now that we have a proof of concept, a long term goal is to set water flow systems such as these ones up in places around campus, especially dorms, to further help bring Middlebury into a greener future. We are currently in the process of contacting the office, just to see the ideas and logistics a project such as this one has to go from a concept to an actual product. Look out for water flow sensors across the Middlebury campus! 

###### Smart Home
Another major future goal we had, was to connect with Smart Home devices such as Amazon Alexa or Google Nest to help monitor users' usage across the home, whether that be a sensor on the main water pipe, or several sensors spread out to monitor individiual rooms. We think that it would be a great addition to be able to easily access data to see how the users are doing, but we understand it is a long journey to get third party apps and devices hooked up with these already established devices. A dream of ours would be able ot ask Alexa how much water has the user used in the past day, or the Google Nest displaying warnings or messages of unusual water useage.   









