# stranger_lights

Re-creates the Chrismas light prop from Season 1 of Stranger Things. I was originally inspired by
http://www.instructables.com/id/Arduino-Based-Stranger-Things-Lights/, and used the shopping list
described there for the project:

- Arduino DUO
- One strand of WS2811 LED lights (not the strips, though)
- separate DC power supplies for the Arduino and the LEDs
- power jack adapters for connecting the LED strand to DC power

We hung the lights on the wall, taped up the alphabet and then went through the process of identifying which
light was best situated to light up each letter. You'll do this the very first time you set it up, and adjust
the values in lines 18-32 of the sketch accordingly.

Things to know:

- The sketch requires the FastLED library, so make sure you've got that installed.

- the "fading" bits were left over from an earlier iteration. they don't work as intended, but I was OK with
how it looked, so it stayed in

- the lights will be random colors each time they're used.

Have fun! We did. This was our first Arduino project and it was a ball to get up and running. 
