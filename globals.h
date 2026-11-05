#pragma once

#include <raylib.h>
#include <stdint.h>

#define MAX_BUFFERS 16
#define MAX_ENTITIES 1024

const int width = 640;
const int height = 360;

struct buffer_table {
  RenderTexture2D buffers;
  int key;
};

// Macros to dictate player movement
#define SPEED 50.0f
#define DELTA_TIME GetFrameTime()

enum bindings { MOVEMENT = 1 << 0, ACTION = 1 << 1, PAUSE = 3 };
/*
Keys struct features a tagged union for keybindings.
*/
struct keys {
  // bindings
  enum bindings key_bindings;
  union {
    // Takes a single integer at a time.
    int key;
  };
};

enum entity_action {
  DAMAGE_PLAYER = 1 << 0,
  COLLIDE = 1 << 1,
  DESTROYED = 1 << 2,
  DROP_LOOT = 1 << 3
};

struct entities {
  entity_action entity_act;
  union {
    Rectangle rec[2];
    uint32_t id;
  };
};

namespace audio {

typedef enum {
  MUSIC_PLAYING,
  MUSIC_PAUSED,
  MUSIC_LOOPING,
  SOUND_FX,
} music_state;

} // namespace audio
