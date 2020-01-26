/**
 * Tester for the library functions.
 */

#include "common.h"
#include "index.h"
#include "grid.h"
#include "grid_func.h"

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
    int d1 = 20;
    oneByOne(RED, d1);
    oneByOne(GREEN, d1);
    oneByOne(BLUE, d1);

    int d2 = 5;
    snake(PURPLE, d2);
    snake(GREEN, d2);
    snake(YELLOW, d2);

    grid_swipe_right(RED, 100);
    grid_swipe_left(BLUE, 100);
    grid_swipe_down(GREEN, 100);
    grid_swipe_up(PURPLE, 100);
}
