#include "globals.h"
#include "map.h"
#include <raylib.h>

void init_buffers() {

  for (int i = 0; i < MAX_BUFFERS; ++i) {
    controls::buffer[i].buffers =
        LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
  }
  controls::buffer[0].key = KEY_P;
  controls::buffer[1].key = KEY_TAB;
  controls::buffer[2].key = KEY_Q;
}

void init_assets() {}

int main() {
  // I have no idea why this works.
  //  Removing this won't make the ball move at all. So weird.

  SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
  buffers::display::load_atlas();
  InitWindow(800, 800, "Game");
  // Load the atlas shortly after init window.
  SetTargetFPS(60);

  init_buffers();

  buffers::display::music_system[0].filepath = "shrine_stealth.mp3";
  while (!WindowShouldClose()) {
    controls::main_menu();
    audio::start_music(buffers::display::music_system[0].filepath, 0, true);
  }
  UnloadRenderTexture(controls::buffer[0].buffers);
  CloseWindow();

  return 0;
}
