#include <PololuLedStrip.h>

// Create an ledStrip object on pin 10.
PololuLedStrip<10> ledStrip;

#define LED_COUNT 10
rgb_color colors[LED_COUNT];
int LED_STRIP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int counter = 0;
int power = 0;
const int buttonPin = 2;

int buttonState = 0;

void setup()
{
pinMode(buttonPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == 1)           // Set up the pulse to occur periodically
    { 
      LED_STRIP[0] = 200 ;     // This is loading the array with the pulse in position one 
      // counter = 0 ;            // Reset counter to 0
    }
  
  for (int l = 0; l < 10; l++)                        // This loads the different values across for the LED Strip, looping for the 10 led positions
    {                                                 // 
      colors [l] = (rgb_color){LED_STRIP[l], 0, 0};   // Stepping one at a time, only loading a value in for the red led value, the others set to zero
    }

    ledStrip.write(colors, LED_COUNT);                // Send the array out to the light strand
    delay(40);
    
  for (int m = 9; m > 0; m--)                         // This advances the pulse through the set of 10 leds
    {
      LED_STRIP[m] = LED_STRIP[m-1];
    }
  power = LED_STRIP[0];
  
  if ( power > 0 )                               // This decrements the value of the number in position one of the led strip
    {
      LED_STRIP[0] = power - 50 ;
    }
  
  counter = counter + 1 ;
}
