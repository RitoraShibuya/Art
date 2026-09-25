#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 255;
const int BACKGRAY = 5;
const int GAP = 20;
const int E_SIZE = 10;
const double NOISEMUL = 0.01;

double framecount = 0;

void setup( ) {
    size(WIDTH, HEIGHT);
    background(BACKCOLOR);
    noStroke( );
}

void draw( ) {
    background(BACKCOLOR, BACKGRAY);

    for (int x = 0; x <= WIDTH; x += GAP)
    {
        for (int y = 0; y <= HEIGHT; y += GAP)
        {
            double r = noise(x * NOISEMUL, y * NOISEMUL, framecount * NOISEMUL) * 255;
            double g = noise((x + 200) * NOISEMUL, y * NOISEMUL, framecount * NOISEMUL) * 255;
            double b = noise(x * NOISEMUL, (y + 200) * NOISEMUL, framecount * NOISEMUL) * 255;

            double size = noise(x * NOISEMUL, y * NOISEMUL, framecount * 0.5 * NOISEMUL) * E_SIZE * 2;

            fill(r, g, b);
            ellipse(x, y, size);
        }
    }
    framecount += 0.02;
}
