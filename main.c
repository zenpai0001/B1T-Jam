#include "game.h"
#include <raylib.h>

int main() {
  InitWindow(800, 800, "Game");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    move_player();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("[Press ESC to close]", 10, 10, 20, GRAY);
    DrawCircle((int)global.x, (int)global.y, 5.0f, GREEN);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
