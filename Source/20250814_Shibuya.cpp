#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int E_NUM = 6;
const int E_SIZE = 50;
const int E_WIDTH = 200;
const int E_SPD = 100;

bool Ang_Switch;
bool Size_Switch;

struct HOLE {
    double x, y;
    double mx, my;
    double e_width;
    double ang;
    double max_x, max_y;
    double spd_x, spd_y;

    void Setup(int i) {
        x = CENTER_X;
        y = CENTER_Y;
        e_width = E_WIDTH;
        ang = PI * 2 * i / E_NUM;
        mx = CENTER_X;
        my = CENTER_Y;
        spd_x = 0;
    }

    void Draw() {
        x = mx + sin(ang) * e_width;
        y = my + cos(ang) * e_width;
        ellipse(x, y, E_SIZE);

        ang += (Ang_Switch ? 1 : -1);

        if (Size_Switch) {
            e_width -= spd_x;
            if (e_width <= 0) { e_width = 0; Size_Switch = false; }
        }
        else {
            e_width += spd_x;
            if (e_width >= E_WIDTH) { e_width = E_WIDTH; Size_Switch = true; }
        }
    }

    void Updatespd(double gmx, double gmy) {
        max_x = x;
        max_y = y;
        mx = gmx;
        my = gmy;
        spd_x = abs(x - mx) / E_SPD;
    }
};

HOLE ellipses[E_NUM];

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKCOLOR);
    noStroke();
    fill(255);
    setFrameRate(30);
    Ang_Switch = true;
    Size_Switch = false;
    for (int i = 0; i < E_NUM; i++) {
        ellipses[i].Setup(i);
    }
}

void draw() {
    background(BACKCOLOR, 20);
    for (int i = 0; i < E_NUM; i++) {
        ellipses[i].Draw();
    }
}

void mouseClicked() {
    Ang_Switch = !Ang_Switch;
    Size_Switch = !Size_Switch;
    double gmx = getMouseX();
    double gmy = getMouseY();
    for (int i = 0; i < E_NUM; i++) {
        ellipses[i].Updatespd(gmx, gmy);
    }
}
