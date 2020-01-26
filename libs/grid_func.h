#pragma once

#include "common.h"
#include "grid.h"

void set_grid(int x, int y, rgb_color color) {
  int index = LETTER_GRID[y][x];
  if (index != o) {
    leds[index] = color;
  }
}

void grid_swipe(rgb_color color, int delayMs,
		int start1, int end1,
		int start2, int end2, bool vertical) {

  int dir1 = end1 - start1;
  int dir2 = end2 - start2;
  int x, y, t;
  
  for(int v = start1; v < end1; v++) {
    for(int w = start2; w < end2; w++) {
      x = start1 + v * dir1;
      y = start2 + w * dir2;
      
      if (vertical) {
	t = x;
	x = y;
	y = t;
      }

      set_grid(x, y, color);
    }
    write();
    delay(delayMs);
  }
}

void grid_swipe_right(rgb_color color, int delayMs) {
  grid_swipe(color, delayMs, 0, GRID_COLS, 0, GRID_ROWS, false);
}

void grid_swipe_left(rgb_color color, int delayMs) {
  grid_swipe(color, delayMs, GRID_COLS, 0, 0, GRID_ROWS, false);
}

void grid_swipe_down(rgb_color color, int delayMs) {
  grid_swipe(color, delayMs, 0, GRID_ROWS, 0, GRID_COLS, true);
}

void grid_swipe_up(rgb_color color, int delayMs) {
  grid_swipe(color, delayMs, GRID_ROWS, 0, 0, GRID_COLS, true);
}
