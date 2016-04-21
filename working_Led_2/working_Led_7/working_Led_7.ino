#include <PololuLedStrip.h>

// Create an ledStrip object on pin 10.
PololuLedStrip<10> ledStrip;

#define LED_COUNT 10
rgb_color colors[LED_COUNT];
int RED_LED_STRIP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int BLUE_LED_STRIP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int GREEN_LED_STRIP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int counter = 0;
int red_power = 0;
int green_power = 0;
void setup()
{

}

void loop()
{
  if (counter == 27)           // Set up the pulse to occur periodically
    { 
      RED_LED_STRIP[0] = 200 ;     // This is loading the array with the pulse in position one 
  //    GREEN_LED_STRIP[9] = 200;
  //    counter = 0 ;            // Reset counter to 0
    }
  if (counter == 30)
    {
      GREEN_LED_STRIP[9] = 200;
      counter = 0 ;
    }

  for (int l = 0; l < 10; l++)                        // This loads the different values across for the LED Strip, looping for the 10 led positions
    {                                                 // 
      colors [l] = (rgb_color){RED_LED_STRIP[l], GREEN_LED_STRIP[l], 0};   // Stepping one at a time, only loading a value in for the red led value, the others set to zero
    }
    ledStrip.write(colors, LED_COUNT);                // Send the array out to the light strand
    delay(50);
    
  for (int m = 9; m > 0; m--)                         // This advances the pulse through the set of 10 leds
    {
      RED_LED_STRIP[m] = RED_LED_STRIP[m-1];
      GREEN_LED_STRIP[9-m] = GREEN_LED_STRIP[10-m];
    }
  red_power = RED_LED_STRIP[0];
  green_power = GREEN_LED_STRIP[9];
  
  if ( red_power > 0 )                               // This decrements the value of the number in position one of the led strip
    {
      RED_LED_STRIP[0] = red_power - 20 ;
    }
  if (green_power > 0)
    {
      GREEN_LED_STRIP[9] = green_power - 20;
    }
    
  counter = counter + 1 ;
}
