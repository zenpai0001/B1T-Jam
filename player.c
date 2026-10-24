#include "game.h"
#include <raylib.h>

// Macros to dictate player movement
#define SPEED 50.0f
#define DELTA_TIME GetFrameTime()

player global = {20.0f, 20.0f};

// Function that checks for button presses and updates position.
void move_player() {
  if (IsKeyDown(KEY_RIGHT))
    global.x += SPEED * DELTA_TIME;
  if (IsKeyDown(KEY_LEFT))
    global.x -= SPEED * DELTA_TIME;
  if (IsKeyDown(KEY_DOWN))
    global.y += SPEED * DELTA_TIME;
  if (IsKeyDown(KEY_UP))
    global.y -= SPEED * DELTA_TIME;
}
