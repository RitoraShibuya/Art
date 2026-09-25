#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;

const int POINT_GRAY = 255;
const int POINT_SPD = -3;

struct Points {
	Vector2 pos = { 0,0 };
};

std::list<Points> _points;

void spawnPoints( ) {
	Points p;
	p.pos = Vector2( getMouseX( ), HEIGHT );
	_points.push_back( p );
}

void drawPoints( ) {
	std::list<Points>::iterator it = _points.begin( );
	Vector2 old_pos = it->pos;
	while ( it != _points.end( ) ) {
		it->pos += Vector2( 0, POINT_SPD );
		line( old_pos.x, old_pos.y, it->pos.x, it->pos.y );
		old_pos = it->pos;

		if ( it->pos.y < 0 ) {
			it = _points.erase( it );
		} else {
			it++;
		}
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( POINT_GRAY );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );
	spawnPoints( );
	drawPoints( );
}


