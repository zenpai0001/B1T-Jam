#include "globals.h"
#include <raylib.h>

#define KEY_MAX_SIZE 20

// Forward declaration for keys.
keys key_array[6] = {
    [0] = {.key = KEY_W, .key_bindings = MOVEMENT},
    [1] = {.key = KEY_A, .key_bindings = MOVEMENT},
    [2] = {.key = KEY_S, .key_bindings = MOVEMENT},
    [3] = {.key = KEY_D, .key_bindings = MOVEMENT},
    [4] = {.key = KEY_KP_SUBTRACT, .key_bindings = MOVEMENT},
    [5] = {.key = KEY_KP_ADD, .key_bindings = MOVEMENT},
};

// Testing player position and camera.
Vector2 player_position = {(float)width / 2, (float)height / 2};

Camera2D player_cam = {.offset = {(float)width / 2, (float)height / 2},
                       .target = player_position,
                       .rotation = 0.0f,
                       .zoom = 1.0f};

// Function that checks for key presses and updates position.
void move_player() {

  for (int i = 0; i < 6; ++i) {
    if (IsKeyDown(key_array[i].key)) {
      switch (key_array[i].key) {
      case KEY_W:
        player_position.y -= SPEED * DELTA_TIME;
        break;
      case KEY_A:
        player_position.x -= SPEED * DELTA_TIME;
        break;
      case KEY_S:
        player_position.y += SPEED * DELTA_TIME;
        break;
      case KEY_D:
        player_position.x += SPEED * DELTA_TIME;
        break;
      }
      if (IsKeyPressed(key_array[i].key)) {
        switch (key_array[i].key) {
        case KEY_KP_SUBTRACT:
          player_cam.zoom -= 0.5f;
          if (player_cam.zoom < 0.5f) {
            player_cam.zoom = 1.0f;
          }
          break;
        case KEY_KP_ADD:
          player_cam.zoom += 0.5f;
          if (player_cam.zoom > 10.0f) {
            player_cam.zoom = 2.0f;
          }
          break;
        }
      }
    }
  }
}
