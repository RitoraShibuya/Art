#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_R = 0;
const int BACK_G = 255;
const int BACK_B = 0;
const int DEF_SPD = 5;
const int DEF_DIA = 300;
const int P_DIA = 100;

int mx, my, collx1, collx2, colly1, colly2;

struct Pinpon;
void Hit(Pinpon& p);

struct Pinpon {
    int x, y, dia, spd;
    double ang;

    void Setup(int px = 500, int py = 500, int d = DEF_DIA, int s = DEF_SPD) {
        x = px;
        y = py;
        dia = d;
        spd = s;
        ang = radians(random(360));
    }

    void Update() {
        // 移動
        x += cos(ang) * spd;
        y += sin(ang) * spd;

        // 壁に当たったら反射
        if (x < dia / 2 || x > WIDTH - dia / 2) {
            ang = PI - ang;
        }
        if (y < dia / 2 || y > HEIGHT - dia / 2) {
            ang = -ang;
        }

        // coll に当たったら分裂
        if (( x > collx1 && x < collx2 ) && ( y > colly1 && y < colly2 )) {
            Hit(*this);
        }
    }

    void Draw() {
        if (dia > 0) {
            fill(0,255,0);
            ellipse(x, y, dia, dia);
        }
    }
};

std::vector<Pinpon> g_rects;

// --- Hit 関数（外部）---
void Hit(Pinpon& p) {
    if (p.dia > 20) { // 最小サイズ制限
        // 左方向
        Pinpon newP1;
        newP1.Setup(p.x, p.y, p.dia / 2, p.spd * 2);
        newP1.ang = p.ang + HALF_PI;

        // 右方向
        Pinpon newP2;
        newP2.Setup(p.x, p.y, p.dia / 2, p.spd * 2);
        newP2.ang = p.ang - HALF_PI;

        g_rects.push_back(newP1);
        g_rects.push_back(newP2);
    }
    // 元の玉は消える
    p.dia = 0;
}

// --- setup ---
void setup() {
    size(WIDTH, HEIGHT);
    background(0);
    rectMode(CENTER);

    Pinpon P;
    P.Setup();
    g_rects.push_back(P);
}

// --- draw ---
void draw() {
    background(0);

    for (int i = 0; i < g_rects.size(); i++) {
        if (g_rects[i].dia > 0) {
            g_rects[i].Update();
            g_rects[i].Draw();
        }
    }

    // 全滅したらランダム位置から 1 個再生成
    bool allDead = true;
    for (int i = 0; i < g_rects.size(); i++) {
        if (g_rects[i].dia > 0) {
            allDead = false;
            break;
        }
    }
    if (allDead) {
        Pinpon P;
        P.Setup(random(WIDTH), random(HEIGHT), DEF_DIA, DEF_SPD);
        g_rects.clear();
        g_rects.push_back(P);
    }

    // coll 四角の描画
    fill(0,255,0);
    rect(mx, my, P_DIA, P_DIA);
}

// --- マウス操作 ---
void mousePressed() {
    mx = getMouseX();
    my = getMouseY();
    collx1 = mx - ( P_DIA / 2 );
    collx2 = mx + ( P_DIA / 2 );
    colly1 = my - ( P_DIA / 2 );
    colly2 = my + ( P_DIA / 2 );
}
