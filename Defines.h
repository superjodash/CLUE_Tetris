#ifndef DEFINES_H
#define DEFINES_H

// Hardware
#define BUTTON_A 5
#define BUTTON_B 11
#define BUTTON_0 0
#define BUTTON_1 1
#define BUTTON_2 2

// Game board / screen relationships
#define CELL_SIZE 10                                    // Cell size in pixels
#define BOARD_WIDTH_C 10                                // Board width in cells
#define BOARD_HEIGHT_C 26                               // Board heght in cells
#define SCREEN_WIDTH 240                                // Screen width in pixels
#define SCREEN_HEIGHT 240                               // Screen height in pixels
#define BOARD_WIDTH CELL_SIZE * BOARD_WIDTH_C           // Board width in pixels
#define BOARD_HEIGHT CELL_SIZE * BOARD_HEIGHT_C         // Board height in pixels

// Movement
#define MOVE_NONE 0
#define MOVE_LEFT 1
#define MOVE_RIGHT 2

// Piece shapes
#define PIECE_I 0
#define PIECE_J 1
#define PIECE_L 2
#define PIECE_O 3
#define PIECE_S 4
#define PIECE_T 5
#define PIECE_Z 6

// Piece orientation
#define ORTN_0 0
#define ORTN_90 1
#define ORTN_180 2
#define ORTN_270 3

#define FRAME_DELAY 1000
#define FPS 10
#define MSPF FRAME_DELAY / FPS

struct Point {
  int x;
  int y;
};





#endif
