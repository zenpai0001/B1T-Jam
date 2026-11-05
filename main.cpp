#include "globals.h"
#include <raylib.h>

namespace buffers::display {
void gameplay_buffer();
}

int main() {
  // I have no idea why this works.
  //  Removing this won't make the ball move at all. So weird.

  // Testing player position and camera.
  Vector2 player_position = {(float)width / 2, (float)height / 2};

  Camera2D player_cam = {.offset = {(float)width / 2, (float)height / 2},
                         .target = player_position,
                         .rotation = 0.0f,
                         .zoom = 1.0f};

  SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
  InitWindow(800, 800, "Game");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    InitAudioDevice();
    buffers::display::gameplay_buffer();
  }
  CloseWindow();

  return 0;
}
