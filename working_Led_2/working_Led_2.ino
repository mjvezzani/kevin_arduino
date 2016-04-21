#include <PololuLedStrip.h>

// Create an ledStrip object on pin 10.
PololuLedStrip<10> ledStrip;

// Create a buffer for holding 30 colors.  Takes 90 bytes.
#define LED_COUNT 10
rgb_color colors[LED_COUNT];
rgb_color refColors[20];

void setup()
{
}

void loop()
{  
  //load the colors
  refColors[1] = (rgb_color){ 255, 0, 0};
  refColors[2] = (rgb_color){ 255, 0, 63};
  refColors[3] = (rgb_color){ 255, 0, 127};
  refColors[4] = (rgb_color){ 255, 0, 187}; 
  refColors[5] = (rgb_color){ 255, 0, 255};
  refColors[6] = (rgb_color){ 180, 0, 255};
  refColors[7] = (rgb_color){ 0, 0, 255};
  refColors[8] = (rgb_color){ 0, 63, 255};
  refColors[9] = (rgb_color){ 0, 127, 255};
  refColors[10] = (rgb_color){ 0, 187, 255};
  refColors[11] = (rgb_color){ 0, 255, 255};
  refColors[12] = (rgb_color){ 0, 255, 187};
  refColors[13] = (rgb_color){ 0, 255, 127};
  refColors[14] = (rgb_color){ 0, 255, 63};
  refColors[15] = (rgb_color){ 0, 255, 0};
  refColors[16] = (rgb_color){ 63, 255, 0};
  refColors[17] = (rgb_color){ 127, 255, 0};
  refColors[18] = (rgb_color){ 187, 255, 0};
  refColors[19] = (rgb_color){ 255, 255, 0};
  refColors[0] = (rgb_color){ 255, 127, 0};

  //loop ten times to create chasing effect
  for (int i = 0; i < 20; i++) {
    for (int k = 0; k < 20; k++) {
        colors[k] = refColors[ (k+i)%20 ];
    }
    ledStrip.write(colors, LED_COUNT);
    delay(100);
  }
}
