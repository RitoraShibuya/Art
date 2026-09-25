#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int STONE_GRAY = 255;
const int STONE_DIA = 300;
const int STONE_SPD = 5;

struct Stone {
	Vector2 pos;
	Vector2 vec;
};

Stone _stone;

void drawStone( ) {
	_stone.pos += _stone.vec;
	if ( _stone.pos.x > WIDTH || _stone.pos.x < 0 ) {
		_stone.vec.x *= -1;
	}
	if ( _stone.pos.y > HEIGHT || _stone.pos.y < 0 ) {
		_stone.vec.y *= -1;
	}

	rect( _stone.pos.x, _stone.pos.y, STONE_DIA, STONE_DIA );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
	noFill( );
	stroke( STONE_GRAY );

	_stone.pos = Vector2( WIDTH / 2, HEIGHT / 2 );
	_stone.vec = Vector2( STONE_SPD, 0 ).rotate( random( PI2 ) );
}

void draw( ) {
	drawStone( );
}


