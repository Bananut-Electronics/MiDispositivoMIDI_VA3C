#include <Control_Surface.h> // Include the Control Surface library

// Instantiate a MIDI over USB interface.
USBMIDI_Interface midi;

// Instantiate a multiplexer
CD74HC4067 mux = {
  A0,              // analog pin
  {0, 1, 2, 3}, // Address pins S0, S1, S2, S3
  // 7, // Optionally, specify the enable pin
};

// Alternatively, if you have a 3-bit mux:
// CD74HC4051 mux = {
//   A0,
//   {3, 4, 5},
//   // 7, // Optional
// };

// Create an array of potentiometers that send out MIDI Control Change messages 
// when you turn the potentiometers connected to the 16 input pins of the mux.
CCPotentiometer volumePotentiometers[] = {
  { mux.pin(0), { MIDI_CC::Channel_Volume, CHANNEL_1 } },
  { mux.pin(1), { MIDI_CC::Channel_Volume, CHANNEL_2 } },
  { mux.pin(2), { MIDI_CC::Channel_Volume, CHANNEL_3 } },
  { mux.pin(3), { MIDI_CC::Channel_Volume, CHANNEL_4 } },
  { mux.pin(4), { MIDI_CC::Channel_Volume, CHANNEL_5 } },
  { mux.pin(5), { MIDI_CC::Channel_Volume, CHANNEL_6 } },
  { mux.pin(6), { MIDI_CC::Channel_Volume, CHANNEL_7 } },
  { mux.pin(7), { MIDI_CC::Channel_Volume, CHANNEL_8 } },
  { mux.pin(8), { MIDI_CC::Channel_Volume, CHANNEL_9 } },
  { mux.pin(9), { MIDI_CC::Channel_Volume, CHANNEL_10 } },
  { mux.pin(10), { MIDI_CC::Channel_Volume, CHANNEL_11 } },
  { mux.pin(11), { MIDI_CC::Channel_Volume, CHANNEL_12 } },
  { mux.pin(12), { MIDI_CC::Channel_Volume, CHANNEL_13 } },
  { mux.pin(13), { MIDI_CC::Channel_Volume, CHANNEL_14 } },
  { mux.pin(14), { MIDI_CC::Channel_Volume, CHANNEL_15 } },
  { mux.pin(15), { MIDI_CC::Channel_Volume, CHANNEL_16 } },
};



void setup() {
  mux.begin(); // Initialize multiplexer
  Control_Surface.begin(); // Initialize Control Surface
}

void loop() {
  Control_Surface.loop(); // Update the Control Surface
}
