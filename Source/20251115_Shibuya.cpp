#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int HALF_WIDTH = WIDTH / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 2;
const int MAX_H = 255;
const int COLOR_S = 100;
const int COLOR_B = 100;
const int ALPHA = 1;
const int TIMER = 15;
const int SPEED = 5;
const int HEIGHT_GAP = WIDTH;

int _frame_count = 0;

struct ColLine {
	int x1 = ( int )random( WIDTH );
	int x2 = ( int )random( WIDTH );
	int y1 = -HEIGHT_GAP;
	int y2 = HEIGHT + HEIGHT_GAP;
	int weight = 1;
	int h = ( int )random( MAX_H );
};

std::list<ColLine> _lines;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, COLOR_S, COLOR_B );
	blendMode( ADD );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	if ( _frame_count % TIMER == 0 ) {
		_lines.emplace_back( );
	}

	auto it = _lines.begin( );
	while ( it != _lines.end( ) ) {
		it->weight += SPEED;
		stroke( it->h, COLOR_S, COLOR_B, ALPHA );
		strokeWeight( it->weight );
		line( it->x1, it->y1, it->x2, it->y2 );

		if ( it->weight > HALF_WIDTH ) {
			it = _lines.erase( it );
		} else {
			++it;
		}
	}

	_frame_count++;
}


