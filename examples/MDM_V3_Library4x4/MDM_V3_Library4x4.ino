/********************************************************************
 *                       MiDispositivoMIDI V3                       *
 ********************************************************************
 * 2018 BanaNut Electronics                                         *
 * bananutelectronics@gmail.com                                     *
 *                                                                  *
 * See license and documentation in the repository.                 *
 * https://github.com/bananut-electronics                           *
 *                                                                  *
 * Code:     Expansion_4x4.ino                                      *
 * Hardware: Single 4x4 boards configuration        *
 * Brief:    This code handles a MiDispositivoMIDI V3 with three    *
 *           expansions, which is, four devices in total. They have *
 *           to be connected in a 4x4, creating an array of 16     *
 *           buttons. With this code you can set a default color    *
 *           when the button is an idle state, and another color    *
 *           when the button is pushed. There is also a subroutine  *
 *           that does some animation with the leds.                *
 *                                                                  *
 ********************************************************************/

// Include the library
#include <MiDispositivoMIDI_V3.h>

// Creates a mdm with four pages and only one expansion
BoardRoles bRoles[1] = {TOUCHPAD};
MiDispositivoMIDI_V3 mdm = MiDispositivoMIDI_V3(SINGLE_DEVICE_4X4, bRoles);

// Couple of variables for the led animation
int buttonCounter    = 0;
int expansionCounter = 0;
bool myflag          = 0;


void setup() {

  // Assign MIDI notes to buttons. Note that if you are using
  // more than one expansion (more than one 4x4 device) you will
  // need to change the size of this array. Always 1 value per button.
  uint8_t midiNotes [1][16] = {{ 36, 37, 38, 39,
                                 40, 41, 42, 43,
                                 44, 45, 46, 47,
                                 48, 49, 50, 51}};
  mdm.setMidiNotes(midiNotes);

  // Same with the so called velocities of the notes. This means the
  // intensity of each note.
  uint8_t midiVelocities [1][16] = {{127,127,127,127,
                                    127,127,127,127,
                                    127,127,127,127,
                                    127,127,127,127}};

  mdm.setMidiVeloc(midiVelocities);
  // Configure the colors when the LED is not pressed
  uint8_t offColors[3] = {255, 0, 0};
  mdm.setOffColors( offColors );

  // Configure the colors when the LED is pressed
  uint8_t onColors[3] = {0, 255, 0};
  mdm.setOnColors( onColors );

   // Set a call to an animation each .025 sec
  mdm.setInterrupt(doFunnyAnimation, 0.025);
}

void loop() {
  // Run the loop
  mdm.loop();
}

// Function that is called periodically
void doFunnyAnimation(){
  
  // This animation wipes between two colors
  uint8_t colores1[3] = {0, 50, 0};
  uint8_t colores2[3] = {0, 50, 50};

  mdm.setPixelColor(expansionCounter, buttonCounter, myflag ? colores1 : colores2);

  // Generates the following sequence.
  //      for (int i = 0; i < 4; i++)
  //        for (int j = 0; j < 16; j++)
  
  if (buttonCounter == 15)
  {
    buttonCounter = 0;
    if (expansionCounter == 3)
    {
      expansionCounter = 0;
      myflag = !myflag;
    }
    else{
      expansionCounter += 1;
    }
  }
  else
  {
    buttonCounter += 1;
  }
}
