#include <PololuLedStrip.h>

// Create an ledStrip object on pin 10.
PololuLedStrip<10> ledStrip;

#define LED_COUNT 10
rgb_color colors[LED_COUNT];
int i = 0;
int j = 0;
int k = 0;

void setup()
{
}

void loop()
{  
  //loop ten times to create chasing effect
  for (int i = 0; i < 200; i=i+5) {
    for (int j = 0; j < 200; j=j+5) {
      for (int k = 0; k < 200; k=k+5) {
        for (int l = 0; l < 10; l++) {
        colors[l] = (rgb_color){ i, j, k};
   //     delay(5);
        }
     ledStrip.write(colors, LED_COUNT);
//     delay(5);
      }
      for (int k = 200; k > 0; k=k-5) {
        for (int l = 0; l < 10; l++) {
          colors [l] = (rgb_color){ i, j, k};
//          delay(5);
        }
      ledStrip.write(colors, LED_COUNT);
      }
   }
  }
}
