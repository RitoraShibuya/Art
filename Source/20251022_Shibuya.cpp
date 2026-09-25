#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CX = WIDTH / 2;
const int CY = HEIGHT / 2;
const int BACKCOL = 0;

struct Elem {
    float x, y;
    float ang;
    float gap;
    float freq;
    float speed;
};

Elem e1, e2, e3;

void setup( ) {
    size(WIDTH, HEIGHT);
    background(BACKCOL);
    stroke(255);
    strokeWeight(1);
    noFill( );

    e1 = { CX + 200, CY, 0, 200, 1, 1 };
    e2 = { e1.x, e1.y, 60, 200, 3, 1 };
    e3 = { e2.x, e2.y, 120, 100, 5, 2 };
}

void draw( ) {
    // 残像効果（透明度つき背景）
    fill(BACKCOL, 5);
    rect(0, 0, WIDTH, HEIGHT);

    // e1の回転
    e1.ang += e1.speed;
    e1.x = CX + cos(radians(e1.ang)) * e1.gap;
    e1.y = CY + sin(radians(e1.ang)) * e1.gap;

    // e2の回転
    e2.ang += e2.speed;
    float r2 = e2.gap * sin(radians(e2.freq * e2.ang));
    e2.x = e1.x + r2 * cos(radians(e2.ang * e2.freq));
    e2.y = e1.y + r2 * sin(radians(e2.ang * e2.freq));

    // e3の回転
    e3.ang += e3.speed;
    float r3 = e3.gap * cos(radians(e3.freq * e3.ang));
    e3.x = e2.x + r3 * cos(radians(e3.ang * 2));
    e3.y = e2.y + r3 * sin(radians(e3.ang * 2));

    // --- 線でつなぐ ---
    stroke(255);
    line(CX, CY, e1.x, e1.y);   // 中心からe1へ
    line(e1.x, e1.y, e2.x, e2.y); // e1からe2へ
    line(e2.x, e2.y, e3.x, e3.y); // e2からe3へ

    // 最終点を明示する点
    fill(255);
    ellipse(e3.x, e3.y, 1);
}
