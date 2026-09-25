#include "Processing.h"
#include <math.h>

const int WIDTH = 1920;
const int HEIGHT = 1080;

double t = 0;   // 時間パラメータ

// 値を段階化する関数
double quantize( double v, int steps ) {
    return floor( v * steps ) / steps;  // 0〜1 を steps 段階に分割
}

void setup( ) {
    size( WIDTH, HEIGHT );
    setFrameRate( 60 );
}

void draw( ) {
    background( 0 );

    for ( int y = 0; y < HEIGHT; y++ ) {
        for ( int x = 0; x < WIDTH; x++ ) {
            double scale = 0.01;

            double r = noise( x * scale, y * scale, t );
            double g = noise( x * scale + t, y * scale, t );
            double b = noise( x * scale, y * scale + t, t );

            // ===== カラフルな境界処理 =====
            r = quantize( r, 4 );  // 4段階
            g = quantize( g, 4 );
            b = quantize( b, 4 );

            int R = ( int )( r * 255 );
            int G = ( int )( g * 255 );
            int B = ( int )( b * 255 );

            stroke( R, G, B );
            point( x, y );
        }
    }

    t += 0.05;  // 動きをゆっくり
}
