#include "globals.h"
#include <raylib.h>

void init_buffers() {

  for (int i = 0; i < MAX_BUFFERS; ++i) {
    controls::buffer[i].buffers =
        LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
  }
  controls::buffer[0].key = KEY_P;
  controls::buffer[1].key = KEY_NUM_LOCK;
}

void init_assets() {
  buffers::display::player_sprite = LoadTexture("shrine_thief.png");

  buffers::display::stream_table[0] = {
      .sampleRate = 44100, .sampleSize = 32, .channels = 2};
  buffers::display::sound_table[0] = {.stream =
                                          buffers::display::stream_table[0],
                                      .frameCount = 3600,
                                      .looping = true};
  PlayMusicStream(buffers::display::sound_table[0]);
}

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

  init_assets();
  init_buffers();

  while (!WindowShouldClose()) {
    UpdateMusicStream(buffers::display::sound_table[0]);

    controls::pause_menu();
  }
  CloseWindow();

  return 0;
}
