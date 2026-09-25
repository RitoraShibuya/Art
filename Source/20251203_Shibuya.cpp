#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int MAX_RGB = 255;
const int GRAY = 255;
const int ALPHA = 10;
const int GRID_SIZE = 20;
const int GRID_X_NUM = WIDTH / GRID_SIZE;
const int GRID_Y_NUM = HEIGHT / GRID_SIZE;

const int START_NUM = 10;
const int RANDOM_SECTION = 2;
const int MIN_DIA = 100;
const int MAX_DIA = 200;
const int MINUS_SPD_RANGE = -5;
const int MIN_SPD_RANGE = 1;
const int MAX_SPD_RANGE = 5;
const int COL_GAP = 300;

double NOISE_RANGE = 0.01;

struct ColSphere {
	int x = 0;
	int y = 0;
	int spdx = 0;
	int spdy = 0;
	int dia = MIN_DIA;
};

int _frame_count = 0;

std::list<ColSphere> _lens;

void createSphere( ) {
	ColSphere c;
	switch ( ( int )random( RANDOM_SECTION ) ) {
	case 0:
		c.x = ( int )random( WIDTH );
		c.spdx = ( int )random( MINUS_SPD_RANGE, MAX_SPD_RANGE );
		c.spdy = ( int )random( MIN_SPD_RANGE, MAX_SPD_RANGE );
		break;
	case 1:
		c.y = ( int )random( HEIGHT );
		c.spdx = ( int )random( MIN_SPD_RANGE, MAX_SPD_RANGE );
		c.spdy = ( int )random( MINUS_SPD_RANGE, MAX_SPD_RANGE );
		break;
	}
	c.dia = ( int )random( MIN_DIA, MAX_DIA );
	_lens.push_back( c );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );

	for ( int i = 0; i < START_NUM; i++ ) {
		createSphere( );
	}
}

void draw( ) {
	fill( GRAY, ALPHA );

	std::list<ColSphere>::iterator it = _lens.begin( );
	while ( it != _lens.end( ) ) {
		if ( it->x > WIDTH || it->y > HEIGHT ) {
			it = _lens.erase( it );
			createSphere( );
		} else {
			it->x += it->spdx;
			it->y += it->spdy;

			ellipse( it->x, it->y, it->dia );

			it++;
		}
	}

	blendMode( MULTIPLY );
	double nf = _frame_count * NOISE_RANGE;
	for ( int i = 0; i < GRID_X_NUM; i++ ) {
		int x = i * GRID_SIZE;
		double nx = x * NOISE_RANGE;
		for ( int j = 0; j < GRID_Y_NUM; j++ ) {
			int y = j * GRID_SIZE;
			double ny = y * NOISE_RANGE;
			double r = noise( nx, ny, nf ) * MAX_RGB;
			double g = noise( nx + COL_GAP, ny, nf ) * MAX_RGB;
			double b = noise( nx, ny + COL_GAP, nf ) * MAX_RGB;

			fill( r, g, b, ALPHA );
			rect( x, y, GRID_SIZE, GRID_SIZE );
		}
	}
	blendMode( BLEND );

	_frame_count++;
}


