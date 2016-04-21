#include <PololuLedStrip.h>

// Create an ledStrip object on pin 10.
PololuLedStrip<10> ledStrip;

#define LED_COUNT 10
rgb_color colors[LED_COUNT];


void setup()
{

}

void loop()
{
  for (int i = 50; i < 250; i = i + 50)
  {
   for (int l = 0; l < 10; l++)
    {
     colors [l] = (rgb_color){i-(5*l), 0, 0};
     ledStrip.write(colors, LED_COUNT);
     delay(500); 

    } 
  }

}
