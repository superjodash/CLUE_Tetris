#include <Adafruit_Arcada.h> // include for screen
#include <Bounce2.h> //https://github.com/thomasfredericks/Bounce2
#include <LinkedList.h> ////https://github.com/ivanseidel/LinkedList

#include "defines.h"
#include "shapes.h"

/***
 *  Tetris clone for CLUE using Arcada
 * 
 * Button A: Makes piece drop faster
 * Button B: Rotates Piece clockwise
 * Reset   : Resets game
 * 
 */

Adafruit_Arcada arcada;
LinkedList<int> snake = LinkedList<int>();
Bounce2::Button buttonA;
Bounce2::Button buttonB;
Bounce2::Button buttonL;
Bounce2::Button buttonR;

int board[BOARD_WIDTH_C * BOARD_HEIGHT_C];
bool gameOver = true;
int frame = 0;

int currentPiece = PIECE_O;
int orientation = ORTN_0;
int moveState = MOVE_NONE;
bool speedBoost = false;

void setup() {
#ifdef DEBUG
   Serial.begin(9600);
#endif

  randomSeed(millis());
  initHardware();
  drawBoard();
  //drawPiece();
}

void initHardware() {
  buttonA.attach(BUTTON_A, INPUT);
  buttonA.interval(5);
  buttonA.setPressedState(LOW);
  
  buttonB.attach(BUTTON_B, INPUT);
  buttonB.interval(5);
  buttonB.setPressedState(LOW);

  buttonL.attach(BUTTON_0, INPUT);
  buttonL.interval(5);
  buttonL.setPressedState(LOW);

  buttonR.attach(BUTTON_1, INPUT);
  buttonR.interval(5);
  buttonR.setPressedState(LOW);
  
  if (!arcada.arcadaBegin()) {
    Serial.print("Failed to begin");
    while (1);
  }
  
  arcada.displayBegin();
  arcada.display->setCursor(0, 0);
  arcada.display->setTextSize(2);

   // Turn on backlight
  arcada.setBacklight(255);
}

void drawBoard() {
  // Draw Scoring Area
  arcada.display->fillRect(BOARD_WIDTH + 1, 0, SCREEN_WIDTH - BOARD_WIDTH + 1, BOARD_HEIGHT, ARCADA_WHITE);

  // Draw Well
  //arcada.display->fillRect(0, 0, BOARD_WIDTH, BOARD_HEIGHT, ARCADA_BLACK);
  arcada.display->drawFastVLine(0, 0, BOARD_HEIGHT, ARCADA_BLUE);
  arcada.display->drawFastVLine(BOARD_WIDTH, 0, BOARD_HEIGHT, ARCADA_BLUE);
}

void rotatePiece() {
  
}

void movePieceSideways() {
  // Check move validity before moving!
  switch(moveState) {
    case MOVE_LEFT:
      break;
    case MOVE_RIGHT:
      break;
    case MOVE_NONE:
      return;
  }

  // incremement
  

  // reset states
  speedBoost = false;
  moveState = MOVE_NONE;
}

void movePieceDown() {
  
}

void checkGameState() {
  
}

void drawPiece(Point index, bool erase) {
  // draw piece in its color unless erasing - then black
  switch(currentPiece) {
    case PIECE_I:
      break;
    case PIECE_J:
      break;
    case PIECE_L:
      break;
    case PIECE_O:
      break;
    case PIECE_S:
      break;
    case PIECE_T:
      break;
    case PIECE_Z:
    break;
  }
}

void drawCell() {
  
}

void loop() {

  if(gameOver) {
    return;
  }

  buttonA.update();
  buttonB.update();
  buttonL.update();
  buttonR.update();

  speedBoost = buttonA.pressed();
  
  if (buttonB.pressed()) {
    // Rotate piece clockwise
    orientation = (orientation + 1) % 4;
  } else if(buttonL.pressed()) {
    moveState = MOVE_LEFT;
  } else if(buttonR.pressed()) {
    moveState = MOVE_RIGHT;
  }

  // we need a separate timer for falling vs moving/rotating

  frame += 1;
  if(frame >= MSPF) {
    movePieceSideways();
    movePieceDown();
    checkGameState();
    frame = 0;
  }
  delay(1);
}

int pointToIndex(Point p) {
  return p.y * BOARD_WIDTH_C + p.x;
}

Point indexToPoint(int index) {
   return { index % BOARD_WIDTH_C, index / BOARD_WIDTH_C };
}

void rotateMatrix(int* mat, int n) {
  int ret[n][n];
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      ret[i][j] = mat[n - j - 1 * i];
    }
  }
}
