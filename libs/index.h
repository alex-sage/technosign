#pragma once
#include "common.h"

// T
const byte T_1 = 0;
const byte T_2 = 15;
// E
const byte E_1 = T_2 + 1;
const byte E_2 = E_1 + 22;
// C
const byte C_1 = E_2 + 1;
const byte C_2 = C_1 + 16;
// H
const byte H_1 = C_2 + 1;
const byte H_2 = H_1 + 24;
// N
const byte N_1 = H_2 + 1;
const byte N_2 = N_1 + 28;
// O
const byte O_1 = N_2 + 1;
const byte O_2 = O_1 + 20;
// P
const byte P_1 = O_2 + 1;
const byte P_2 = P_1 + 20;
// A
const byte A_1 = P_2 + 1;
const byte A_2 = A_1 + 24;
// R
const byte R_1 = A_2 + 1;
const byte R_2 = R_1 + 21;
// K
const byte K_1 = R_2 + 1;
const byte K_2 = K_1 + 21;

const byte LETTER_MAP[LETTER_COUNT][3] = {
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


/**
 * Sets the same color for one letter.
 */
void letter(byte letter, rgb_color color)
{
    byte start;
    byte end;
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

    for (byte i = start; i <= end; i++)
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
    for (byte i = 0; i < LETTER_COUNT; i++)
    {
        letter(LETTER_MAP[i][0], color);
        write();
        delay(msDelay);
    }
}
