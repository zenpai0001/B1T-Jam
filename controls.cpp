#include "globals.h"
#include <raylib.h>

namespace controls {

enum bindings binding;

// Scoping globally prevents W-shadow.
buffer_table buffer[MAX_BUFFERS] = {
    [0] =
        {
            .buffers = LoadRenderTexture(width, height),
            .key = KEY_P,
        },
    [1] = {.buffers = LoadRenderTexture(width, height), .key = KEY_NUM_LOCK},
};

Rectangle src;

void pause_menu() {
  binding = PAUSE;

  if (IsKeyPressed(controls::buffer[0].key)) {
    binding = ACTION;
  }
  BeginDrawing();
  ClearBackground(BLACK);

  BeginTextureMode(controls::buffer[0].buffers);
  ClearBackground(GRAY);
  DrawText("PAUSED", 10, 10, 20, ORANGE);
  EndTextureMode();

  src = {0, 0, (float)controls::buffer[0].buffers.texture.width,
         (float)-controls::buffer[0].buffers.texture.height};
  DrawTexture(buffer[0].buffers.texture, 0, 0, WHITE);
  DrawTextureRec(controls::buffer[0].buffers.texture, src, Vector2{0, 0},
                 WHITE);

  if (binding == ACTION) {
    ClearBackground(BLACK);
    src = {0, 0, (float)controls::buffer[1].buffers.texture.width,
           (float)-controls::buffer[1].buffers.texture.height};

    buffers::display::gameplay_buffer();
    DrawTexture(controls::buffer[1].buffers.texture, 0, 0, WHITE);
    DrawTextureRec(controls::buffer[1].buffers.texture, src, Vector2{0, 0},
                   WHITE);
  }
  EndDrawing();
}

} // namespace controls

namespace buffers::display {

AudioStream stream_table[MAX_BUFFERS] = {
    [0] = {.sampleRate = 44100, .sampleSize = 32, .channels = 2},

};
Music sound_table[MAX_BUFFERS] = {
    [0] = {.stream = stream_table[0], .frameCount = 3600, .looping = true},

};

Texture2D player_sprite = LoadTexture("shrine_thief.png");

// TODO: Fix this buffer from flickering and crashing the game.
void gameplay_buffer() {

  /*
  Draw to buffer, load audio stream,
  play music that loops, and move the player around.
  */

  // LoadAudioStream(stream_table[0].sampleRate, stream_table[0].sampleSize,
  //                 stream_table[0].channels);
  // LoadMusicStream("shrine_stealth.mp3");
  // PlayMusicStream(sound_table[0]);

  // UpdateMusicStream(sound_table[0]);
  BeginDrawing();
  ClearBackground(BLACK);

  BeginTextureMode(controls::buffer[1].buffers);
  ClearBackground(BLACK);

  DrawText("GAMEPLAY", 0, 0, 20, ORANGE);
  EndTextureMode();
  EndDrawing();

  DrawTexture(controls::buffer[1].buffers.texture, 0, 0, WHITE);
  if (IsKeyPressed(controls::buffer[0].key)) {
    controls::pause_menu();
  }
  // StopMusicStream(sound_table[0]);
  // UnloadMusicStream(sound_table[0]);
  // UnloadAudioStream(stream_table[0]);
  // UnloadTexture(player_sprite);
}

} // namespace buffers::display
