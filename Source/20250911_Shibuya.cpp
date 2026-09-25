#include "Processing.h"

const int WIDTH = 800;
const int HEIGHT = 800;
const int NUM = 20;          // ‰~‚Ì”
const int E_RADIUS = 100;     // ”¼Œa
const double NOISE_SCALE = 0.01;

struct Ball {
    double x, y, spd;

    void reset( ) {
        x = random( WIDTH );
        y = random( -200, 0 );
        spd = random( 2, 6 );
    }

    void update( ) {
        y += spd;
        if ( y - E_RADIUS > HEIGHT ) reset( );
    }

    void draw( ) {
        ellipse( x, y, E_RADIUS * 2, E_RADIUS * 2 );
    }
};

Ball balls[ NUM ];

void setup( ) {
    size( WIDTH, HEIGHT );
    noStroke( );
    for ( int i = 0; i < NUM; i++ ) balls[ i ].reset( );
}

void draw( ) {
    background( 0 );

    // 1. •‚¢ƒ}ƒXƒN‚ð—pˆÓiŽÀÛ‚Í•”wŒi‚È‚Ì‚ÅÈ—ª‰Âj
    fill( 0 );
    rect( 0, 0, WIDTH, HEIGHT );

    // 2. ‰~‚ðu”’v‚Å“h‚Á‚Ä‚¨‚­
    fill( 255 );
    for ( int i = 0; i < NUM; i++ ) {
        balls[ i ].update( );
        balls[ i ].draw( );
    }

    // 3. ‚»‚Ìã‚É–Í—l‚ð MULTIPLY
    blendMode( MULTIPLY );
    for ( int y = 0; y < HEIGHT; y += 5 ) {
        for ( int x = 0; x < WIDTH; x += 5 ) {
            int r = noise( x * NOISE_SCALE, y * NOISE_SCALE ) * 500;
            int g = noise( x * NOISE_SCALE + 100, y * NOISE_SCALE ) * 500;
            int b = noise( x * NOISE_SCALE, y * NOISE_SCALE + 100 ) * 500;
            r = constrain( r, 0, 255 );
            g = constrain( g, 0, 255 );
            b = constrain( b, 0, 255 );
            fill( r, g, b );
            ellipse( x, y ,3);
        }
    }
    blendMode( BLEND );
}
