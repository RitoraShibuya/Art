#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACK_R = 50;
const int BACK_G = 50;
const int BACK_B = 50;
const int GRID_SIZE = 10;
const int MAX_GAP = 500;
const int CIRCLE_NUM = MAX_GAP / GRID_SIZE;
const int SPAWN_NUM = 100;
const int MAX_RGB = 255;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_B, BACK_G );
}

void draw( ) {
	Vector2 center( CENTER_X, CENTER_Y );

	for ( int i = 0; i < CIRCLE_NUM; i++ ) {
		int gap = i * GRID_SIZE;
		for ( int j = 0; j < SPAWN_NUM; j++ ) {
			double ang = PI2 * j / SPAWN_NUM;
			Vector2 pos = center + Vector2( gap, 0 ).rotate( ang );
			int col_r = j + _frame_count % MAX_RGB;
			int col_g = ( int )( pos.x ) % MAX_RGB;
			int col_b = ( int )( pos.y ) % MAX_RGB;

			stroke( col_r, col_b, col_g );
			ellipse( pos.x, pos.y, GRID_SIZE );
		}
	}
	_frame_count++;
}


