#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int E_NUM = 5;
const int MAX_DIA = 200;
const int SPD = 3;
const int p_dia = 100;

int Framecount;

struct ColEllipse {
    int x, y;
    int dia;
    int r, g, b;
    int rad;
};

ColEllipse balls[E_NUM];

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKCOL);
    noStroke();

    for (int i = 0; i < E_NUM; i++) {
        balls[i].x = (int)random(MAX_DIA, WIDTH - MAX_DIA);
        balls[i].y = (int)random(MAX_DIA, HEIGHT - MAX_DIA);
        balls[i].dia = (int)random(50, MAX_DIA);  // 50以上で見やすく
        balls[i].rad = (int)random(360);
    }

    Framecount = 0;
}

void draw() {
    background(BACKCOL);

    int mx = getMouseX();
    int my = getMouseY();

    // プレイヤーの円
    fill(255);
    ellipse(mx, my, p_dia, p_dia);

    for (int i = 0; i < E_NUM; i++) {
        int h_dia = balls[i].dia / 2;

        // ノイズカラー
        balls[i].r = (int)map(noise(balls[i].x * 0.05, balls[i].y * 0.05, Framecount * 0.01), 0.0, 1.0, 0, 255);
        balls[i].g = (int)map(noise(balls[i].x * 0.05 + i * 100, balls[i].y * 0.05, Framecount * 0.01), 0.0, 1.0, 0, 255);
        balls[i].b = (int)map(noise(balls[i].x * 0.05, balls[i].y * 0.05 + i * 100, Framecount * 0.01), 0.0, 1.0, 0, 255);

        fill(balls[i].r, balls[i].g, balls[i].b);
        ellipse(balls[i].x, balls[i].y, balls[i].dia, balls[i].dia);

        // 移動
        balls[i].x += cos(radians(balls[i].rad)) * SPD;
        balls[i].y += sin(radians(balls[i].rad)) * SPD;

        // 壁反射
        if (balls[i].x < h_dia) {
            balls[i].x = h_dia;               // 押し戻す
            balls[i].rad = 180 - balls[i].rad; // 反射
        }
        else if (balls[i].x > WIDTH - h_dia) {
            balls[i].x = WIDTH - h_dia;
            balls[i].rad = 180 - balls[i].rad;
        }

        // Y方向の壁チェック
        if (balls[i].y < h_dia) {
            balls[i].y = h_dia;
            balls[i].rad = -balls[i].rad;
        }
        else if (balls[i].y > HEIGHT - h_dia) {
            balls[i].y = HEIGHT - h_dia;
            balls[i].rad = -balls[i].rad;
        }


        // プレイヤーとの当たり判定
        int dx = balls[i].x - mx;
        int dy = balls[i].y - my;
        int gap = sqrt(dx * dx + dy * dy);

        if (gap < (h_dia + p_dia / 2)) {
            // 衝突 → 反射
            balls[i].rad = 180 + balls[i].rad;
            while (gap < balls[i].dia)
            {
                balls[i].x += cos(radians(balls[i].rad)) * SPD;
                balls[i].y += sin(radians(balls[i].rad)) * SPD;
                dx = balls[i].x - mx;
                dy = balls[i].y - my;
                gap = sqrt(dx * dx + dy * dy);
            }

        }
    }

    Framecount++;
}
