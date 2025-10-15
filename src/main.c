#include "module.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void cycle(int max) {
  for (int i = 0; i < max; i++) {
    printf("%i\n", i);
  }
}

struct foo *getStructPtr1() {
  struct foo *x = (struct foo *)(calloc(1, sizeof(struct foo)));
  x->a = 'b';
  x->b = 32463;
  return x;
}

struct foo *getStructPtr2() {
  struct foo *x = (struct foo *)(malloc(sizeof(*x)));
  *x = (struct foo){'a', 123};
  return x;
}

int main(void) {
  struct foo *(*operation)() = getStructPtr2;
  struct foo *x = operation();
  // printf("Hello, World!\n");
  // sayHello();
  printf("%c %d\n", x->a, x->b);
  free(x);
  // cycle(10);
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first window!", 190, 200, 20,
             LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}