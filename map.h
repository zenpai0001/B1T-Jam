#pragma once

/*This is the array I'm building*/

#include <raylib.h>
#define CHUNK_X 16
#define CHUNK_Y 16

#include <cstdint>

// Forward declare the map_chunks here.
extern uint16_t map_chunk_variant0[CHUNK_X][CHUNK_Y];
extern uint16_t map_chunk_variant1[CHUNK_X][CHUNK_Y];
extern uint16_t map_chunk_variant2[CHUNK_X][CHUNK_Y];
extern uint16_t map_chunk_variant3[CHUNK_X][CHUNK_Y];

// Have this here if I need it.
struct texture_atlas {
  Image img;
  Texture2D texture;
};

namespace map_gen {
inline uint16_t tile(texture_atlas atlas);
}
