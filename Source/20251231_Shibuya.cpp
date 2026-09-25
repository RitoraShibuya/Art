#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int RGB_MAX = 255;
const int BLOCK_ALPHA = 50;
const int MIN_DIA = 10;
const int MAX_DIA = 300;

struct Block {
	Vector2 pos;
	int width = 0;
	int height = 0;
	int r = 0;
	int g = 0;
	int b = 0;
};

std::list<Block> _blocks;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
	rectMode( CENTER );
}

void draw( ) {
	background( BACKGROUND );

	std::list<Block>::iterator it = _blocks.begin( );
	while ( it != _blocks.end( ) ) {
		Block& block = *it;

		if ( block.pos.y < HEIGHT - block.height / 2 ) {
			block.pos.y++;
		}

		fill( block.r, block.g, block.b ,BLOCK_ALPHA);
		rect( block.pos.x, block.pos.y, block.width, block.height );

		it++;
	}
}

void mouseClicked( ) {
	Block b;
	b.pos = Vector2( getMouseX( ), getMouseY( ) );
	b.width = ( int )random( MIN_DIA, MAX_DIA );
	b.height = ( int )random( MIN_DIA, MAX_DIA );
	b.r = ( int )random( RGB_MAX );
	b.g = ( int )random( RGB_MAX );
	b.b = ( int )random( RGB_MAX );
	_blocks.push_back( b );
}

