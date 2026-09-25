#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 255;
const int R_WEIGHT = 25;   // バーの厚み
const int R_HEIGHT = 25;   // バーの厚み

int _framecount = 0;

enum Direction { FROM_BOTTOM, FROM_LEFT, FROM_RIGHT, FROM_TOP };

struct MUSICWAVE {
    int x, y;     // 基準位置
    int r, g, b;  // 色
    int bars;     // バーの数
    Direction dir;

    void Setup(int sx, int sy, Direction d, int cr, int cg, int cb) {
        x = sx;
        y = sy;
        dir = d;
        r = cr; g = cg; b = cb;
        bars = 0;
    }

    void Update() {
        float val = noise(_framecount * 0.05 + (x + y) * 0.02);
        bars = (int)(val * 30);   // 最大20段
    }

    void Draw() {
        fill(r, g, b,120);
        stroke(BACKCOLOR);
        for (int c = 0; c < bars; c++) {
            if (dir == FROM_BOTTOM) {
                int yy = HEIGHT - R_HEIGHT * (c + 1);
                rect(x, yy, R_WEIGHT, R_HEIGHT);
            }
            else if (dir == FROM_LEFT) {
                int xx = R_WEIGHT * c;
                rect(xx, y, R_WEIGHT, R_HEIGHT);
            }
            else if (dir == FROM_RIGHT) {
                int xx = WIDTH - R_WEIGHT * (c + 1);
                rect(xx, y, R_WEIGHT, R_HEIGHT);
            }
            else if (dir == FROM_TOP) {
                int yy = R_HEIGHT * c;
                rect(x, yy, R_WEIGHT, R_HEIGHT);
            }
        }
    }
};

std::vector<MUSICWAVE> Rects;

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKCOLOR);
    setFrameRate(30);

    // 下から緑
    for (int x = 0; x < WIDTH; x += R_WEIGHT) {
        MUSICWAVE R;
        R.Setup(x, HEIGHT, FROM_BOTTOM, 0, 255, 0);
        Rects.push_back(R);
    }

    // 左から赤
    for (int y = 0; y < HEIGHT; y += R_HEIGHT) {
        MUSICWAVE R;
        R.Setup(0, y, FROM_LEFT, 255, 0, 0);
        Rects.push_back(R);
    }

    // 右から青
    for (int y = 0; y < HEIGHT; y += R_HEIGHT) {
        MUSICWAVE R;
        R.Setup(WIDTH, y, FROM_RIGHT, 0, 0, 255);
        Rects.push_back(R);
    }

    // 上から黄
    for (int x = 0; x < WIDTH; x += R_WEIGHT) {
        MUSICWAVE R;
        R.Setup(x, 0, FROM_TOP, 255, 255, 0);
        Rects.push_back(R);
    }
}

void draw() {
    background(BACKCOLOR);
    for (auto& R : Rects) {
        R.Update();
        R.Draw();
    }
    _framecount++;
}
