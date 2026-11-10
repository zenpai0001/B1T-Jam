#include "globals.h"
#include <raylib.h>

namespace audio {

void init_audio() {
  InitAudioDevice();
  SetMasterVolume(0.5f);

  start_music(buffers::display::music_system[2].filepath, 2, false);
}
void close_audio() {
  CloseAudioDevice();
  for (int i = 0; i < 10; ++i) {
    UnloadSound(buffers::display::sound_system[i].sound);
  }
}
void update_music() {
  for (int i = 0; i < 10; ++i) {
    if (buffers::display::music_system[i].music.frameCount > 0) {
      UpdateMusicStream(buffers::display::music_system[i].music);
    }
  }
}
void update_sound() {}

void start_music(const char *filepath, int index, bool _is_looping) {
  for (int i = 0; i < 10; ++i) {
    close_music(i);
  }

  buffers::display::music_system[index].music = LoadMusicStream(filepath);
  buffers::display::music_system[index].music.looping = _is_looping;
  PlayMusicStream(buffers::display::music_system[index].music);
}

void start_sound(const char *filepath, int index) {
  buffers::display::sound_system[index].sound = LoadSound(filepath);
  buffers::display::sound_system[index].sound.frameCount = 600;
}
void close_music(int index) {
  if (buffers::display::music_system[index].music.frameCount > 0) {
    StopMusicStream(buffers::display::music_system[index].music);
    UnloadMusicStream(buffers::display::music_system[index].music);
    buffers::display::music_system[index].music.frameCount = 0;
  }
}

} // namespace audio
