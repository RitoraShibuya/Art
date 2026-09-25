#include "Processing.h"
#include <vector>

#define TWO_PI 6.28318530718  // ← これをここに追加

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKKGROUNDCOLOR = 0;
const int BACKGROUNDGRAYSCALE = 5;
const double CENTER_X = WIDTH / 2;
const double CENTER_Y = HEIGHT / 2;
const int SPD = 10;
const int DIA = 2000;
const int INTERVAL = 10;
const int SETFRAME = 30;
const int LINEWEIGHT = 5;
const int ANG = 3;
const double RED = 255;
const double GREEN = 255;
const double BLUE = 255;

double _red, _green, _blue = 255;

struct _Circle {
    int x, y, size;
    double red = _red;
    double green = _green;
    double blue = _blue;

    void Reset() {
        x = CENTER_X;
        y = CENTER_Y;
        size = DIA;
        red = _red;
        green = _green;
        blue = _blue;
    }

    void drawCIRCLE() {
        stroke(red,green,blue);
        strokeWeight(LINEWEIGHT);
        noFill();

        int segments = 100;
        float radius = size / 2.0;

        beginShape();
        for (int i = 0; i <= segments; i++) {
            float angle = TWO_PI * i / segments;
            float px = x + cos(angle) * radius;
            float py = y + sin(angle) * radius;
            vertex(px, py);
        }
        endShape();
    }


    void Update() {
        size -= SPD;
    }

    bool isDead() {
        return size <= 0;
    }
};

struct _Rect {
    int x, y, size;
    float angle = 0;
    int ang_spd;
    double red;
    double green;
    double blue;

    void Reset() {
        x = CENTER_X;
        y = CENTER_Y;
        size = DIA;
        angle = 0;
        ang_spd = (int)random(ANG) - 1;
        red = _red;
        green = _green;
        blue = _blue;
    }

    void drawRECT() {
        stroke(red, green, blue);
        strokeWeight(LINEWEIGHT);
        noFill();
        float half = size / 2.0;
        float rad = angle * PI / 180.0;

        for (int i = 0; i < 4; i++) {
            float px1 = cos(rad + i * PI / 2) * half;
            float py1 = sin(rad + i * PI / 2) * half;
            float px2 = cos(rad + ((i + 1) % 4) * PI / 2) * half;
            float py2 = sin(rad + ((i + 1) % 4) * PI / 2) * half;
            line(x + px1, y + py1, x + px2, y + py2);
        }
    }

    void Update() {
        size -= SPD;
        angle += ang_spd;
    }

    bool isDead() {
        return size <= 0;
    }
};


struct _Tri {
    int x, y, size;
    float angle = 0;
    int ang_spd;
    double red;
    double green;
    double blue;

    void Reset() {
        x = CENTER_X;
        y = CENTER_Y;
        size = DIA;
        angle = 0;
        ang_spd = random(ANG) - 1;
        red = _red;
        green = _green;
        blue = _blue;
    }

    void drawTRI() {
        stroke(red, green, blue);
        strokeWeight(LINEWEIGHT);
        noFill();

        float half = size / 2.0;
        float rad = angle * PI / 180.0;
        float baseAngle = -PI / 2;

        float x1 = cos(baseAngle + rad) * half;
        float y1 = sin(baseAngle + rad) * half;

        float x2 = cos(baseAngle + 2 * PI / 3 + rad) * half;
        float y2 = sin(baseAngle + 2 * PI / 3 + rad) * half;

        float x3 = cos(baseAngle + 4 * PI / 3 + rad) * half;
        float y3 = sin(baseAngle + 4 * PI / 3 + rad) * half;

        beginShape();
        vertex(x + x1, y + y1);
        vertex(x + x2, y + y2);
        vertex(x + x3, y + y3);
        endShape(CLOSE);
    }

    void Update() {
        size -= SPD;
        angle += ang_spd;
    }

    bool isDead() {
        return size <= 0;
    }
};


std::vector<_Circle> circles;
std::vector<_Rect> rects;
std::vector<_Tri> tris;  

int frameCounter = 0;
double ang = 0;

void setup() {
    size(WIDTH, HEIGHT);
    background(BACKKGROUNDCOLOR);
    setFrameRate(SETFRAME);
}

void draw() {
    background(BACKKGROUNDCOLOR, BACKGROUNDGRAYSCALE);

    if (frameCounter % INTERVAL == 0) {
        switch ((int)random(1, 4)) {
        case 1: {
            _Circle newCircle;
            newCircle.Reset();
            circles.push_back(newCircle);
            break;
        }
        case 2: {
            _Rect newRect;
            newRect.Reset();
            rects.push_back(newRect);
            break;
        }
        case 3: {
            _Tri newTri;
            newTri.Reset();
            tris.push_back(newTri);
            break;
        }
        }
    }

    for (int i = 0; i < circles.size(); i++) {
        circles[i].drawCIRCLE();
        circles[i].Update();
    }

    for (int i = 0; i < rects.size(); i++) {
        rects[i].drawRECT();
        rects[i].Update();
    }

    for (int i = 0; i < tris.size(); i++) {
        tris[i].drawTRI();
        tris[i].Update();
    }

    for (int i = circles.size() - 1; i >= 0; i--) {
        if (circles[i].isDead()) {
            circles.erase(circles.begin() + i);
        }
    }

    for (int i = rects.size() - 1; i >= 0; i--) {
        if (rects[i].isDead()) {
            rects.erase(rects.begin() + i);
        }
    }

    for (int i = tris.size() - 1; i >= 0; i--) {
        if (tris[i].isDead()) {
            tris.erase(tris.begin() + i);
        }
    }

    _red = (int)map(sin(radians(ang)),-1,1,0,255);
    _green = (int)map(sin(radians(ang + 120)), -1, 1, 0, 255);
    _blue = (int)map(sin(radians(ang + 240)), -1, 1, 0, 255);

    frameCounter++;
    ang += 1;
}
