#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 145;
const int SPAWN_NUM = 15;
const int SPAWN_INTERVAL = 30;
const int VER_NUM = 5;
const int MAX_GAP = 200;
const int GAP_SPD = 2;
const int COL_SPD = 3;
const double ANG_SPD = PI2 * 1 / 300;

struct Box {
	Vector2 center;
	int gap = 0;
	int col_h = 0;
	double base_ang;
};

int _frame_count = 0;
std::list<Box>_boxes;

void spawnBox( ) {
	Box b;
	b.center = Vector2( random( WIDTH ), random( HEIGHT ) );
	b.col_h = ( int )random( MAX_H );
	b.base_ang = random( PI2 );
	_boxes.push_back( b );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
}

void draw( ) {

	if ( _frame_count % SPAWN_INTERVAL  == 0) {
		spawnBox( );
	}

	std::list<Box>::iterator it = _boxes.begin( );
	while ( it != _boxes.end( ) ) {
		Box& box = *it;

		box.gap += GAP_SPD;
		box.base_ang += ANG_SPD;
		box.col_h = (box.col_h + COL_SPD) % MAX_H;

		stroke( box.col_h, MAX_S, MAX_B );

		beginShape( );
		for ( int i = 0; i < VER_NUM; i++ ) {
			double ang = box.base_ang + PI2 * i / VER_NUM;
			double x = box.center.x + cos( ang ) * box.gap;
			double y = box.center.y + sin( ang ) * box.gap;
			vertex( x, y );
		}
		endShape( CLOSE );

		if ( box.gap > MAX_GAP ) {
			it = _boxes.erase( it );
		} else {
			it++;
		}
	}
	_frame_count++;
}


