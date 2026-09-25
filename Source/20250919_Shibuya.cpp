#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOL = 0;
const int E_NUM = 6;
const int GAP = 200;
const int P_GAP = 80;
const int C_SPD = 3;        // 追従速度
const double ANGSPD = 0.01;

int framecount;

struct CenterPoint {
    int old_cx, old_cy;
};

struct Horse {
    int center_x, center_y, x, y, r, g, b, num;
    double ang, p_ang;

    void setup(int i) {
        num = i;
        ang = PI2 * num / E_NUM;
        p_ang = (int)random(360);
        center_x = CENTER_X;
        center_y = CENTER_Y;
        r = g = b = 0;
        switch (num % 3) {
        case 0: r = 255; break;
        case 1: g = 255; break;
        case 2: b = 255; break;
        }
    }

    void update(int cx, int cy) {
        x = cx + sin(ang) * GAP;
        y = cy + cos(ang) * GAP;
        ang += ANGSPD;
    }

    void draw() {
        stroke(r, g, b);
        noFill();

        for (int n = 0; n < 180; n += 3) {
            double ang = radians(p_ang + n);

            // ang によって固定のノイズ値を取得（framecount を入れない）
            double radius = P_GAP + ( noise(num * 10 + cos(ang), num * 10 + sin(ang),framecount * 0.05) - 0.5 ) * 50;

            double px = x + cos(ang) * radius;
            double py = y + sin(ang) * radius;

            point(px, py);
        }
        p_ang += 3;
    }
};

CenterPoint P;
Horse points[E_NUM];

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKCOL);
    setFrameRate(30);
    P.old_cx = CENTER_X;
    P.old_cy = CENTER_Y;
    for (int i = 0; i < E_NUM; i++) {
        points[i].setup(i);
    }
    framecount = 0;
}

void draw() {
    background(BACKCOL, 5);

    // マウスへのベクトル
    double dx = getMouseX() - P.old_cx;
    double dy = getMouseY() - P.old_cy;
    double dist = sqrt(dx * dx + dy * dy);

    int cx = P.old_cx;
    int cy = P.old_cy;

    if (dist > 0) {
        cx = P.old_cx + ( dx / dist ) * C_SPD;
        cy = P.old_cy + ( dy / dist ) * C_SPD;
    }

    // 各Horse更新
    for (int i = 0; i < E_NUM; i++) {
        points[i].update(cx, cy);
    }
    P.old_cx = cx;
    P.old_cy = cy;

    // 描画
    for (int i = 0; i < E_NUM; i++) {
        points[i].draw();
    }

    framecount++;
}
