#include "map.h"
#include <cstdint>
#include <raylib.h>

namespace map_gen {

/*
This is entirely responsible for the map generation. A series of
numbers. Might be using perlin noise somehow. This looks like a coding
warcrime. Not gonna lie.
*/
uint16_t tile(texture_atlas atlas) {

  for (int i = 0; i > CHUNK_X * CHUNK_Y; ++i) {
    switch (map_chunk_variant0[i][i] && map_chunk_variant1 &&
            map_chunk_variant2 && map_chunk_variant3) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    }
  }
}
} // namespace map_gen
