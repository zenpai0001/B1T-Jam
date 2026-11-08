#include "globals.h"
#include "map.h"
#include <cstdint>
#include <cstdlib>
#include <raylib.h>

Color *tile_table[16];
Color *bg_table[16];

bool regular_color;

namespace map_gen {
unsigned int num_state;

/*
This is entirely responsible for the map generation. A series of
numbers. Might be using perlin noise somehow. This looks like a coding
warcrime. Not gonna lie.
*/

void seed(unsigned int init_state) {
  init_state = (init_state == 0) ? 1 : init_state;
}

unsigned int gen_seed() {
  num_state ^= num_state << 13;
  num_state ^= num_state << 17;
  num_state ^= num_state << 5;
  return num_state;
}

void draw_terrain(unsigned int chunk_seed) {

  texture_atlas atlas;

  for (int i = 0; i < CHUNK_X; ++i) {
    for (int j = 0; j < CHUNK_Y; ++j) {

      // Generate random numbers in all 4 chunks.
      chunk_seed =
          (i * 73856093) ^ (j * 19349663) ^ (i * 839492791) ^ (j * 3152707);
      seed(chunk_seed);
      map_chunk_variant0[i][j] = (float)gen_seed();
      map_chunk_variant1[i][j] = (float)gen_seed();
      map_chunk_variant2[i][j] = (float)gen_seed();
      map_chunk_variant3[i][j] = (float)gen_seed();

      atlas.img = GenImagePerlinNoise(16, 16, 0, 0, 4.0f);
    }
  }
}

} // namespace map_gen
