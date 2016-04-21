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
  //load the colors
  //refColors[1] = (rgb_color){ 255, 255, 255};
  //refColors[2] = (rgb_color){ 200, 200, 200};
  //refColors[3] = (rgb_color){ 150, 150, 150};
  //refColors[4] = (rgb_color){ 100, 100, 100}; 
  //refColors[5] = (rgb_color){ 50, 50, 100};
  //refColors[6] = (rgb_color){ 0, 0, 100};
  //refColors[7] = (rgb_color){ 0, 0, 200};
  //refColors[8] = (rgb_color){ 100, 0, 255};
  //refColors[9] = (rgb_color){ 200, 0, 255};
  //refColors[10] = (rgb_color){ 255, 0, 0};
  //refColors[11] = (rgb_color){ 255, 0, 0};
  //refColors[12] = (rgb_color){ 200, 0, 0};
  //refColors[13] = (rgb_color){ 150, 0, 0};
  //refColors[14] = (rgb_color){ 100, 0, 0}; 
  //refColors[15] = (rgb_color){ 50, 0, 0};
  //refColors[16] = (rgb_color){ 0, 0, 0};
  //refColors[17] = (rgb_color){ 0, 50, 0};
  //refColors[18] = (rgb_color){ 0, 100, 0};
  //refColors[19] = (rgb_color){ 0, 150, 0};
  //refColors[0] = (rgb_color){ 0, 200, 0};
  
  //loop ten times to create chasing effect
  for (int i = 0; i < 200; i=i+5) {
    for (int j = 0; j < 200; j=j+5) {
      for (int k = 0; k < 200; k=k+5) {
        for (int l = 0; l < 10; l++) {
        colors[l] = (rgb_color){ i, j, k};
   //     delay(5);
        }
     ledStrip.write(colors, LED_COUNT);
     delay(5);
      }
      for (int k = 200; k > 0; k=k-5) {
        for (int l = 0; l < 10; l++) {
          colors [l] = (rgb_color){ i, j, k};
//          delay(15);
        }
      ledStrip.write(colors, LED_COUNT);
      delay(5);
      }
   }
  }
}
