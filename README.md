# CS435-FINAL
Water Flow Sensor Project for Embedded Systems
Blair Jia and Zayn Makdessi - Fall 2021

## Introduction

This project is a culmination of all of the hardware based material we have learned in the course, as well as the important ethical discussions about implementing systems. When we first started brainstorming for this project, we originally had some ideas on implementing a sensor system for older vehicles, but we quickly realized the importance of promoting greener systems as the next generation of computer scientists. We therefore decided to implement a water flow tracker, to help promote the saving of water, the most important resource on this planet. Using the ESP32 Feather microcontroller, a buzzer, a flow sensor, as well as some data analytics, we have implemented a small and budget friendly system for everybody.

Our project allows users to monitor their water usage of certain faucets, taps, hoses, or small pipes, displaying the amount of water used. For the forgetful, if a tap is left on for too long, a buzzer warns them about their water usage, reminding them of the importance of saving water. The internet savy will also be able to go online, and find visualizations of their water usage, to see their trends.

INSERT DIAGRAM HERE...

## Methods
blah blah
blah FOR ZAYN TO DO.

This section should be used to described how you accomplished your goals! Here you can describe the devices/peripherals/libraries that you used. If you used existing projects as inspiration or building blocks (cite them!), include in this section a description about how you incorporated these projects, what existing code you used and what you added/modified, and clearly identify how your project differs from an existing one.

###### Flow Sensor
Flow sensor go zoom 

###### Adafruit FeatherWing OLED 
OLED screen go beep boop

###### Thingspeak
Thingspeak goes woosh



## Results
Potato

## Accessibility
blah blah
blah

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

## Future Work

###### Buzzer
Use the buzzer for more things, like playing a melody in certain situations

###### HTTP vs MQTT
Change from http to mqtt calls for some things
Send users information once a month (or any set duration) about their consumption


###### Real Time Updates
Real time updates, with a subscription to ThingSpeak

Save data and upload weekly, monthly, and yearly averages



## Far Future

###### Sustainability Office at Middlebury
When we brought out the ideas of this project to Professor Vaccari, he suggested for us to contact the Sustainability Office at Middlebury, to tell them about our project planning. After some careful consideration, we realized that we probably wanted something tangible before contacting the office about anything. Now that we have a proof of concept, a long term goal is to set water flow systems such as these ones up in places around campus, especially dorms, to further help bring Middlebury into a greener future. We are currently in the process of contacting the office, just to see the ideas and logistics a project such as this one has to go from a concept to an actual product. Look out for water flow sensors across the Middlebury campus! 

###### Smart Home
Another major future goal we had, was to connect with Smart Home devices such as Amazon Alexa or Google Nest to help monitor users' usage across the home, whether that be a sensor on the main water pipe, or several sensors spread out to monitor individiual rooms. We think that it would be a great addition to be able to easily access data to see how the users are doing, but we understand it is a long journey to get third party apps and devices hooked up with these already established devices. A dream of ours would be able ot ask Alexa how much water has the user used in the past day, or the Google Nest displaying warnings or messages of unusual water useage.   









