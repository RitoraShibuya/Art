#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int R_SIZE = 5;
const double NOISERANGE = 0.01;

double cx, cy, vx, vy;
int radius;

void setup( ) {
    size(WIDTH, HEIGHT);
    noStroke( );

    // 初期位置をランダムに設定
    cx = random(WIDTH);
    cy = random(HEIGHT);

    // ランダムな角度を生成
    double ang = radians(random(360));
    vx = cos(ang) * 2.0;   // x方向速度
    vy = sin(ang) * 2.0;   // y方向速度
    radius = 100;         // 見える円の半径
}

void draw( ) {
    background(0);

    // 移動
    cx += vx;
    cy += vy;

    // 壁で反射（vx, vy を反転）
    if (cx - radius < 0 || cx + radius > WIDTH) {
        vx *= -1;
        vy += random(-0.5, 0.5);  // 少し斜めにずらす
    }
    if (cy - radius < 0 || cy + radius > HEIGHT) {
        vy *= -1;
        vx += random(-0.5, 0.5);
    }


    // 円の中だけ描画
    for (int y = 0; y < HEIGHT; y += R_SIZE) {
        for (int x = 0; x < WIDTH; x += R_SIZE) {
            double dx = x - cx, dy = y - cy;
            if (dx * dx + dy * dy <= radius * radius) {
                fill(noise(x * NOISERANGE, y * NOISERANGE) * 255,
                     noise(x * NOISERANGE + 100, y * NOISERANGE) * 255,
                     noise(x * NOISERANGE, y * NOISERANGE + 100) * 255);
                rect(x, y, R_SIZE, R_SIZE);
            }
        }
    }
}
