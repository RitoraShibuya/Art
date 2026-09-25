#include "Processing.h"
#include <vector>

const int WIDTH = 800;
const int HEIGHT = 800;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;

const int GAP = 200;   // 中心からの半径
const int R_NUM = 12;  // 棒の数
const int R_WID = 20;  // 棒の幅
const int MIN_H = 40;  // 最小高さ
const int MAX_H = 120; // 最大高さ
const double ROT_SPEED = 0.01; // 回転スピード（小さいほどゆっくり）

int frameCount;
float gridOffset = 0;          // 格子の縦方向オフセット
const float GRID_SPEED = 0.5;  // 格子が流れるスピード（小さいほどゆっくり）

struct Bar {
    double baseAng;  // 固有の角度
    double tx, ty;   // 位置
    double rot;      // 回転角度
    int height;      // 高さ

    void setup(int i) {
        baseAng = PI * 2 * i / (double)R_NUM;
        height = (int)random(MIN_H, MAX_H);
    }

    void update(int frame) {
        // 円周上の位置（時間で回転）
        double ang = baseAng + frame * ROT_SPEED;
        tx = CENTER_X + cos(ang) * GAP;
        ty = CENTER_Y + sin(ang) * GAP;
        rot = ang + PI / 2;

        // 高さをランダムに ±3 変動（範囲内に収める）
        int delta = ( (int)random(2) == 1 ? -3 : 3 );
        height += delta;
        if (height < MIN_H) height = MIN_H;
        if (height > MAX_H) height = MAX_H;
    }

    void draw( ) {
        translate(tx, ty);
        rotate(rot);

        fill(255, 200, 0);
        rect(0, 0, R_WID, height);

        rotate(-rot);
        translate(-tx, -ty);
    }
};

Bar bars[ R_NUM ];

void setup( ) {
    size(WIDTH, HEIGHT);
    rectMode(CENTER);
    noStroke( );
    for (int i = 0; i < R_NUM; i++) bars[ i ].setup(i);
}

void draw( ) {
    background(0,10);

    // 白い格子線（下に流れる）
    stroke(255);
    strokeWeight(1);
    for (int x = 0; x < WIDTH; x += 50) {
        line(x, 0, x, HEIGHT);
    }
    for (int y = -50; y < HEIGHT + 50; y += 50) {
        line(0, y + gridOffset, WIDTH, y + gridOffset);
    }

    // オフセット更新
    gridOffset += GRID_SPEED;
    if (gridOffset >= 100) gridOffset = 0; // タイル状にループ

    // 棒の描画
    blendMode(MULTIPLY);
    for (int i = 0; i < R_NUM; i++) {
        bars[ i ].update(frameCount);
        bars[ i ].draw( );
    }
    blendMode(BLEND);

    frameCount++;
}
