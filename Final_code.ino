/*
Arduino Water flow meter
YF- S201 Hall Effect Water Flow Sensor
Water Flow Sensor output processed to read in millilitres/second
*/
#include <Wire.h>
#include <Adafruit_GFX.h> // OLED graphics
#include <Adafruit_SH110X.h> // OLED driver
#include "WiFi.h"
#include "ThingSpeak.h"

// The ID and key to access our thingspeak website
#define CHANNEL_ID 1592311
#define CHANNEL_API_KEY "VPIVO6WGL0R6OXWV"

// the username and password to connect to our WiFi
#define ssid "MiddleburyGuest"
#define password ""

volatile int flow_frequency; // Measures flow sensor pulses
float l_sec; // Calculated litres/hour
unsigned int flowsensor = 33; // Sensor output
unsigned int BuzzerPin = 26; // Buzzer pin (A0 == GPIO 26)
unsigned long currentTime;
unsigned long cloopTime;
WiFiClient client;

// creates a pointer to an existing TwoWire instance (in this case the microcontroller's primary I2C bus)
// the first two parameters are width and length of the OLED
Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);
float total = 0; // initializes total flow to 0
int buzzer_counter = 0; // initializes the buzzer counter to 0
const int PWMFreq = 262; // Note C4
const int PWMChannel = 0;
const int PWMResolution = 10;

void IRAM_ATTR flow (){ // Interrupt function
  noInterrupts(); // to avoid debouncing
  flow_frequency++;
  interrupts();
}

void setup()
{
  Serial.begin(115200);

  // set the pin receiving data from the flow meter as input and attach an interrupt on its rising edge
  pinMode(flowsensor, INPUT);
  attachInterrupt(flowsensor, flow, RISING);
  
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  // Attach the LED PWM Channel to the GPIO Pin
  ledcAttachPin(BuzzerPin, PWMChannel);
  
  display.begin(0x3C, true); // Address 0x3C default
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  // set up the OLED orientation, text size, and text color
  display.setRotation(1);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  
  currentTime = millis(); // keeps track of time
  cloopTime = currentTime;

  // connect to the WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  // once connected to the Wifi, connect to the ThingSpeak channel
  ThingSpeak.begin(client);
}


void loop ()
{
  currentTime = millis();
  // Every second, calculate and print millilitres/second
  if(currentTime >= (cloopTime + 1000)){
    
    cloopTime = currentTime; // Updates cloopTime
    
    // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
    // (Pulse frequency* 1000/60)/7.5 = flowrate in mL/sec
    l_sec = ( (flow_frequency * 1000) / 60) / 7.5;
    flow_frequency = 0; // Reset Counter
    total += l_sec; // increment total consumption

    if (l_sec != 0) {
      // if the water is flowing      
      buzzer_counter++; // increment the buzzer counter
    
    } else {
      // if water has stopped flowing
      buzzer_counter = 0; // reset the buzzer counter
      ledcWrite(PWMChannel, 0 ); // stop the buzzer (by making a 0% duty cycle)
    }
    
    if (buzzer_counter == 10){
      // after 10 seconds of having the water running 
      /* this can be changed to a longer time, or even use volume of water used as
       * a measure since that would be more accurate in the amount of water used
       * since with time, the flow could be slow or fast.
       */
      ledcWrite(PWMChannel, 512 ); // start the buzzer (by making a ≈50% duty cycle)
    }

    display.clearDisplay();
    display.setCursor(0,0);
    display.print(l_sec); // Print millilitres/second
    display.setCursor(0,16);
    display.print(total); // Print total millilitres consumed 
    // display.setCursor(0,32);
    // display.print(buzzer_counter); // Print current value of buzzer counter
    display.display(); // actually display all of the above
    
    // sends current flow rate and total flow rate
    ThingSpeak.writeField(CHANNEL_ID, 1, l_sec, CHANNEL_API_KEY);
    ThingSpeak.writeField(CHANNEL_ID, 2, total, CHANNEL_API_KEY);
   }
}
