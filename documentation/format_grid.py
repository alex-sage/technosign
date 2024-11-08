#!/usr/bin/python3
""" Formats the grid in the .csv (exported from the .ods) into C code.

The double array is a map from a logical grid location to the index in
the LED color array for the LED strip. Thus, typical usage would go:

void set_grid(int x, int y, rgb color) {
  int index = LETTER_GRID[y][x];
  colors[index] = color;
}

* Notes on memory usage

The Atmega 328 MC has limited RAM, at only 2kB. This grid takes up 10 * 62 = 620 bytes,
or 30% of RAM. However, expressing it in other ways would also be expensive: E.g. one
could implement a look-up table, with x/y as key and index as value. However, it would
require 2 bytes for the key, and one byte for the value, which give 3 * 211 = 633 bytes.
In other words, it would take more space than the grid. Similarly, a switch method which
implements such a lookup would take the same amount, because it would have to express
each of the 3 bytes for each LED separately.

If this becomes a problem, other approaches could be to add external RAM, but I'm unsure
of the processing cost, or go with a bigger boards with more RAM. E.g the ATmega2560 has
8kb RAM, and the Arduino Due (with a 32-bit ARM chip) has 96kB.

* Usage of this script:
  ./format_grid.py technopark_grid.csv > technopark_grid.h
"""


import sys

fname = sys.argv[1]

print("#pragma once")
print("")
print("const byte GRID_ROWS = 10;")
print("const byte GRID_COLS = 62;")
print("const byte LETTER_GRID[GRID_ROWS][GRID_COLS] = {")
print("const byte o = -1;")

r = 0 
for line in open(fname):
  split = line.strip().split(",")
  fmt = ["%4s" % e for e in split[1:63]]
  
  if r in [0, 1, 12]:
    print("//", " ".join(fmt))
  else:
    print("   {",  ",".join(fmt), "},")

  r += 1

print("};")
