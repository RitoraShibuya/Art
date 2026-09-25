#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int P_NUM = 12;
const int P_SIZE = 5;   
const int GLID = 20;

const int START_X[ 4 ] = { 0, WIDTH, 0, WIDTH };
const int START_Y[ 4 ] = { 0, 0, HEIGHT, HEIGHT };
const int RED[ 4 ] = { 255, 0, 0, 0 };
const int GREEN[ 4 ] = { 0, 255, 0, 0 };
const int BLUE[ 4 ] = { 0, 0, 255, 0 };

struct ColP {
    int num, x, y, r, g, b;

    void Setup( int i ) {
        num =(int) i % 4;
        x = START_X[ num ];
        y = START_Y[ num ];
        r = RED[ num ];
        g = GREEN[ num ];
        b = BLUE[ num ];
    }

    void Draw( ) {
        fill( r, g, b, 10 );
        ellipse( x, y, P_SIZE);
    }

    void Update( ) {
        switch ( ( int )random( 4 ) ) {
        case 0: if ( x + GLID <= WIDTH )  x += GLID; break; // âEÇ÷
        case 1: if ( x - GLID >= 0 )      x -= GLID; break; // ç∂Ç÷
        case 2: if ( y + GLID <= HEIGHT ) y += GLID; break; // â∫Ç÷
        case 3: if ( y - GLID >= 0 )      y -= GLID; break; // è„Ç÷
        }
    }
};

ColP points[ P_NUM ];

void setup( ) {
    size( WIDTH, HEIGHT );
    background( BACKCOLOR );
    noStroke( );
    for ( int i = 0; i < P_NUM; i++ ) {
        points[ i ].Setup( i );
    }
}

void draw( ) {
    for ( int i = 0; i < P_NUM; i++ ) {
        points[ i ].Draw( );
        points[ i ].Update( );
    }
}
