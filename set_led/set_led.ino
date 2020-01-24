/* Sets a single LED based on Serial input.
 * Intended for locating the grid points.
 */

#include <PololuLedStrip.h>

// Create an ledStrip object and specify the pin it will use.
PololuLedStrip<8> ledStrip;

// Create a buffer for holding the colors (3 bytes per color).
const int LED_COUNT=220;
rgb_color colors[LED_COUNT];

void setup()
{
  // Start up the serial port, for communication with the PC.
  Serial.begin(19200);
  Serial.println("Ready to receive colors.");

        // Update the colors buffer.
        rgb_color blank;
        blank.red = 255;
        blank.green = 255;
        blank.blue = 255;
        
      for(uint16_t i = 0; i < LED_COUNT; i++)
      {
        colors[i] = blank;
      }

      // Write to the LED strip.
      ledStrip.write(colors, LED_COUNT);

}


rgb_color rgb(uint16_t r, uint16_t g, uint16_t b)
{
    rgb_color c;

    // That's right. The red and green in the rgb_color object is reversed for our strip.
    c.red = g;
    c.green = r;
    c.blue = b;

    return c;
}

const rgb_color BLANK = rgb(0, 0, 0);
const rgb_color WHITE = rgb(100, 100, 100);
const rgb_color RED = rgb(100, 0, 0);
const rgb_color GREEN = rgb(0, 100, 0);
const rgb_color BLUE = rgb(0, 0, 100);
const rgb_color PURPLE = rgb(100, 0, 100);
const rgb_color YELLOW = rgb(100, 100, 0);

const rgb_color color_loop[5] = { BLANK, WHITE, RED, GREEN, BLUE };
int color_idx = 0;

void loop()
{
  if (Serial.available())
  {
    int idx = Serial.parseInt();
    color_idx++;
    color_idx %= 5;

    for(uint16_t i = 0; i < LED_COUNT; i++)
    {
	if (i == idx) {
          colors[i] = color_loop[color_idx];
	} else {
	  colors[i] = BLANK;
	}
    }

    ledStrip.write(colors, LED_COUNT);
  }
}
