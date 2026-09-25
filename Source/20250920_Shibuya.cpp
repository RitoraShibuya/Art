#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int DIA = 100;

// 真ん中の白い枠のサイズ
const int FRAME_SIZE = 500;
const int FRAME_X = (WIDTH - FRAME_SIZE) / 2;
const int FRAME_Y = (HEIGHT - FRAME_SIZE) / 2;

// 横幅は固定
const int LIGHT_W = 100;

// ライトを描画する関数（横長バージョン）
void drawLight(int x, int y, int maxH) {
    noStroke();
    for (int h = maxH; h > 0; h -= 10) {
        int alpha = map(h, 0, maxH, 0, 100); // 外側ほど薄く
        fill(255, 255, 0, alpha);
        ellipse(x, y, LIGHT_W, h);  // 横は固定、縦だけ広がる
    }
}

void setup() {
    size(WIDTH, HEIGHT);
    background(0);
    noFill();
    stroke(255);
    rectMode(CORNER);
}

void draw() {
    background(0);

    int mx = getMouseX();
    int my = getMouseY();
    int rx1 = mx - DIA / 2;
    int ry1 = my - DIA / 2;
    int rx2 = mx + DIA / 2;
    int ry2 = my + DIA / 2;

    // ライトの位置と高さ
    int e_x = (mx + FRAME_X + FRAME_SIZE / 2) / 2;
    int e_y = (my - (DIA / 2) + FRAME_Y) / 2;
    int e_h = (int)map(e_y, FRAME_Y, FRAME_Y + FRAME_SIZE, 0, 100);

    // マウスの四角
    noFill();
    stroke(255);
    rect(rx1, ry1, DIA, DIA);

    // 照明（ライト、横幅は固定）
    drawLight(e_x, e_y, e_h);

    // 対角線
    stroke(255);
    line(rx1, ry1, FRAME_X, FRAME_Y);
    line(rx2, ry1, FRAME_X + FRAME_SIZE, FRAME_Y);
    line(rx1, ry2, FRAME_X, FRAME_Y + FRAME_SIZE);
    line(rx2, ry2, FRAME_X + FRAME_SIZE, FRAME_Y + FRAME_SIZE);

    // 上下左右を黒く塗りつぶし
    fill(0);
    noStroke();
    rect(0, 0, WIDTH, FRAME_Y);
    rect(0, FRAME_Y + FRAME_SIZE, WIDTH, HEIGHT);
    rect(0, FRAME_Y, FRAME_X, FRAME_SIZE);
    rect(FRAME_X + FRAME_SIZE, FRAME_Y, WIDTH - (FRAME_X + FRAME_SIZE), FRAME_SIZE);

    // 白い枠
    noFill();
    stroke(255);
    rect(FRAME_X, FRAME_Y, FRAME_SIZE, FRAME_SIZE);
}
