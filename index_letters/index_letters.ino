/**
 * Concept for adressing the letters.
 */

#include "common.h"
#include "index.h"

void setup()
{
    Serial.begin(19200);

    all(rgb(0, 0, 0));
    write();
    delay(100);

    leds[0] = WHITE;
    write();
    delay(1000);
}

void loop()
{
    int d1 = 100;
    oneByOne(RED, d1);
    oneByOne(GREEN, d1);
    oneByOne(BLUE, d1);

    int d2 = 30;
    snake(RED, d2);
    snake(PURPLE, d2);
    snake(BLUE, d2);
    snake(GREEN, d2);
    snake(YELLOW, d2);
}
