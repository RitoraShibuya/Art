#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int BACKALPHA = 5;
const int LINECOLOR = 255;
const int MIN_SIZE = 50;
const int MAX_SIZE = 500;
const int E_NUM = 6;
const int SPAWN_RADIUS = 100;

struct ELLIPE {
    int x, y;
    double _size;

    void Setup(int px = CENTER_X, int py = CENTER_Y) {
        x = px;
        y = py;
        _size = MIN_SIZE;
    }

    void Draw() {
        ellipse(x, y, _size);
        _size += 2;
    }

    bool ShouldSplit() const {
        return _size >= MAX_SIZE;
    }

    static bool IsInside(int x, int y) {
        return x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT;
    }
};

std::vector<ELLIPE> ellipses;

void ResetEllipses() {
    ellipses.clear();
    ELLIPE newE;
    newE.Setup();
    ellipses.push_back(newE);
}

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKCOLOR);
    noFill();
    stroke(0,0,LINECOLOR);
    strokeWeight(5);
    ResetEllipses();
}

void draw() {
    background(BACKCOLOR, BACKALPHA);
    std::vector<ELLIPE> newEllipses;

    for (int i = 0; i < ellipses.size(); i++) {
        ellipses[i].Draw();

        if (ellipses[i].ShouldSplit()) {
            bool outOfBounds = false;

            for (int j = 0; j < E_NUM; j++) {
                double angle = TWO_PI * j / E_NUM;
                int px = ellipses[i].x + cos(angle) * (MAX_SIZE / 2);
                int py = ellipses[i].y + sin(angle) * (MAX_SIZE / 2);

                if (!ELLIPE::IsInside(px, py)) {
                    outOfBounds = true;
                    break;
                }
            }

            if (outOfBounds) {
                ResetEllipses();  // 一つでも画面外ならリセット
                return;
            }

            // 全て画面内なら生成
            for (int j = 0; j < E_NUM; j++) {
                double angle = TWO_PI * j / E_NUM;
                int px = ellipses[i].x + cos(angle) * (MAX_SIZE / 2);
                int py = ellipses[i].y + sin(angle) * (MAX_SIZE / 2);

                ELLIPE newE;
                newE.Setup(px, py);
                newEllipses.push_back(newE);
            }

        }
        else {
            newEllipses.push_back(ellipses[i]);
        }
    }

    ellipses = newEllipses;
}
