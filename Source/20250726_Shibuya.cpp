#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUNDCOLOR = 0;
const int BACKGROUNDCOLORGRAYSCALE = 5;

struct Ripple {
    double x, y;
    int frame; // アニメーション経過時間
};

std::vector<Ripple> ripples;

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKGROUNDCOLOR);
}

void draw() {
    background(BACKGROUNDCOLOR, BACKGROUNDCOLORGRAYSCALE);

    for (int i = 0; i < ripples.size(); ++i) {
        Ripple& r = ripples[i];
        double radius = r.frame * 4;

        noFill();
        stroke(255,0,0);
        strokeWeight(2);
        ellipse(r.x, r.y, radius, radius);

        r.frame++;
    }

    ripples.erase(
        std::remove_if(ripples.begin(), ripples.end(), [](const Ripple& r) {
            return r.frame > (int)random(15,180);
            }),
        ripples.end()
    );

}

void mouseClicked() {
    int x1 = (int)getMouseX();  // クリック位置X
    int y1 = (int)getMouseY();  // クリック位置Y

    ripples.push_back({ (double)x1, (double)y1, 0 });

    // 中心 (cx, cy) から (x1, y1) に向かうベクトル
    double cx = WIDTH / 2.0;
    double cy = HEIGHT / 2.0;
    double dx = x1 - cx;
    double dy = y1 - cy;

    // 正規化して大きく伸ばす
    double length = sqrt(dx * dx + dy * dy);
    dx /= length;
    dy /= length;

    // 線の両端を画面外に広げて描画
    double x0 = cx - dx * 2000;
    double y0 = cy - dy * 2000;
    double x2 = cx + dx * 2000;
    double y2 = cy + dy * 2000;

    stroke(255);
    strokeWeight(5);
    line((int)x0, (int)y0, (int)x2, (int)y2);
    if (random(2) == 1) {

        int randnum = (int)random(1000);

        double px0 = x1 + randnum + dy * 2000;
        double py0 = y1 + randnum - dx * 2000;
        double px2 = x1 - randnum - dy * 2000;
        double py2 = y1 - randnum + dx * 2000;

        line((int)px0, (int)py0, (int)px2, (int)py2 );
    }
}
