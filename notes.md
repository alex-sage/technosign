
# 2024-11-08

ESP32: Just trying stuff out for now.

# 2024-11-08

The full sign; all letters, all 211 LEDs work again.

It seems like there is a short somewhere near the H or N. When the cables and letters are moved around there, there is a cut or short. Also, while touching the sign, there's often a small shock. The cables are touching the sign somewhere.

To debug, we have a few useful tools:

- [technopark_grid_index.png](documentation/technopark_grid_index.png): Shows the layout of the LEDs and their index.
- `set_led`: This takes an int on the terminal and blinks the corresponding LED index (the Arduino has to be connected to the computer)
- `test_letters`: Has a hardcoded `LED_COUNT` and cycles the LEDs up to that point. Can be useful when something only works half-way.
- `index_letters`: Once everything works, this cycles the whole sign in different colors.

