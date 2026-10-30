#pragma once

#include <raylib.h>

// Macros to dictate player movement
#define SPEED 50.0f
#define DELTA_TIME GetFrameTime()

// Forward declarations for player
Vector2 player_position;
extern Vector2 player_position;

Camera2D player_cam;
extern Camera2D player_cam;

enum bindings { MOVEMENT = 1 << 0, ACTION = 1 << 1, PAUSE = 3 };
/*
Keys struct features a tagged union for keybindings.
*/
typedef struct {
  // bindings
  enum bindings key_bindings;
  union {
    // Takes a single integer at a time.
    int key;
  };
} keys;

// Function declarations. Controls.c
// End forward declaration of player

// Function declarations. Player.c
void move_player();
