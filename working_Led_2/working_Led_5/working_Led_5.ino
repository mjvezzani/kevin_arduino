#include <PololuLedStrip.h>

// Create an ledStrip object on pin 10.
PololuLedStrip<10> ledStrip;

// Create a buffer for holding 30 colors.  Takes 90 bytes.
#define LED_COUNT 10
rgb_color colors[LED_COUNT];

//rgb_color refColors[20];

void setup()
{

}

void loop()
{
  for (int i = 0; i < 200; i = i+1)
  {
    for (int l = 0; l < 10; l++)
    {
      colors [l] = (rgb_color){200 - i, i, 0};
    }
    ledStrip.write(colors, LED_COUNT);
    delay(20);
  }
  for (int i = 0; i < 200; i = i+1)
  {
    for (int l = 0; l < 10; l++)
    {
      colors [l] = (rgb_color){0, 200 - i, i};
    }
    ledStrip.write(colors, LED_COUNT);
    delay(20);
  }
  for (int i = 0; i < 200; i = i+1)
  {
    for (int l = 0; l < 10; l++)
    {
      colors [l] = (rgb_color){i, 0, 200 - i};
    }
    ledStrip.write(colors, LED_COUNT);
    delay(20);
  }
 
}
