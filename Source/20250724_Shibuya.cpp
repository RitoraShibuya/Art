#include "processing.h"

#include <algorithm> // std::min, std::max ‚Ì‚½‚ß

float constrain(float val, float minVal, float maxVal) {
    return std::min(std::max(val, minVal), maxVal);
}


const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUNDCOLOR = 0;
const int BACKGROUNDGRAYSCALE = 30;
const int N = 25;
const int DIAMETER = 50;
const int DMIN = 50;
const int DMAX = 100;
const int DADD = 1;
const int SPD = 10;

struct Sphere {
    double x, y, vx, vy, c, ang , alpha;
    float d;

    void init() {
        ang = random(180);
        d = random(DMIN, DMAX);
        x = random(d / 2, WIDTH - d / 2);
        y = random(d / 2, HEIGHT - d / 2);
    }

    void update() {
        vx = random(-SPD, SPD);
        vy = random(-SPD, SPD);
        x += vx; 
        y += vy;

        d += ((int)random(2) == 1 ? -DADD : DADD);
        d = constrain(d, DMIN, DMAX);

        if (x < -d / 2) x = WIDTH + d / 2;
        if (x > WIDTH + d / 2) x = -d / 2;
        if (y < -d / 2) y = HEIGHT + d / 2;
        if (y > HEIGHT + d / 2) y = -d / 2;
    }

    void draw() {
        alpha = (double)map(sin(radians(ang)),-1,1,0,1) * 50;
        fill(255,255,0,alpha);
        noStroke();
        rect(x - d / 2, y - d / 2, d, d);
        ang += 5;
    }

};

Sphere bugs[N];

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKGROUNDCOLOR);
    setFrameRate(30);
    for (int i = 0; i < N; i++) bugs[i].init();
}

void draw() {
    background(BACKGROUNDCOLOR, BACKGROUNDGRAYSCALE);

    for (int i = 0; i < N; i++) {
        bugs[i].update();
        bugs[i].draw();
    }
}

