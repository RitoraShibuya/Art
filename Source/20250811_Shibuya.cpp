#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 255;
const int LINE_NUM = 20;
const int LINE_CAVE = 10;
const int LINE_COLOR = 0;
const int LINE_ALPHA = 50; // 初期透明度

struct BORN {
    int sx, sy, x1, y1, x2, y2, ex, ey;

    void Setup() {
        sx = CENTER_X;
        sy = 0;
        ex = CENTER_X;
        ey = HEIGHT;

        // 最初の枝分かれ位置
        x1 = sx + (int)random(-300, 300);
        y1 = sy + (int)random(300);
    }

    void Update() {
        int px = sx;
        int py = sy;

        for (int i = 0; i <= LINE_CAVE; i++) {
            // 進行度（0.0 = 開始, 1.0 = 終点）
            double progress = (double)i / LINE_CAVE;

            // 中央までは濃く太く、後半は薄く細く
            double alpha;
            double weight;
            if (progress <= 0.5) {
                alpha = map(progress, 0, 0.5, LINE_ALPHA, 255);
                weight = map(progress, 0, 0.5, 1, 5);
            }
            else {
                alpha = map(progress, 0.5, 1, 255, LINE_ALPHA);
                weight = map(progress, 0.5, 1, 5, 1);
            }

            // 上半分はブレ幅大きく、下半分は小さく
            double randX = map(progress, 0, 1, 200, 50);

            stroke(LINE_COLOR, alpha);
            strokeWeight(weight);

            if (i == 0) {
                // 最初
                x2 = x1;
                y2 = y1;
            }
            else if (i == LINE_CAVE) {
                // 終点
                x2 = ex;
                y2 = ey;
            }
            else {
                // 中間
                x2 = px + (int)random(-randX, randX);
                y2 = py + (int)random(150);
            }

            line(px, py, x2, y2);
            px = x2;
            py = y2;
        }
    }
};

BORN lines[LINE_NUM];

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKCOLOR);
    for (int i = 0; i < LINE_NUM; i++) {
        lines[i].Setup();
    }
}

void mouseClicked() {
    background(BACKCOLOR);
    for (int i = 0; i < LINE_NUM; i++) {
        lines[i].Setup();
        lines[i].Update();
    }
}
