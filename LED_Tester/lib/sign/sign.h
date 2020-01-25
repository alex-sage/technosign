// This class contains the functions needed for modyfig the Technopark Sign LED colors
#pragma once

#include <PololuLedStrip.h>

class Sign
{
    public:
    Sign();
    // Function to set a single letter via its ID (0-9)
    void set(uint8_t id, rgb_color color);
    // Sets a single letter via its letter (Does nothing if not contained in TECHNOPARK)
    void set(char letter, rgb_color color);
    // Sets all letters to a single color
    void setAll(rgb_color color);
    // Writes the color values to the LEDs
    void update();

    private:
    // Converts a character to a letter ID
    uint8_t letter(char L);
    // Pin where the LED strip is connected
    static const uint8_t LED_PIN = 12;
    // Total number of LEDs in the sign
    static const uint16_t LED_COUNT_TOTAL = 212;
    // Total number of letters in the sign
    static const uint8_t LETTER_COUNT = 10;
    // Contains umber of LEDs in the individual letters
    const uint8_t _ledCounts[LETTER_COUNT] = {16, 22, 16, 24, 28, 20, 20, 24, 21, 21};
    // Contains start index in _colorValues array for each letter
    uint8_t _letterStart[LETTER_COUNT];
    // Contains stop index in _colorValues array for each letter
    uint8_t _letterStop[LETTER_COUNT];
    // Current color values for all LEDs
    rgb_color _colorValues[LED_COUNT_TOTAL];
    // Arduino pin the LED strip is connected to
    PololuLedStrip<LED_PIN> _ledStrip;
}
