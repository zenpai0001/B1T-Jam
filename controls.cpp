#include "globals.h"
#include <iterator>
#include <raylib.h>

namespace controls {

static enum bindings binding;

// Scoping globally prevents W-shadow.
buffer_table buffer[MAX_BUFFERS] = {
    [0] =
        {
            .buffers = LoadRenderTexture(width, height),
            .key = KEY_P,
        },
    [1] = {.buffers = LoadRenderTexture(width, height), .key = KEY_NUM_LOCK},
    [2] = {.buffers = LoadRenderTexture(width, height)}};

Rectangle src;

void main_menu() {

  if (IsKeyPressed(controls::buffer[0].key)) {
    binding = PAUSE;
  }
  if (IsKeyPressed(controls::buffer[1].key)) {
    binding = ACTION;
  }
  if (IsKeyPressed(controls::buffer[2].key)) {
    binding = MAIN;
  }

  BeginDrawing();

  ClearBackground(BLACK);
  // Placeholder text
  DrawText("MAIN MENU", 0, 0, 20, ORANGE);
  BeginTextureMode(controls::buffer[0].buffers);

  ClearBackground(BLACK);
  // draw stuff here
  DrawText("PAUSED", 0, 0, 20, ORANGE);
  // draw stuff here
  EndTextureMode();

  BeginTextureMode(controls::buffer[2].buffers);
  ClearBackground(BLACK);
  // draw stuff here
  DrawText("MAIN MENU", 0, 0, 20, ORANGE);
  // draw stuff here
  EndTextureMode();

  // This function will handle its texturemode
  buffers::display::gameplay_buffer();

  if (binding == PAUSE) {
    DrawTexture(controls::buffer[0].buffers.texture, 0, 0, WHITE);
    ClearBackground(BLACK);
  }
  if (binding == ACTION) {
    DrawTexture(controls::buffer[1].buffers.texture, 0, 0, WHITE);
    ClearBackground(BLACK);
  }
  if (binding == MAIN) {
    DrawTexture(controls::buffer[2].buffers.texture, 0, 0, WHITE);
  }
  EndDrawing();
}
} // namespace controls
namespace buffers::display {

audio_table music_system[MAX_BUFFERS] = {
    [0] = {.filepath = "shrine_stealth.mp3"},
    [1] = {.filepath = "shrine_stealth_2.mp3"},
    [2] = {.filepath = "shrine_heist_theme"},
    [3] = {.filepath = "zombie_horde.mp3"},
    [4] = {.filepath = "zombie_horde_2.mp3"},
};

audio_table sound_system[MAX_BUFFERS] = {
    [0] = {.filepath = "Shield.wav"},
    [1] = {.filepath = "crossbow.wav"},
    [2] = {.filepath = "death sfx.wav"},
    [3] = {.filepath = "ninja star.wav"},
    [4] = {.filepath = "shrine breaking.wav"},
    [5] = {.filepath = "shrine broken.wav"},
    [6] = {.filepath = "Steel shrine charge.wav"},
    [7] = {.filepath = "Steel shrine charge v2.wav"}};

texture_atlas atlas[MAX_BUFFERS] = {
    [0] = {.filepath = "shrine_thief.png"},
    [1] = {.filepath = "shrine_thief_2.png"},
    [2] = {.filepath = "tileset.png"},
    [3] = {.filepath = "enemy1.png"},
    [4] = {.filepath = "enemy2.png"},
};

void load_atlas() {
  for (int i = 0; i < 5; ++i) {
    atlas[i].img = LoadImage(atlas[i].filepath);
    atlas[i].texture = LoadTextureFromImage(atlas[i].img);
  }
}
void load_music() {
  for (int i = 0; i < 7; ++i) {
    music_system[i].sound = LoadSound(music_system[i].filepath);
  }
  for (int i = 0; i < 13; ++i) {
    sound_system[i].music = LoadMusicStream(sound_system[i].filepath);
  }
}

void gameplay_buffer() {
  BeginTextureMode(controls::buffer[1].buffers);
  ClearBackground(BLACK);
  DrawText("GAMEPLAY", 0, 0, 20, ORANGE);
  EndTextureMode();
}

} // namespace buffers::display
