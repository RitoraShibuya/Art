#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 245;
const int BACK_A = 10;
const int VER_NUM = 5;
const int MIN_WEIGHT = 10;
const int MAX_WEIGHT = 50;
const double ANG_SPD = PI2 * 1 / 300;

struct Box {
	int weight = 0;
	int gap = 0;
	int col_h = 0;
	int step = 1;
	double base_ang = 0;
};

int _frame_count = 0;
std::vector<Box> _boxes;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );

	int gap = 0;
	while ( gap < WIDTH + HEIGHT / 2 ) {
		Box b;
		b.weight = ( int )random( MIN_WEIGHT, MAX_WEIGHT );
		b.gap = gap + b.weight;
		b.col_h = ( int )random( MAX_H );
		b.step = ( int )( random( 2 ) ) * 2 - 1;
		b.base_ang = random( PI2 );
		_boxes.push_back( b );
		gap = b.gap + b.weight;

	}
}
void draw( ) {
	background( BACK_H, MAX_S, MAX_B, BACK_A );

	for ( Box& box : _boxes ) {
		box.base_ang += ANG_SPD * box.step;
		int col_h = ( box.col_h + _frame_count ) % MAX_H;
		beginShape( );
		stroke( col_h, MAX_S, MAX_B );
		strokeWeight( box.weight );

		for ( int i = 0; i < VER_NUM; i++ ) {
			double ang = box.base_ang + PI2 * i / VER_NUM;
			double x = CENTER_X + cos( ang ) * box.gap;
			double y = CENTER_Y + sin( ang ) * box.gap;
			vertex( x, y );
		}
		endShape( CLOSE );
	}
	_frame_count++;
}


