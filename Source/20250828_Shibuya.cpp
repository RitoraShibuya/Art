#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 230;
const int SPD = 5;        // 伸びる速さ
const int LINENUM = 40;   // ひびの本数
const int DOTSIZE = 20;   // ドットの大きさ
const double NOISEGAP = 0.01;

int gap = 0;
bool active = false;      // ひびが動いているかどうか
int frameCounter = 0;

struct Crack {
    int num;
    int mx, my;   // 中心座標
    double ang;   // 角度
    int ex, ey;   // 端点

    void Setup(int set_num, int cx, int cy) {
        num = set_num;
        mx = cx;
        my = cy;
        ang = PI2 * num / LINENUM;
        ex = mx;
        ey = my;
    }

    void Update() {
        ang += random(-0.05, 0.05);   // 少し揺らす
        ex = mx + cos(ang) * gap;
        ey = my + sin(ang) * gap;
    }

    void Draw() {
        if (frameCounter % 2 == 0) {
            noStroke();
            fill(
                noise(ex * NOISEGAP, ey * NOISEGAP, 0) * 255,
                noise(ex * NOISEGAP + 100, ey * NOISEGAP, 0) * 255,
                noise(ex * NOISEGAP, ey * NOISEGAP + 100, 0) * 255
            );
            rect(ex, ey, DOTSIZE, DOTSIZE);
        }
    }
};

Crack cracks[LINENUM];

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKCOLOR);
    rectMode(CENTER);   // rectの中心を座標にする
}

void draw() {
    if (!active) return;  // ひびが始まってなければ描かない

    for (int i = 0; i < LINENUM; i++) {
        cracks[i].Update();
        cracks[i].Draw();
    }
    gap += SPD;
    frameCounter++;
}

void mousePressed() {
    background(BACKCOLOR);  // 完全クリアに変更（過去のひびが消える）
    gap = 0;
    frameCounter = 0;
    active = true;          // ひびが動き始める
    int cx = getMouseX();
    int cy = getMouseY();
    for (int i = 0; i < LINENUM; i++) {
        cracks[i].Setup(i, cx, cy);
    }
}
