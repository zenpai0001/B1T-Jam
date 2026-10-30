#include "controls.h"
#include "game.h"

#include <raylib.h>

int main() {
  // I have no idea why this works.
  //  Removing this won't make the ball move at all. So weird.
  const int width = 800;
  const int height = 400;

  // Testing player position and camera.
  player_position = (Vector2){(float)width / 2, (float)height / 2};

  player_cam = (Camera2D){.offset = {(float)width / 2, (float)height / 2},
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

    // TODO: Make a special function to test stuff.
    handle_buffer();
  }
  CloseWindow();
  return 0;
}
