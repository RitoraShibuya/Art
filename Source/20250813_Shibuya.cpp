#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int BACKALPHA = 5;
const int L_NUM = 4;
const int L_COLOR = 255;
const int SPD_MIN = 0;
const int SPD_MAX = 50;

bool _spd_switch = true; // 初回も速度設定できるように

struct Sphere
{
    double x, y, x2, y2;

    void Setup(int i, double set_x, double set_y)
    {
        x = CENTER_X;
        y = CENTER_Y;
        x2 = x;
        y2 = y;
    }

    void Draw(int i, double adx, double ady)
    {
        // 画面外に出たら中央に戻す
        if (x > WIDTH || x < 0 || y > HEIGHT || y < 0) {
            x = CENTER_X;
            y = CENTER_Y;
            x2 = CENTER_X;
            y2 = CENTER_Y;
            _spd_switch = true; // 速度方向切替フラグ
        }

        switch (i)
        {
        case 0:
            x2 += adx;
            y2 += ady;
            break;
        case 1:
            x2 -= adx;
            y2 -= ady;
            break;
        case 2:
            x2 += adx;
            y2 -= ady;
            break;
        case 3:
            x2 -= adx;
            y2 += ady;
            break;
        }

        line(x, y, x2, y2);
        x = x2;
        y = y2;
    }
};

Sphere lines[L_NUM];
int spd_min = SPD_MIN;
int spd_max = SPD_MAX;

void setup()
{
    size(WIDTH, HEIGHT);
    background(BACKCOLOR);
    stroke(L_COLOR);
    strokeWeight(1);

    double set_x = 100;
    double set_y = 100;

    for (int i = 0; i < L_NUM; i++) {
        lines[i].Setup(i, set_x, set_y);
    }
}

void draw()
{
    background(BACKCOLOR, BACKALPHA);

    // 速度範囲の切替
    if (_spd_switch) {
        if ((int)random(2) == 0) {
            spd_min = SPD_MIN;
            spd_max = SPD_MAX;
        }
        else {
            spd_min = -SPD_MAX;
            spd_max = -SPD_MIN;
        }
        _spd_switch = false;
    }

    // 切り替えた範囲でランダム速度生成
    double adx = random(spd_min, spd_max);
    double ady = random(spd_min, spd_max);

    for (int i = 0; i < L_NUM; i++) {
        lines[i].Draw(i, adx, ady);
    }
}
