#include "Processing.h"




const int WIDTH = 1000;

const int HEIGHT = 1000;

const int CENTER_X = WIDTH / 2;

const int CENTER_Y = HEIGHT / 2;

const int ELLIPSE_DIAMETER = 100;

const double NOICEMULTIPL = 0.02;

const double RGBMULTIPL = 450;

const int BACKGROUNDGRAYSCALE = 3;

double _x;

double _y;

double _last_x;

double _last_y;

int _r, _g, _b ;

int _r_2, _g_2, _b_2;

double _backgroundcolor = 0;


void setup() {

    size(WIDTH, HEIGHT);

    background( _backgroundcolor );

    noStroke( );

    _x = CENTER_X;

    _y = CENTER_Y;
}


void draw( ) {

    _r = noise( _x * NOICEMULTIPL ) * RGBMULTIPL;

    _g = noise( _y * NOICEMULTIPL ) * RGBMULTIPL;

    _b = noise( ( _x + _y ) * NOICEMULTIPL ) * RGBMULTIPL;

    _x += ( ( getMouseX( ) - _last_x ) > 0 ) ? random( 1, 10 ) : random( -1, -10 );

    _y += ( ( getMouseY( ) - _last_y ) > 0 ) ? random( 1, 10 ) : random( -1, -10 );

    fill( _r, _g, _b );

    ellipse( _x, _y, ELLIPSE_DIAMETER );

    ellipse( -_x + WIDTH, -_y + HEIGHT, ELLIPSE_DIAMETER );

    fill( _g, _b, _r );

    ellipse( _x, -_y + HEIGHT, ELLIPSE_DIAMETER );
    
    ellipse( -_x + WIDTH, _y, ELLIPSE_DIAMETER );

    _last_x = _x;

    _last_y = _y;

    background(_backgroundcolor, BACKGROUNDGRAYSCALE );
}


