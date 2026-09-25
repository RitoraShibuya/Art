#include "Processing.h"
#include <vector>
#include <cstdlib>
#include <ctime>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int DROPSPD = 4;

enum ShapeType { CIRCLE, RECTANGLE, TRIANGLE };

struct FallingShape {
    int x, y;
    int size;
    ShapeType type;
    bool stop;

    void setup(int startX) {
        x = startX;
        y = -100;
        size = 60;
        stop = false;
        type = (ShapeType)(rand() % 3); // ƒ‰ƒ“ƒ_ƒ€‚ÈŒ`
    }

    int left()   const { return x - size / 2; }
    int right()  const { return x + size / 2; }
    int top()    const { return y - size / 2; }
    int bottom() const { return y + size / 2; }

    void update(int groundY) {
        if (stop) return;
        int desiredY = groundY - size / 2;
        if (y < desiredY) {
            int nextY = y + DROPSPD;
            if (nextY > desiredY) nextY = desiredY;
            y = nextY;
        }
        if (y >= desiredY) {
            y = desiredY;
            stop = true;
        }
    }

    void draw() const {
        stroke(0);
        fill(0); // ”’‚Å“h‚è‚Â‚Ô‚·
        if (type == CIRCLE) {
            ellipse(x, y, size, size);
        } else if (type == RECTANGLE) {
            rectMode(CENTER);
            rect(x, y, size, size);
        } else { // TRIANGLE
            beginShape();
            vertex(x, y - size / 2);
            vertex(x - size / 2, y + size / 2);
            vertex(x + size / 2, y + size / 2);
            endShape(CLOSE);
        }
    }
};

std::vector<FallingShape> shapes;

void drawNoiseBackground() {
    float scale = 0.01; // ƒmƒCƒY‚Ì‘e‚³
    loadPixels();
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            float n = noise(x * scale, y * scale) * 255;
            stroke(n);
            point(x, y);
        }
    }
}

void setup() {
    size(WIDTH, HEIGHT);
    srand((unsigned)time(NULL));
    background(0);
    drawNoiseBackground(); // ˆê“x‚¾‚¯•`‰æ‚µ‚Ä”wŒi¶¬
}

void draw() {
    background(0);
    
    drawNoiseBackground();
    
    blendMode(MULTIPLY);
    for (int i = 0; i < (int)shapes.size(); ++i) {
        int groundY = HEIGHT;
        for (int j = 0; j < (int)shapes.size(); ++j) {
            if (i == j) continue;
            if (!shapes[j].stop) continue;
            if (shapes[i].right() > shapes[j].left() &&
                shapes[i].left() < shapes[j].right()) {
                int topOfJ = shapes[j].top();
                if (topOfJ < groundY) groundY = topOfJ;
            }
        }
        int minAllowed = shapes[i].size / 2;
        if (groundY < minAllowed) groundY = minAllowed;
        shapes[i].update(groundY);
    }
    for (const auto& s : shapes) s.draw();
    blendMode(BLEND);
    
    
    
}

void mouseClicked() {
    FallingShape newS;
    newS.setup(getMouseX());
    shapes.push_back(newS);
}
