<<<<<<< HEAD
# 2024-12-17

Final handover. The sign is on top of the cupboards in the Dev room, running the ESP32 board.

We had to cut out one LED on the O, because it was broken. This was reflected in the letter indexes in sign.yml of this MR, however, documentation, C++ code has not been updated.
=======
# 2024-11-21

Freecad models for 3D printing the brackets to hang up the power supply and MC boards.
>>>>>>> ccb4f2ec67bafa8d346372fb47ac6c4701b7f68d

# 2024-11-11

Hooked up the ESP32 to the sign, and got a number of things to work. [See details here](esp32/notes.md).

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

