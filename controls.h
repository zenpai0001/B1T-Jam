#pragma once

#include "raylib.h"

#define MAX_BUFFERS 16

typedef struct {
  RenderTexture2D buffers;
  int key;
  const char *text;
} buffer_table;

// void handle_buffer(buffer_table *buffer);
void handle_buffer();
void unit_test();
