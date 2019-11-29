# stranger_lights

Re-creates the Chrismas light prop from Season 1 of Stranger Things. I was originally inspired by
http://www.instructables.com/id/Arduino-Based-Stranger-Things-Lights/, and used the shopping list
described there for the project:

- Arduino DUO
- One strand of WS2811 LED lights (not the strips, though)
- separate DC power supplies for the Arduino and the LEDs
- power jack adapters for connecting the LED strand to DC power

We hung the lights on the wall, taped up the alphabet and then went through the process of identifying which
light was best situated to light up each letter. I used a simple sketch to illuminate the LEDs one at a time, wrote down
the best LEDs and plugged the values in.

You'll do this the very first time you set it up, and adjust the values in lines 18-32 of the sketch accordingly. 

Things to know:

- The sketch requires the FastLED library.

- the "fading" bits were left over from an earlier iteration. they don't work as intended, but I was OK with
the effect, so they stayed in. If you can grok what I was trying to do and fix it, let me know.

- the lights will be random colors each time they're used for messages. If you're OK with this, great. if not, you'll need
to hard-code colors somehow. I didn't care, so I didn't bother.

Have fun! We did. This was our first Arduino project and it was a ball to get up and running. 

Update: the Christmas Lights sketch is just that - a series of effects driving a 500-led strand that we put on our tree. I lost the most recent version and had to rebuild a bunch of it by hand in a hurry. Sticking it here so it'll be safe. Use it if you like. I'm not really into crazy outdoor shows. This is just enough to scratch the itch.
