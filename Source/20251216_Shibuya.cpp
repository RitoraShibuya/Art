#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 255;
const int GRID_SIZE = 5;
const int NUM_WIDTH = WIDTH / GRID_SIZE;
const int NUM_HEIGHT = HEIGHT / GRID_SIZE;
const int POINTS_NUM_SPAWN = 60;
const int MAX_LIFE = 20;

enum class GRID_TYPE {
	SKY,
	FOOTING,
};

struct Circle {
	Vector2 pos = { 0,0 };
	Vector2 vec = { 0,0 };
	int life = MAX_LIFE;
};

GRID_TYPE _grid[ NUM_WIDTH ][ NUM_HEIGHT ];
std::list <Circle> _points;

void initBack( ) {
	for ( int i = 0; i < NUM_WIDTH; i++ ) {
		for ( int j = 0; j < NUM_HEIGHT; j++ ) {
			_grid[ i ][ j ] = GRID_TYPE::SKY;
		}
	}
}

void spawnCircle( ) {
	int mx = getMouseX( );
	int my = getMouseY( );
	int gx = mx / GRID_SIZE;
	int gy = my / GRID_SIZE;

	if ( gx < 0 || gx >= NUM_WIDTH ||
		 gy < 0 || gy >= NUM_HEIGHT ) {
		return;
	}

	for ( int i = 0; i < POINTS_NUM_SPAWN; i++ ) {
		double ang = PI2 * i / POINTS_NUM_SPAWN;
		Circle p;
		p.pos = Vector2( gx, gy );
		p.vec = Vector2( 1, 0 ).rotate( ang );
		_points.push_back( p );
	}
}

void drawCircle( ) {
	std::list<Circle>::iterator it = _points.begin( );
	while ( it != _points.end( ) ) {
		Circle& point = *it;
		point.pos += point.vec;
		int px = ( int )point.pos.x;
		int py = ( int )point.pos.y;
		if ( px < 0 || px >= NUM_WIDTH ||
			 py < 0 || py >= NUM_HEIGHT ||
			 point.life <= 0 ) {
			it = _points.erase( it );
		} else {
			_grid[ px ][ py ] = GRID_TYPE::FOOTING;
			point.life--;
			it++;
		}
	}
}

void drawBack( ) {
	for ( int i = 0; i < NUM_WIDTH; i++ ) {
		for ( int j = 0; j < NUM_HEIGHT; j++ ) {
			GRID_TYPE type = _grid[ i ][ j ];
			int x = i * GRID_SIZE;
			int y = j * GRID_SIZE;
			switch ( type ) {
			case GRID_TYPE::SKY:
				fill( 255 );
				break;
			case GRID_TYPE::FOOTING:
				fill( 0 );
				break;
			}
			rect( x, y, GRID_SIZE, GRID_SIZE );
		}
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
	setFrameRate( 30 );

	initBack( );
}

void draw( ) {
	background( BACKGROUND );
	drawCircle( );
	drawBack( );
}

void mouseClicked( ) {
	spawnCircle( );
}


