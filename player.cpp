#include "globals.h"
#include <raylib.h>

#define KEY_MAX_SIZE 20

namespace player_manager {
class player {
public:
  // Forward declaration for keys.
  keys key_array[6] = {
      [0] = {.key_bindings = MOVEMENT, .key = KEY_W},
      [1] = {.key_bindings = MOVEMENT, .key = KEY_A},
      [2] = {.key_bindings = MOVEMENT, .key = KEY_S},
      [3] = {.key_bindings = MOVEMENT, .key = KEY_D},
      [4] = {.key_bindings = MOVEMENT, .key = KEY_KP_SUBTRACT},
      [5] = {.key_bindings = MOVEMENT, .key = KEY_KP_ADD},
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
}; // class player
} // namespace player_manager
