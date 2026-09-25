#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int GLIDSIZE = 50;
const int NUM_LINES = 10;
const int LINEALPHA = 100;

struct ColorLine {
    int x;
    int y;
    int old_x;
    int old_y;
    int r;
    int g;
    int b;

    void Setup(int n) {
        x = CENTER_X;
        y = CENTER_Y;
        old_x = CENTER_X;
        old_y = CENTER_Y;
        r = 0;
        g = 0;
        b = 0;

        switch (n % 4) {
        case 1: r = 255; break;
        case 2: g = 255; break;
        case 3: b = 255; break;
        }
    }

    void DrawLine() {
        old_x = x;
        old_y = y;

        switch ((int)random(1, 5)) {
        case 1: for (int i = 0;i < (int)random(1, 4);i++) { if (x + GLIDSIZE <= WIDTH)  x += GLIDSIZE; } break;
        case 2: for (int i = 0;i < (int)random(1, 4);i++) { if (x - GLIDSIZE >= 0)      x -= GLIDSIZE; } break;
        case 3: for (int i = 0;i < (int)random(1, 4);i++) { if (y + GLIDSIZE <= HEIGHT) y += GLIDSIZE; } break;
        case 4: for (int i = 0;i < (int)random(1, 4);i++) { if (y - GLIDSIZE >= 0)      y -= GLIDSIZE; } break;
        }

        stroke(r, g, b);
        strokeWeight(5);
        line(old_x, old_y, x, y);
    }
};

ColorLine lines[NUM_LINES];

void setup() {
    size(WIDTH, HEIGHT);
    background(0);
    setFrameRate(30);

    for (int i = 0; i < NUM_LINES; i++) {
        lines[i].Setup(i);
    }
}

void draw() {

    background(0);

    for (int i = 0; i < NUM_LINES; i++) {
        lines[i].DrawLine();
    }
}
