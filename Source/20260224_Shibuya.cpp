#include "Processing.h"

const int WIDTH = 300;
const int HEIGHT = 300;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 25;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;

const int MAX_ITER = 30;
const int MAX_RANGE = 200;
const double SCALE_RANGE = 5.0;
const double ZOOM_SPD = 0.02;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	setFrameRate( 10 );
}

void draw( ) {
	background( BACKGROUND );

	Vector2 m_pos( getMouseX( ), getMouseY( ) );
	double zoom_scale = map( m_pos.getLength( ), 0, WIDTH + HEIGHT, 0, MAX_RANGE );
	double scale = SCALE_RANGE * exp( -ZOOM_SPD * zoom_scale );

	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double a = -0.75 + ( i - CENTER_X ) * scale / WIDTH;
			double b = 0.0 + ( j - CENTER_Y ) * scale / HEIGHT;

			double y = 0;
			double x = 0;
			int n = 0;
			while ( x * x + y * y <= 5 && n < MAX_ITER ) {
				double nx = x * x - y * y + a;
				y = 2 * x * y + b;
				x = nx;
				n++;
			}

			int col_h = ( int )map( n, 0, MAX_ITER, 0, MAX_H );

			stroke( col_h, MAX_S, MAX_B );
			point( i, j );
		}
	}
}


