#pragma once

#include <raylib.h>
#include <stdint.h>

#define MAX_BUFFERS 16
#define MAX_ENTITIES 1024

const int width = 640;
const int height = 360;

typedef struct {
  RenderTexture2D buffers;
  int key;
  const char *text;
} buffer_table;

// Macros to dictate player movement
#define SPEED 50.0f
#define DELTA_TIME GetFrameTime()

enum bindings { MOVEMENT = 1 << 0, ACTION = 1 << 1, PAUSE = 3 };
/*
Keys struct features a tagged union for keybindings.
*/
typedef struct {
  // bindings
  enum bindings key_bindings;
  union {
    // Takes a single integer at a time.
    int key;
  };
} keys;

typedef enum {
  DAMAGE_PLAYER = 1 << 0,
  COLLIDE = 1 << 1,
  DESTROYED = 1 << 2,
  DROP_LOOT = 1 << 3
} entity_action;

typedef struct {
  entity_action entity_action;
  union {
    struct {
      Rectangle rec[2];
      uint32_t id;
    } collision;
  };
} entities;

namespace audio {

typedef struct {
  AudioStream stream;
  Music playlist[10];
} audio_manager;

typedef enum {
  MUSIC_PLAYING,
  MUSIC_PAUSED,
  MUSIC_LOOPING,
} music_state;

} // namespace audio
