#include "Processing.h"

const int WIDTH = 800;
const int HEIGHT = 800;
const int NUM_SHAPES = 200;
const int LIGHT_RADIUS = 150;

struct Shape {
    float x, y, r;
    int red, green, blue;
};

Shape shapes[ NUM_SHAPES ];

void setup( ) {
    size(WIDTH, HEIGHT);
    noStroke( );

    // ランダムな図形を配置
    for (int i = 0; i < NUM_SHAPES; i++) {
        shapes[ i ].x = random(WIDTH);
        shapes[ i ].y = random(HEIGHT);
        shapes[ i ].r = random(20, 60);
        shapes[ i ].red = (int)random(255);
        shapes[ i ].green = (int)random(255);
        shapes[ i ].blue = (int)random(255);
    }
}

void draw( ) {
    background(0); // 真っ暗

    float mx = getMouseX( );
    float my = getMouseY( );

    // 懐中電灯の範囲内だけ描画
    for (int i = 0; i < NUM_SHAPES; i++) {
        float dx = mx - shapes[ i ].x;
        float dy = my - shapes[ i ].y;
        float d = sqrt(dx * dx + dy * dy);

        if (d < LIGHT_RADIUS) {
            // マウスが近いものだけ表示
            fill(shapes[ i ].red, shapes[ i ].green, shapes[ i ].blue);
            ellipse(shapes[ i ].x, shapes[ i ].y, shapes[ i ].r, shapes[ i ].r);
        }
    }

    // 懐中電灯の輪郭を薄く描画（光の円っぽく）
    noFill( );
    ellipse(mx, my, LIGHT_RADIUS * 2, LIGHT_RADIUS * 2);
}
