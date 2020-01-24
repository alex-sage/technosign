/**
 * Concept for adressing the letters.
 */

#include <PololuLedStrip.h>

// PIN 8
PololuLedStrip<8> ledStrip;

const uint16_t LETTER_COUNT = 10;

// TODO: One of these are still wrong. I think it's the E which has one to many.
// TODO: Will have to go through the start/end LEDs of each letter and check.

// T
const uint16_t T_1 = 0;
const uint16_t T_2 = 15;
// E
const uint16_t E_1 = T_2 + 1;
const uint16_t E_2 = E_1 + 22;
// C
const uint16_t C_1 = E_2 + 1;
const uint16_t C_2 = C_1 + 16;
// H
const uint16_t H_1 = C_2 + 1;
const uint16_t H_2 = H_1 + 24;
// N
const uint16_t N_1 = H_2 + 1;
const uint16_t N_2 = N_1 + 28;
// O
const uint16_t O_1 = N_2 + 1;
const uint16_t O_2 = O_1 + 20;
// P
const uint16_t P_1 = O_2 + 1;
const uint16_t P_2 = P_1 + 20;
// A
const uint16_t A_1 = P_2 + 1;
const uint16_t A_2 = A_1 + 24;
// R
const uint16_t R_1 = A_2 + 1;
const uint16_t R_2 = R_1 + 21;
// K
const uint16_t K_1 = R_2 + 1;
const uint16_t K_2 = K_1 + 21;

const uint16_t LETTER_MAP[LETTER_COUNT][3] = {
  { 'T', T_1, T_2 },
  { 'E', E_1, E_2 },
  { 'C', C_1, C_2 },
  { 'H', H_1, H_2 },
  { 'N', N_1, N_2 },
  { 'O', O_1, O_2 },
  { 'P', P_1, P_2 },
  { 'A', A_1, A_2 },
  { 'R', R_1, R_2 },
  { 'K', K_1, K_2 },
};

const uint16_t LED_COUNT = K_2 + 1;
rgb_color leds[LED_COUNT];

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


void all(rgb_color color)
{
    for (uint16_t i = 0; i < LED_COUNT; i++)
    {
        leds[i] = color;
    }
}

void write()
{
    ledStrip.write(leds, LED_COUNT);
}

void letter(uint16_t letter, rgb_color color)
{
    uint16_t start;
    uint16_t end;
    bool found = false;

    for (int i = 0; i < LETTER_COUNT; i++)
    {
        if (letter == LETTER_MAP[i][0])
        {
            start = LETTER_MAP[i][1];
            end = LETTER_MAP[i][2];
            found = true;
            break;
        }
    }

    if (!found)
    {
        return;
    }

    for (uint16_t i = start; i <= end; i++)
    {
        leds[i] = color;
    }
}

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

void oneByOne(rgb_color color, int msDelay)
{
    for (uint16_t i = 0; i < LETTER_COUNT; i++)
    {
        letter(LETTER_MAP[i][0], color);
        write();
        delay(msDelay);
    }
}

void snake(rgb_color color, int msDelay)
{
    for (uint16_t i = 0; i < LED_COUNT; i++)
    {
        leds[i] = color;
        write();
        delay(msDelay);
    }
  
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
