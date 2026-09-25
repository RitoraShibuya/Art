#include "Processing.h"

#define TWO_PI 6.28318530718 

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_DOT_SIZE = 100;
const int NUM_BOXES = 10;
const int NUM_CIRCLES = 20;
const int CIRCLE_RADIUS_MIN = CENTER_DOT_SIZE / 4;
const int CIRCLE_RADIUS_MAX = CENTER_DOT_SIZE / 2;
const int SPREAD_RADIUS = 100;

// 四角形の構造体
struct MovingBox {
    double x;
    double y;
    double r, g, b;

    void init(double px, double py) {
        x = px;
        y = py;
        randomColor();
    }

    void randomColor() {
        switch ((int)random(1, 5)) {
        case 1: r = 255; g = 0; b = 0; break;
        case 2: r = 0; g = 255; b = 0; break;
        case 3: r = 0; g = 0; b = 255; break;
        case 4: r = 0; g = 0; b = 0; break;
        }
    }

    void update() {
        x += random(-CENTER_DOT_SIZE, CENTER_DOT_SIZE);
        y += random(-CENTER_DOT_SIZE, CENTER_DOT_SIZE);
        if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT) {
            x = WIDTH / 2;
            y = HEIGHT / 2;
            randomColor();
        }
    }

    void draw() {
        fill(r, g, b,50);
        rect(x, y, CENTER_DOT_SIZE, CENTER_DOT_SIZE);

        // 周囲の白い円
        fill(255);
        for (int i = 0; i < NUM_CIRCLES; i++) {
            double angle = random(TWO_PI);
            double dist = random(CENTER_DOT_SIZE / 2 + 10, SPREAD_RADIUS);
            double cx = x + cos(angle) * dist;
            double cy = y + sin(angle) * dist;
            double radius = random(CIRCLE_RADIUS_MIN, CIRCLE_RADIUS_MAX);
            rect(cx, cy, radius, radius);
        }
    }
};

MovingBox boxes[NUM_BOXES];

void setup() {
    size(WIDTH, HEIGHT);
    background(255);
    noStroke();
    setFrameRate(10);

    // 複数のボックスを初期化
    for (int i = 0; i < NUM_BOXES; i++) {
        boxes[i].init(random(WIDTH), random(HEIGHT));
    }
}

void draw() {
    // 毎フレーム、全ての四角を更新・描画
    for (int i = 0; i < NUM_BOXES; i++) {
        boxes[i].update();
        boxes[i].draw();
    }
}
