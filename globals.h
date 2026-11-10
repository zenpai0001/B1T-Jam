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

extern buffer_table buffer[MAX_BUFFERS];

// Macros to dictate player movement
#define SPEED 50.0f
#define DELTA_TIME GetFrameTime()

enum bindings { MOVEMENT = 1 << 0, ACTION = 1 << 1, PAUSE = 3, MAIN = 4 };
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

// Forward declare functions and extern here.
//  Prevents hack fixing missing symbols.

// player.cpp
namespace player {
extern keys key_array[6];

void move_player();

extern Vector2 player_position;
extern Camera2D player_cam;

} // namespace player

namespace controls {
extern buffer_table buffer[MAX_BUFFERS];

void main_menu();

} // namespace controls
namespace buffers::display {
enum audio_files {};

struct audio_table {
  const char *filepath;
  Music music;
  Sound sound;
};

struct texture_atlas {
  const char *filepath;
  Image img;
  Texture2D texture;
};

extern audio_table music_system[MAX_BUFFERS];
extern audio_table sound_system[MAX_BUFFERS];
extern texture_atlas atlas[MAX_BUFFERS];
extern Rectangle slice[MAX_BUFFERS];
void load_atlas();
void load_music();
void gameplay_buffer();
} // namespace buffers::display

extern Texture2D player_sprite;
extern Rectangle *src;
extern Rectangle dest;

namespace audio {

enum music_state {
  MUSIC_PLAYING,
  MUSIC_PAUSED,
  MUSIC_LOOPING,
  SOUND_FX,
};

enum audio_files { OGG, WAV, MP3 };

void init_audio();
void close_audio();
void update_music();
void update_sound();

void start_music(const char *filepath, int index, bool _is_looping);
void start_sound(const char *filepath);

void close_music(int index);

} // namespace audio
