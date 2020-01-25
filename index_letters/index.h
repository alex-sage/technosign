#pragma once
#include "common.h"

const uint16_t LETTER_COUNT = 10;

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

//const uint16_t LED_COUNT = K_2 + 1;
//rgb_color leds[LED_COUNT];

/**
 * Sets the same color for one letter.
 */
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

/**
 * Loop over one letter at the time, set and write the specified color.
 * After each letter is updated, wait the specified ms.
 */
void oneByOne(rgb_color color, int msDelay)
{
    for (uint16_t i = 0; i < LETTER_COUNT; i++)
    {
        letter(LETTER_MAP[i][0], color);
        write();
        delay(msDelay);
    }
}
