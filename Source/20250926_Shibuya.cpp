#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int SPD = 2;
const int LIFE = 180;             // 生存フレーム数
const double NOISERANGE = 0.01;

int Framecount;

class Col_Line {
    int x, y;
    int r, g, b;
    int bornFrame;
    double ang;

public:
    Col_Line(int mx, int my) {
        x = mx;
        y = my;
        ang = 0;
        bornFrame = Framecount;
    }

    void Update( ) {
        ang = radians(noise(x * NOISERANGE, y * NOISERANGE) * 360);
        x += sin(ang) * SPD;
        y += cos(ang) * SPD;
    }

    void Draw( ) {
        r = noise(x * NOISERANGE, y * NOISERANGE) * 255;
        g = noise(x * NOISERANGE + 100, y * NOISERANGE) * 255;
        b = noise(x * NOISERANGE, y * NOISERANGE + 100) * 255;
        stroke(r, g, b);
        point(x, y);
    }

    bool isDead( ) {
        return Framecount >= bornFrame + LIFE;
    }
};

std::vector<Col_Line*> points;

void setup( ) {
    size(WIDTH, HEIGHT);
    background(0);
    colorMode(HSB, 360, 100, 100);
    Framecount = 0;

    // 最初に1つ追加
    points.push_back(new Col_Line(WIDTH / 2, HEIGHT / 2));
}

void draw( ) {
    // 半透明の黒で残像を残す

    // 生き残りだけ残す
    std::vector<Col_Line*> alive;
    for (auto& p : points) {
        p->Update( );
        p->Draw( );
        if (!p->isDead( )) alive.push_back(p);
        else delete p;  // 死んだものは削除
    }
    points.swap(alive);

    Framecount++;
}

void mouseDragged( ) {
    // マウス位置から新しいラインを追加
    points.push_back(new Col_Line(getMouseX( ), getMouseY( )));
}
