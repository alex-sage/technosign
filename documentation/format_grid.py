#!/usr/bin/python3
""" Formats the grid in the .csv (exported from the .ods) into C code.

The dobble array is a map from a logical grid location to the index in
the LED color array for the LED strip. Thus, typical usage would go:

void set_grid(int x, int y, rgb color) {
  int index = LETTER_GRID[y][x];
  colors[index] = color;
}

Usage of this script:
  ./format_grid.py technopark_grid.csv > technopark_grid.h
"""


import sys

fname = sys.argv[1]

print("const uint16_t GRID_ROWS = 10;")
print("const uint16_t GRID_COLS = 61;")
print("const uint16_t LETTER_GRID[GRID_ROWS][GRID_COLS] = {")
print("const uint16_t o = -1;")

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
