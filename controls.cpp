#include "globals.h"
#include <raylib.h>

namespace controls {

enum bindings binding;

// Scoping globally prevents W-shadow.
buffer_table buffer[MAX_BUFFERS] = {
    [0] = {.buffers = LoadRenderTexture(-width, -height), .key = KEY_P},
    [1] = {.buffers = LoadRenderTexture(-width, -height), .key = KEY_ENTER},
};

void pause_menu() {
  BeginTextureMode(buffer[0].buffers);

  BeginDrawing();
  DrawTexture(buffer[0].buffers.texture, 0, 0, GRAY);
  DrawText("PAUSED", GetScreenWidth() / 2, GetScreenHeight() / 2, 200, ORANGE);
  EndDrawing();
  EndTextureMode();
}

void handle_buffer() {
  for (int i = 0; i < MAX_BUFFERS; ++i) {
    if (binding == PAUSE && IsKeyPressed(buffer[i].key)) {
      switch (buffer[i].key) {
      case KEY_P:
        pause_menu();
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

namespace buffers::display {
enum audio_files { WAV, MP3, OGG };

AudioStream stream_table[MAX_BUFFERS] = {
    [0] = {.sampleRate = 44100, .sampleSize = 32, .channels = 2},

};
Music sound_table[MAX_BUFFERS] = {
    [0] = {.stream = stream_table[0], .frameCount = 3600, .looping = true},

};

Texture2D player_sprite = LoadTexture("shrine_thief.png");

void gameplay_buffer() {

  /*
  Draw to buffer, load audio stream,
  play music that loops, and move the player around.
  */

  LoadAudioStream(stream_table[0].sampleRate, stream_table[0].sampleSize,
                  stream_table[0].channels);
  LoadMusicStream("shrine_stealth.mp3");
  PlayMusicStream(sound_table[0]);

  while (!WindowShouldClose()) {
    UpdateMusicStream(sound_table[0]);

    BeginDrawing();
    BeginTextureMode(controls::buffer[1].buffers);
    ClearBackground(BLACK);

    BeginScissorMode(80, 0, 100, 10);
    DrawTexture(player_sprite, 50, 50, WHITE);
    EndScissorMode();

    EndTextureMode();
    EndDrawing();
  }
  StopMusicStream(sound_table[0]);
  UnloadMusicStream(sound_table[0]);
  UnloadAudioStream(stream_table[0]);
  UnloadTexture(player_sprite);
}

} // namespace buffers::display
