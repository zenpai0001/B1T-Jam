#include "globals.h"
#include "map.h"
#include <atomic>
#include <cstdint>
#include <cstdlib>
#include <raylib.h>

Color *tile_table[16];
Color *bg_table[16];

bool regular_color;

namespace map_gen {

enum tiles { TILE_FLOOR = 0, TILE_WALL, TILE_DOOR, TILE_COUNT };

static Rectangle tile_location[map_gen::TILE_COUNT] = {
    [map_gen::TILE_FLOOR] = {0.0f, 0.0f, 16.0f, 16.0f},
    [map_gen::TILE_WALL] = {16.0f, 0.0f, 16.0f, 16.0f},
    [map_gen::TILE_DOOR] = {48.0f, 0.0f, 16.0f, 16.0f},
};

/*
This is entirely responsible for the map generation. A series of
numbers. Might be using perlin noise somehow. This looks like a coding
warcrime. Not gonna lie.
*/

void seed(unsigned int init_state) {
  init_state = (init_state == 0) ? 1 : init_state;
}

unsigned int gen_seed(unsigned int seed) {
  seed ^= seed << 13;
  seed ^= seed << 17;
  seed ^= seed << 5;
  return seed;
}

void draw_terrain() {

  buffers::display::atlas[4].filepath = "tileset.png";
  LoadImage(buffers::display::atlas[4].filepath);
  buffers::display::atlas[4].texture =
      LoadTextureFromImage(buffers::display::atlas[4].img);
  BeginMode2D(player::player_cam);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {

      // Generate random numbers in all 4 chunks.
      unsigned int chunk_seed =
          (i * 73856093) ^ (j * 19349663) ^ (i * 839492791) ^ (j * 3152707);
      seed(chunk_seed);
      map_chunk_variant0[i][j] = (float)gen_seed(chunk_seed);
      map_chunk_variant1[i][j] = (float)gen_seed(chunk_seed);
      map_chunk_variant2[i][j] = (float)gen_seed(chunk_seed);
      map_chunk_variant3[i][j] = (float)gen_seed(chunk_seed);

      // I gave up trying perlin noise, so I had to make something work.
      if (map_chunk_variant0[i][j] || map_chunk_variant1[i][j] ||
          map_chunk_variant2[i][j] || map_chunk_variant3[i][j] < 0.10f) {
        ImageDraw(&buffers::display::atlas[4].img,
                  buffers::display::atlas[4].img,
                  tile_location[map_gen::TILE_FLOOR],
                  tile_location[map_gen::TILE_WALL], WHITE);
        UpdateTexture(buffers::display::atlas[4].texture,
                      buffers::display::atlas[4].img.data);
      }

      if (map_chunk_variant0[i][j] || map_chunk_variant1[i][j] ||
          map_chunk_variant2[i][j] || map_chunk_variant3[i][j] > 0.10f) {

        ImageDraw(&buffers::display::atlas[4].img,
                  buffers::display::atlas[4].img,
                  tile_location[map_gen::TILE_WALL],
                  tile_location[map_gen::TILE_DOOR], WHITE);
        UpdateTextureRec(buffers::display::atlas[4].texture,
                         get_slice(0, 16, 16),
                         buffers::display::atlas[4].img.data);
      }

      if (map_chunk_variant0[i][j] || map_chunk_variant1[i][j] ||
          map_chunk_variant2[i][j] || map_chunk_variant3[i][j] == 0.10f) {
        ImageDraw(&buffers::display::atlas[4].img,
                  buffers::display::atlas[4].img,
                  tile_location[map_gen::TILE_WALL],
                  tile_location[map_gen::TILE_DOOR], WHITE);
        UpdateTextureRec(buffers::display::atlas[4].texture,
                         get_slice(0, 16, 16),
                         buffers::display::atlas[4].img.data);
      }

      if (map_chunk_variant0[i][j] && map_chunk_variant1[i][j] ||
          map_chunk_variant2[i][j] || map_chunk_variant3[i][j] == 0.10f) {
        UpdateTextureRec(buffers::display::atlas[2].texture,
                         get_slice(0, 16, 16),
                         buffers::display::atlas[2].img.data);
      }
    }
  }
  EndMode2D();
}
Rectangle slice_texture(Rectangle slice) {
  slice = {0, 0, 16, 16};
  ImageCopy(buffers::display::atlas[4].img);
  ImageCrop(&buffers::display::atlas[4].img, slice);

  return slice;
}
Rectangle get_slice(int tile_id, int tile_size, int columns) {
  int col = tile_id % columns;
  int row = tile_id / columns;
  return (Rectangle){(float)(col * tile_size), (float)(row * tile_size),
                     (float)tile_size, (float)tile_size};
}

} // namespace map_gen
