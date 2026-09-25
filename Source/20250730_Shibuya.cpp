#include "Processing.h"
#include <algorithm>  // std::min, std::max を使うため

const int WIDTH = 1000;   // 画面幅
const int HEIGHT = 1000;  // 画面高さ

const int COLS = 25;      // 横方向のセル数
const int ROWS = 25;      // 縦方向のセル数
const float JITTER = 0.3; // 頂点のランダムな揺らぎ（セルサイズの割合）

// 2D座標を表す構造体
struct Vec2 {
    float x;
    float y;
};

// constrain関数の代替。値を[minVal, maxVal]の範囲に制限
float constrain(float val, float minVal, float maxVal) {
    return std::min(std::max(val, minVal), maxVal);
}

void setup() {
    size(WIDTH, HEIGHT);  // 画面サイズ設定
    stroke(0);            // 線の色を黒に
    strokeWeight(5);      // 線の太さを5に

    // セルの幅と高さを計算
    float cellW = (float)WIDTH / COLS;
    float cellH = (float)HEIGHT / ROWS;

    // 頂点座標を保存する2次元配列。セルの区切りで頂点は (COLS+1) x (ROWS+1) 個
    Vec2 pts[COLS + 1][ROWS + 1];

    // 各頂点をランダムに揺らしながら配置
    for (int i = 0; i <= COLS; i++) {
        for (int j = 0; j <= ROWS; j++) {
            // 基本の格子点に対し、x,y方向にセル幅・高さの±JITTER分だけランダムにずらす
            float x = i * cellW + random(-cellW * JITTER, cellW * JITTER);
            float y = j * cellH + random(-cellH * JITTER, cellH * JITTER);

            // 画面外に出ないように制限
            x = constrain(x, 0, WIDTH);
            y = constrain(y, 0, HEIGHT);

            pts[i][j] = { x, y };
        }
    }

    // 各セルごとに2つの三角形に分割して描画
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            // セルの4つの頂点を取得
            Vec2 p00 = pts[i][j];       // 左上
            Vec2 p10 = pts[i + 1][j];   // 右上
            Vec2 p01 = pts[i][j + 1];   // 左下
            Vec2 p11 = pts[i + 1][j + 1]; // 右下

            // 対角線の向きをランダムに変えてステンドグラスのような不規則さを演出
            if (random(1) < 0.5) {
                fill(random(255), random(255), random(255), 200);  // 半透明のランダムカラー
                triangle(p00.x, p00.y, p10.x, p10.y, p11.x, p11.y); // 上→右→右下
                fill(random(255), random(255), random(255), 200);
                triangle(p00.x, p00.y, p11.x, p11.y, p01.x, p01.y); // 上→右下→下
            }
            else {
                fill(random(255), random(255), random(255), 200);
                triangle(p00.x, p00.y, p10.x, p10.y, p01.x, p01.y); // 上→右→下
                fill(random(255), random(255), random(255), 200);
                triangle(p10.x, p10.y, p11.x, p11.y, p01.x, p01.y); // 右→右下→下
            }
        }
    }
}

void draw() {
    // 静止画なので何もしない
}
