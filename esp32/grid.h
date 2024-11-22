#pragma once

const byte o = -1;

const byte GRID_ROWS = 10;
const byte GRID_COLS = 62;

const byte LETTER_GRID[GRID_ROWS][GRID_COLS] = {
//    T                                  E                        C                             H                             N                                       O                                  P                        A                                  R                        K                         
//    0    1    2    3    4    5    6    0    1    2    3    4    0    1    2    3    4    5    0    1    2    3    4    5    0    1    2    3    4    5    6    7    0    1    2    3    4    5    6    0    1    2    3    4    0    1    2    3    4    5    6    0    1    2    3    4    0    1    2    3    4    5
   {    9,  10,  11,  12,  13,  14,  15,  29,  30,  31,  32,  33,   o,   o,   o,  51,  52,   o,  68,   o,   o,   o,   o,  67,  87,  88,   o,   o,   o,   o,   o,   o,   o,   o,   o, 116, 117,   o,   o, 135, 136, 137, 138,   o,   o,   o, 146, 169,   o,   o,   o, 179, 180, 181,   o,   o, 200,   o,   o,   o,   o, 201 },
   {    o,   o,   o,   8,   o,   o,   o,  28,   o,   o,   o,   o,   o,  49,  50,   o,   o,  53,  69,   o,   o,   o,   o,  66,  86,   o,  89,   o,   o,   o,   o, 105,   o, 114, 115,   o,   o, 118,   o, 134,   o,   o,   o, 139,   o,   o, 147, 168,   o,   o,   o, 178,   o,   o, 182, 183, 199,   o,   o,   o, 202,   o },
   {    o,   o,   o,   7,   o,   o,   o,  27,   o,   o,   o,   o,  48,   o,   o,   o,   o,   o,  70,   o,   o,   o,   o,  65,  85,   o,  90,   o,   o,   o,   o, 104,   o, 113,   o,   o,   o, 119,   o, 133,   o,   o,   o, 140,   o,   o, 148, 167,   o,   o,   o, 177,   o,   o,   o, 184, 198,   o,   o, 203,   o,   o },
   {    o,   o,   o,   6,   o,   o,   o,  26,   o,   o,   o,   o,  47,   o,   o,   o,   o,   o,  71,   o,   o,   o,   o,  64,  84,   o,   o,  91,   o,   o,   o, 103, 112,   o,   o,   o,   o,   o, 120, 132,   o,   o,   o, 141,   o, 149,   o,   o, 166,   o,   o, 176,   o,   o,   o, 185, 197,   o, 205, 204,   o,   o },
   {    o,   o,   o,   5,   o,   o,   o,  25,  34,  35,  36,  37,  46,   o,   o,   o,   o,   o,  72,  54,  55,  56,  57,  63,  83,   o,   o,   o,  92,   o,   o, 102, 111,   o,   o,   o,   o,   o, 121, 131,   o,   o,   o, 142,   o, 150,   o,   o, 165,   o,   o, 175,   o,   o, 186,   o, 196, 206,   o,   o,   o,   o },
   {    o,   o,   o,   4,   o,   o,   o,  24,   o,   o,   o,   o,  45,   o,   o,   o,   o,   o,  73,   o,   o,   o,   o,  62,  82,   o,   o,   o,  93,   o,   o, 101, 110,   o,   o,   o,   o,   o, 122, 130, 145, 144, 143,   o,   o, 151,   o,   o,   o, 164,   o, 174,   o, 187,   o,   o, 195,   o, 207,   o,   o,   o },
   {    o,   o,   o,   3,   o,   o,   o,  23,   o,   o,   o,   o,  44,   o,   o,   o,   o,   o,  74,   o,   o,   o,   o,  61,  81,   o,   o,   o,   o,  94,   o, 100,   o, 109,   o,   o,   o, 123,   o, 129,   o,   o,   o,   o,   o, 152,   o,   o,   o, 163,   o, 173,   o,   o, 188,   o, 194,   o,   o, 208,   o,   o },
   {    o,   o,   o,   2,   o,   o,   o,  22,   o,   o,   o,   o,   o,  43,   o,   o,   o,   o,  75,   o,   o,   o,   o,  60,  80,   o,   o,   o,   o,  95,   o,  99,   o, 108,   o,   o,   o, 124,   o, 128,   o,   o,   o,   o, 153, 156, 157, 158, 159,   o, 162, 172,   o,   o,   o, 189, 193,   o,   o,   o, 209,   o },
   {    o,   o,   o,   1,   o,   o,   o,  21,   o,   o,   o,   o,   o,  42,  41,  40,  39,  38,  76,   o,   o,   o,   o,  59,  79,   o,   o,   o,   o,   o,  96,  98,   o,   o, 107,   o, 125,   o,   o, 127,   o,   o,   o,   o, 154,   o,   o,   o,   o,   o, 161, 171,   o,   o,   o, 190, 192,   o,   o,   o, 210,   o },
   {    o,   o,   o,   0,   o,   o,   o,  20,  19,  18,  17,  16,   o,   o,   o,   o,   o,   o,  77,   o,   o,   o,   o,  58,  78,   o,   o,   o,   o,   o,   o,  97,   o,   o,   o, 106,   o,   o,   o, 126,   o,   o,   o,   o, 155,   o,   o,   o,   o,   o, 160, 170,   o,   o,   o,   o, 191,   o,   o,   o,   o, 211 },
//    0    1    2    3    4    5    6    0    1    2    3    4    0    1    2    3    4    5    0    1    2    3    4    5    0    1    2    3    4    5    6    7    0    1    2    3    4    5    6    0    1    2    3    4    0    1    2    3    4    5    6    0    1    2    3    4    0    1    2    3    4    5
};