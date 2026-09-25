#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOL = 0;
const int VERNUM = 5;

int framecount = 0;

void setup( ) {
    size( WIDTH, HEIGHT );
    background( BACKCOL );
    setFrameRate( 10 );
}

void draw( ) {
    stroke( 255 );
    strokeWeight( 20 );
    noFill( );

    int mx = getMouseX( );
    int my = getMouseY( );
    int dx = mx - CENTER_X;
    int dy = my - CENTER_Y;

    double baseang = atan2( dy, dx );
    double gap = sqrt( dx * dx + dy * dy );

    // 3‚Â‚Ì‘½ŠpŒ`‚ð•`‰æ
    for ( int c = 0; c < 3; c++ ) {
        beginShape( );
        for ( int i = 0; i < VERNUM; i++ ) {
            double ang = baseang + PI2 * i / VERNUM + PI2 * c / 3;
            int x = CENTER_X + cos( ang ) * gap * ( c + 1 );
            int y = CENTER_Y + sin( ang ) * gap * ( c + 1 );
            vertex( x, y );
        }
        endShape( CLOSE );
    }

    // ƒmƒCƒY”wŒi
    blendMode( MULTIPLY );
    noStroke( );
    for ( int x = 0; x < WIDTH; x += 10 ) {
        for ( int y = 0; y < HEIGHT; y += 10 ) {
            int r = noise( x * 0.01, y * 0.01, framecount * 0.01 ) * 255;
            int g = noise( x * 0.01 + 100, y * 0.01, framecount * 0.01 ) * 255;
            int b = noise( x * 0.01, y * 0.01 + 100, framecount * 0.01 ) * 255;
            fill( r, g, b );
            rect( x, y, 10, 10 );
        }
    }
    blendMode( BLEND );

    framecount++;
}
