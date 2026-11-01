#pragma once

#include "globals.h"
#include <raylib.h>

namespace controls {

enum bindings binding;

// TODO: Setup tables for varying buffers.
buffer_table buffer[MAX_BUFFERS] = {
    [0] = {.key = KEY_P,
           .text = "PAUSED",
           .buffers = {.depth = {.width = 800, .height = 400}}},
};

void handle_buffer() {

  for (int i = 0; i < MAX_BUFFERS; ++i) {
    if (binding == PAUSE && IsKeyPressed(buffer[i].key)) {
      switch (buffer[i].key) {
      case KEY_P:
        // TODO: Pause buffer
        BeginTextureMode(buffer[0].buffers);

        BeginDrawing();
        DrawTexture(buffer[0].buffers.texture, 200, 200,
                    (Color){255, 255, 255, 0});
        EndDrawing();
        EndTextureMode();
        break;
      case KEY_NUM_LOCK:
        // Mutate bindings
        binding = ACTION;

        if (binding == ACTION && KEY_NUM_LOCK) {
          // Undo binding upon num_lock being pressed again.
          binding = PAUSE;
        }
        break;
      }
    }
  }
}
} // namespace controls
