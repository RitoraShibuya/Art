#include "Processing.h"

const int W = 1000, H = 1000, CX = W / 2, CY = H / 2;
const int BG = 255, LINE_NUM = 4, STEP = 5, ANG_STEP = 30;

struct Cave {
    double base_ang;
    void setup(int i) { base_ang = 360.0 * (i + 1.0) / (LINE_NUM + 1.0); }
    void draw() {
        double x = CX, y = CY;
        for (int i = 0; i <= 360; i += STEP) {
            double old_x = x, old_y = y;
            double size = map(i, 0, 360, 0, W);
            double ang = base_ang + i * ANG_STEP;
            x = CX + cos(radians(ang)) * size;
            y = CY + sin(radians(ang)) * size;
            line(old_x, old_y, x, y);
        }
        base_ang += 1; // ‰ñ“]‘¬“x
    }
};

Cave lines[LINE_NUM];

void setup() {
    size(W, H);
    stroke(0);
    for (int i = 0; i < LINE_NUM; i++) lines[i].setup(i);
}

void draw() {
    background(BG, 50);
    for (auto& l : lines) l.draw();
}
