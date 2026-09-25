#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int LINE_GRAY = 255;
const int LINE_SPD = 2;
const int MIN_DIA = 100;
const int MAX_DIA = 300;
const int WALL_HEIGHT = 10;

struct Line {
	Vector2 pos;
	Vector2 vec;
};

struct Wall {
	Vector2 pos;
	int width = 0;
	int height = WALL_HEIGHT;
};

Line _line;
std::list<Wall> _walls;

bool hitWallPoint( const Vector2& a, const Vector2& b, const Vector2& p ) {
	bool hit = false;
	double lx = 0;
	double rx = 0;

	if ( a.x < b.x ) {
		lx = a.x;
		rx = b.x;
	} else {
		lx = b.x;
		rx = a.x;
	}

	if ( p.x >= lx - WALL_HEIGHT && p.x <= rx + WALL_HEIGHT ) {
		double liney = ( a.y + b.y ) * 0.5;
		if ( abs( p.y - liney ) <= WALL_HEIGHT ) {
			hit = true;
		}
	}

	return hit;
}

void drawLine( ) {
	Vector2 old_pos = _line.pos;
	_line.pos += _line.vec;

	if ( _line.pos.x > WIDTH || _line.pos.x < 0 ) {
		_line.vec.x *= -1;
	}
	if ( _line.pos.y > HEIGHT || _line.pos.y < 0 ) {
		_line.vec.y *= -1;
	}

	line( old_pos.x, old_pos.y, _line.pos.x, _line.pos.y );
}

void drawWall( ) {
	std::list<Wall>::iterator it = _walls.begin( );
	while ( it != _walls.end( ) ) {
		Wall& wall = *it;
		rect( wall.pos.x, wall.pos.y, wall.width, WALL_HEIGHT );

		Vector2 left = wall.pos - Vector2 { ( double )wall.width * 0.5,0 };
		Vector2 right = wall.pos + Vector2 { ( double )wall.width * 0.5,0 };
		if ( hitWallPoint( left, right, _line.pos ) ) {
			_line.vec.y *= -1;
			if ( _line.vec.y > 0 ) {
				_line.pos.y = wall.pos.y + WALL_HEIGHT;
			} else {
				_line.pos.y = wall.pos.y - WALL_HEIGHT;
			}
		}

		it++;
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
	noFill( );
	stroke( LINE_GRAY);

	_line.pos = Vector2 { WIDTH * 0.5,HEIGHT * 0.5 };
	_line.vec = Vector2 { LINE_SPD,0 }.rotate( random( PI2 ) );
}

void draw( ) {
	drawWall( );
	drawLine( );
}

void mouseClicked( ) {
	Vector2 mpos { ( double )getMouseX( ),( double )getMouseY( ) };
	Wall w;
	w.pos = mpos;
	w.width = ( int )random( MIN_DIA, MAX_DIA );
	_walls.push_back( w );
}
