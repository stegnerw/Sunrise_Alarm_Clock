# sunrise_alarm_clock

Honors project to make a sunrise alarm clock.
- I am currently revising the design to use less hardware.
- `Hardware/` folder contains hardware schematics.
- `Arduino_Test/` folder contains Arduino sketches to test the hardware designs.
- Will soon include `src/` and `install/` directories for implementation code and installation.

## Current Design

Currently I have custom hardware designed to multiplex the [seven segment display](https://www.adafruit.com/product/865) and to generate signals for the [NeoPixel LED's](https://www.adafruit.com/product/2859). The speaker can be driven directly from the Raspberry Pi Zero.

### Seven Segment Multiplexer

The seven segment multiplexer has the following major components:
- 555 astable oscillator to generate a steady clock pulse.
- Four 8-bit shift registers to hold the digit values, driven by the 555 circuit.
- 7-bit counter to select which digit is active on the display.

### NeoPixel Signal Generation

The NeoPixel signal generation circuit has the following major components:
- 3.2768 MHz oscillator to drive a counter.
- Two 64-bit shift registers to store the light values.
- Two 4-input multiplexors to generate either 1 or 0 signals.
- 12-bit counter to control the shift register and multiplexors.

### Problems

Currently, the NeoPixel signal generation circuit does not work consistently.
- One possible issue is the parasitic capacitance on the breadboard is too high and causes inconsistent timing.
- It is hard to debug the timing problems because I have cheap oscilloscope probes.
- The circuit is large and would be expensive for PCB manufacturing.

## Future Plans

The future plans are to reduce the overall size of the hardware and fix the consistency of the NeoPixel signal generation.
- Use an ATtiny85 to generate the NeoPixel control signal.
- Utilize thread scheduling to multiplex the seven segment display. This should not need its own hardware because the timing requirement is on the order of milliseconds.
