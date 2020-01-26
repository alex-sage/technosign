#pragma once
#include <PololuLedStrip.h>

// PIN 8
PololuLedStrip<8> ledStrip;

const uint16_t LED_COUNT = 212;
rgb_color leds[LED_COUNT];

const uint16_t LETTER_COUNT = 10;


/**
 * Returns an RGB base on the specified input components,
 * each on the range of 0-100, where 0 off, and 100 brightest.
 */
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

/**
 * Sets the same color for all LEDs.
 */
void all(rgb_color color)
{
    for (uint16_t i = 0; i < LED_COUNT; i++)
    {
        leds[i] = color;
    }
}

/**
 * Writes the content of the leds array to the LED strip.
 */
void write()
{
    ledStrip.write(leds, LED_COUNT);
}


/**
 * Loop over one LED at the time, set and write the specified color.
 * After each LED is updated, wait the specified ms.
 *
 * The order of iteration is the physical order and layout of the LED
 * strip. This does not necessary match the perceived logical order.
 * For a better iteration, see order.h (TODO).
 */
void snake(rgb_color color, int msDelay)
{
    for (uint16_t i = 0; i < LED_COUNT; i++)
    {
        leds[i] = color;
        write();
        delay(msDelay);
    }
}
