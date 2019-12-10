/**
 * Tester for each letter, or a row of more.
 *
 * Initially sets the first LED to all white.
 * Then cycles through RGB, one LED at a time.
 */

#include <PololuLedStrip.h>

// PIN
PololuLedStrip<8> ledStrip;

#define LED_COUNT 220
rgb_color colors[LED_COUNT];

void setup()
{
  Serial.begin(19200);

  rgb_color blank;
  blank.red = 255;
  blank.green = 255;
  blank.blue = 255;

  /*
  for(uint16_t i = 0; i < LED_COUNT; i++)
  {
    colors[i] = blank;
  }
  */

  colors[0] = blank;
  

  ledStrip.write(colors, LED_COUNT);

  delay(1000);
}

void loop()
{
    rgb_color color;
    color.red = 100;
    color.green = 0;
    color.blue = 0;
  
    for (int i = 0; i < LED_COUNT; i++)
    {
      colors[i] = color;
      ledStrip.write(colors, LED_COUNT);
      delay(100);
    }

    color.red = 0;
    color.green = 100;
    color.blue = 0;
  
    for (int i = 0; i < LED_COUNT; i++)
    {
      colors[i] = color;
      ledStrip.write(colors, LED_COUNT);
      delay(100);
    }


    color.red = 0;
    color.green = 0;
    color.blue = 100;
  
    for (int i = 0; i < LED_COUNT; i++)
    {
      colors[i] = color;
      ledStrip.write(colors, LED_COUNT);
      delay(100);
    }
}

