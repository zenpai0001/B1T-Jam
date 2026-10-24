#pragma once

#include <raylib.h>

// Forward declaration of player position.
typedef struct {
  float x;
  float y;
} player;

extern player global;

// Function declarations. Player.c
void move_player();
