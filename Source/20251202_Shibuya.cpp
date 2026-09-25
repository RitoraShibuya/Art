#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int ALPHA = 10;
const int H_MAX = 360;
const int S_MAX = 100;
const int B_MAX = 100;

const int LIFE = 1200;
const int SPD = 1;
const int RANDOM_RANGE = 2;

double NOISE_RANGE = 0.1;
double FRAMERATE_NOISE_RANGE = 0.01;

struct ColPoint {
	int x = 0;
	int y = 0;
	int life = LIFE;
	double ang = 0;
};

int _frame_count = 0;

std::list<ColPoint> _points;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, H_MAX, S_MAX, B_MAX );
	blendMode( ADD );
}

void draw( ) {


	ColPoint p;
	if ( ( int )random( RANDOM_RANGE ) == 0 ) {
		p.x = WIDTH;
		p.y = ( int )random( HEIGHT );
	} else {
		p.x = ( int )random( WIDTH );
		p.y = HEIGHT;
	}
	double nx = p.x * NOISE_RANGE;
	double ny = p.y * NOISE_RANGE;
	p.ang = noise( nx, ny ) * TWO_PI;

	_points.push_back( p );

	std::list<ColPoint>::iterator it = _points.begin( );
	while ( it != _points.end( ) ) {
		if ( it->life < 0 ) {
			it = _points.erase( it );
		} else {
			it->x = it->x + cos( it->ang ) * SPD;
			it->y = it->y + sin( it->ang ) * SPD;
			double nx = it->x * NOISE_RANGE;
			double ny = it->y * NOISE_RANGE;
			double nl = it->life * NOISE_RANGE;
			double nf = _frame_count * FRAMERATE_NOISE_RANGE;
			it->ang = noise( nx, ny, nf ) * TWO_PI;

			int h = noise( nx, ny, nl ) * H_MAX;
			stroke( h, S_MAX, B_MAX, ALPHA );
			point( it->x, it->y );

			it->life--;
			it++;
		}
	}
	_frame_count++;
}
