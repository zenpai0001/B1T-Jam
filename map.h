#pragma once

/*This is the array I'm building*/

#include <cmath>
#include <raylib.h>
#define CHUNK_X 16
#define CHUNK_Y 16

#include <cstdint>

// Forward declare the map_chunks here.
extern float map_chunk_variant0[CHUNK_X][CHUNK_Y];
extern float map_chunk_variant1[CHUNK_X][CHUNK_Y];
extern float map_chunk_variant2[CHUNK_X][CHUNK_Y];
extern float map_chunk_variant3[CHUNK_X][CHUNK_Y];

// Have this here if I need it.
struct texture_atlas {
  Image img;
  Texture2D texture;
};

namespace map_gen {

enum tile_type {};

static Rectangle tile_locations[4];

void draw_terrain();
void seed(unsigned int init_state);
unsigned int gen_seed(unsigned int seed);
Rectangle slice_texture(Rectangle slice);
Rectangle get_slice(int tile_id, int tile_size, int columns);
} // namespace map_gen
