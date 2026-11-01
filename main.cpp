#include "globals.h"
#include <raylib.h>

void test() {}

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
    move_player();
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Player's field of view.
    BeginMode2D(player_cam);
    DrawCircleV(player_position, 3.0f, GREEN);
    EndMode2D();

    // Random object not in player's camera.
    DrawCircle(100, 100, 15, BLUE);
    DrawText("Press [ESC] to quit", 10, 10, 20, DARKGRAY);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
