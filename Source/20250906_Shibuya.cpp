#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int VER_NUM = 6;
const int GAP = 200;

int vx[ VER_NUM ];
int vy[ VER_NUM ];
int rCol[ VER_NUM ], gCol[ VER_NUM ], bCol[ VER_NUM ];

void setup( ) {
    size(WIDTH, HEIGHT);
    background(BACKCOLOR);
    noStroke( );
    double ranang = random(-1, 1);
    for (int i = 0; i < VER_NUM; i++) {
        double ang = PI2 * i / VER_NUM;
        vx[ i ] = CENTER_X + cos(ang + ranang) * GAP;
        vy[ i ] = CENTER_Y + sin(ang + ranang) * GAP;

        // 頂点ごとに異なる色
        rCol[ i ] = (int)random(100, 255);
        gCol[ i ] = (int)random(100, 255);
        bCol[ i ] = (int)random(100, 255);
    }
}

void draw( ) {
    for (int i = 0; i < 200; i++) {
        int randver = (int)random(VER_NUM);
        int randsx = (int)random(-GAP, GAP / 5);
        int randsy = (int)random(-GAP, GAP / 5);

        int x = vx[ randver ] + randsx;
        int y = vy[ randver ] + randsy;

        int alpha = (int)random(30, 120);  // 半透明
        int size = (int)random(2, 6);      // 点の大きさ

        fill(rCol[ randver ], gCol[ randver ], bCol[ randver ], alpha);
        ellipse(x, y, size);
    }

    // 頂点を少し揺らす
    for (int i = 0; i < VER_NUM; i++) {
        vx[ i ] += (int)random(-1, 2);
        vy[ i ] += (int)random(-1, 2);
    }
}
