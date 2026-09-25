#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 20;

const int RECT_R = 255;
const int RECT_G = 255;
const int RECT_B = 0;
const int RECT_G_MUL = 7;
const int DIR_NUM = 100;
const int GAP = 500;
const int RECT_WIDTH = 2;
const int RECT_HEIGHT = 10;
const int RECT_GAP = 15;
const double NOISE_RANGE = 0.05;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
	noStroke( );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	for ( int i = 0; i < DIR_NUM; i++ ) {
		double ang = PI2 * i / DIR_NUM;
		double n1 = ang * NOISE_RANGE;
		double n2 = i * NOISE_RANGE;
		double n3 = _frame_count * NOISE_RANGE;
		int noise_gap = noise( n1, n2, n3 ) * GAP;
		int num = noise_gap / RECT_GAP;
		rotate( ang );
		for ( int j = 0; j < num; j++ ) {
			int gap = ( j * RECT_GAP );
			int x = CENTER_X + cos( ang ) * gap;
			int y = CENTER_Y + sin( ang ) * gap;

			fill( RECT_R, RECT_G - j * RECT_G_MUL, RECT_B );
			rect( x, y, RECT_WIDTH, RECT_HEIGHT );
		}
		rotate( -ang );
	}

	_frame_count++;
}


