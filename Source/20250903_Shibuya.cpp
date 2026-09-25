#include "Processing.h"

const int WIDTH = 800;
const int HEIGHT = 800;
const int SPOT_SIZE = 200;   // 窓の幅/高さ
const int SYM = 6;           // 万華鏡の対称数

void setup( ) {
    size(WIDTH, HEIGHT);
    noStroke( );
}

void draw( ) {
    background(0);

    // ==== 万華鏡模様生成 ====
    push( );
    translate(WIDTH / 2, HEIGHT / 2);
    float t = getFrameRate( ) * 0.01f;
    for (int i = 0; i < SYM; i++) {
        push( );
        rotate(PI2 * i / SYM);

        float x = cos(t * 2 + i) * 200 + noise(i * 0.2f, t) * 100;
        float y = sin(t * 3 + i) * 200 + noise(t, i * 0.2f) * 100;

        fill(
            150 + 105 * sin(t + i),
            150 + 105 * sin(t * 0.7f + i * 2),
            150 + 105 * sin(t * 1.3f + i * 3),
            200
        );

        ellipse(x, y, 40);
        pop( );
    }
    pop( );

    // === マウス窓周囲を覆う ===
    int mx = getMouseX( );
    int my = getMouseY( );

    fill(0, 220);  // 黒い幕

    // 窓の上下左右に四角を描くことで窓以外を覆う
    // 上
    rect(0, 0, WIDTH, my - SPOT_SIZE / 2);
    // 下
    rect(0, my + SPOT_SIZE / 2, WIDTH, HEIGHT - ( my + SPOT_SIZE / 2 ));
    // 左
    rect(0, my - SPOT_SIZE / 2, mx - SPOT_SIZE / 2, SPOT_SIZE);
    // 右
    rect(mx + SPOT_SIZE / 2, my - SPOT_SIZE / 2, WIDTH - ( mx + SPOT_SIZE / 2 ), SPOT_SIZE);

    // スポット枠を描く
    noFill( );
    stroke(255, 150);
    strokeWeight(2);
    rect(mx - SPOT_SIZE / 2, my - SPOT_SIZE / 2, SPOT_SIZE, SPOT_SIZE);
}
