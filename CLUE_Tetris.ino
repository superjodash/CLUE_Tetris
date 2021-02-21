#include <Adafruit_Arcada.h> // include for screen
#include <Bounce2.h> //https://github.com/thomasfredericks/Bounce2
#include <LinkedList.h> ////https://github.com/ivanseidel/LinkedList

/***
 *  Tetris clone for CLUE using Arcada
 * 
 * Button A: Makes piece drop faster
 * Button B: Rotates Piece clockwise
 * Reset   : Resets game
 * 
 */

#define FRAME_DELAY 1000
#define FPS 10
#define MSPF FRAME_DELAY / FPS
//const double MSPF = FRAME_DELAY / FPS; // 16.66667ms

Adafruit_Arcada arcada;
LinkedList<int> snake = LinkedList<int>();
Bounce2::Button buttonA;
Bounce2::Button buttonB;

bool gameOver = false;
int frame = 0;

void setup() {
#ifdef DEBUG
   Serial.begin(9600);
#endif

  randomSeed(millis());
  initHardware();
 
}

void initHardware() {
  buttonA.attach(BUTTON_A, INPUT);
  buttonA.interval(5);
  buttonA.setPressedState(LOW);
  
  buttonB.attach(BUTTON_B, INPUT);
  buttonB.interval(5);
  buttonB.setPressedState(LOW);
  
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

void loop() {

  if(gameOver) {
    return;
  }

  buttonA.update();
  buttonB.update();
  
  if(buttonA.pressed()) {
  } else if (buttonB.pressed()) {
  }

  frame += 1;
  if(frame >= MSPF) {
    frame = 0;
  }
  delay(1);
}
