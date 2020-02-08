/********************************************************************
 *                       MiDispositivoMIDI V3                       *
 ********************************************************************
 * 2018 BanaNut Electronics                                         *
 * bananutelectronics@gmail.com                                     *
 *                                                                  *
 * See license and documentation in the repository.                 *
 * https://github.com/bananut-electronics                           *
 *                                                                  *
 * Code:     MDM_V3_Library4x4.ino                                      *
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

BoardRoles bRoles[1] = {TOUCHPAD};
MiDispositivoMIDI_V3 mdm = MiDispositivoMIDI_V3(SINGLE_DEVICE_4X4, bRoles);

void setup() {
  
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
  // Run the loop. This will read all buttons and
  // execute different actions, such as light up the
  // pressed LEDs, and send a MIDI noteOn message.
  mdm.loop();
}

// Function that is called periodically
void doFunnyAnimation(){

  // This animation wipes between two colors
  uint8_t colores1[3] = {0, 50, 0};
};
