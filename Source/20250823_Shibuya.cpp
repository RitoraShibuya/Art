#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int P_NUM = 20;
const int INTERVAL = 60;  // 何フレームごとに目的地を更新するか

void update( );
void drawsphere( );

struct PointData {
    double x, y;   // 現在位置
    double tx, ty; // 目標位置
    double vx, vy; // 移動速度
};

PointData points[ P_NUM ];

int framecount = 0;

// 移動候補の座標
int P_x[ 5 ] = { 100, WIDTH * 1 / 4, WIDTH * 1 / 2, WIDTH * 3 / 4, 900 };
int P_y[ 5 ] = { 100, HEIGHT * 1 / 4, HEIGHT * 1 / 2, HEIGHT * 3 / 4, 900 };

void setup( ) {
    size( WIDTH, HEIGHT );
    background( BACKCOLOR );
    stroke( 255 );
    strokeWeight( 3 );
    noFill( );
    setFrameRate( 30 );

    // 初期位置をランダムに決める
    for (int i = 0; i < P_NUM; i++) {
        points[ i ].x = random( WIDTH );
        points[ i ].y = random( HEIGHT );
        points[ i ].tx = points[ i ].x;
        points[ i ].ty = points[ i ].y;
        points[ i ].vx = 0;
        points[ i ].vy = 0;
    }
}

void draw( ) {
    background( BACKCOLOR ,50);
    update( );
    drawsphere( );
    framecount++;
}

void update( ) {
    if (framecount % INTERVAL == 0) {
        // 各点に新しい目標と速度を設定
        for (int i = 0; i < P_NUM; i++) {
            points[ i ].tx = P_x[ (int)random( 5 ) ];
            points[ i ].ty = P_y[ (int)random( 5 ) ];
            points[ i ].vx = ( points[ i ].tx - points[ i ].x ) / INTERVAL;
            points[ i ].vy = ( points[ i ].ty - points[ i ].y ) / INTERVAL;
        }
    }

    // 位置を更新
    for (int i = 0; i < P_NUM; i++) {
        points[ i ].x += points[ i ].vx;
        points[ i ].y += points[ i ].vy;
    }
}

void drawsphere( ) {
    beginShape( );
    for (int i = 0; i < P_NUM; i++) {
        vertex( points[ i ].x, points[ i ].y );
    }
    endShape( CLOSE );
}
