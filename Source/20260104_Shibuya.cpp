#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int BLOCK_GRAY = 255;
const int START_NUM = 50;
const int BLOCK_WIDTH = 50;
const int BLOCK_HEIGHT = 200;
const double MIN_SPD = 0.5;
const double MAX_SPD = 5.0;

struct Block {
	Vector2 pos;
	Vector2 vec;
	double ang = 0;
	double spd = 0;
};

std::list<Block> _blocks;

void spawnBlock( ) {
	Block b;
	Vector2 pos;
	double ang = 0;
	switch ( ( int )random( 4 ) ) {
	case 0:
		pos.x = ( int )random( WIDTH );
		ang = PI2 * 0.25;
		break;
	case 1:
		pos.y = ( int )random( HEIGHT );
		break;
	case 2:
		pos.x = ( int )random( WIDTH );
		pos.y = HEIGHT;
		ang = PI2 * 0.75;
		break;
	case 3:
		pos.x = WIDTH;
		pos.y = ( int )random( WIDTH );
		ang = PI2 * 0.5;
		break;
	}
	b.pos = pos;
	b.spd = random( MAX_SPD, MIN_SPD );
	b.ang = ang;
	b.vec = Vector2( b.spd, 0 ).rotate( b.ang );
	_blocks.push_back( b );
}

void drawBlock( ) {
	std::list<Block>::iterator it = _blocks.begin( );
	while ( it != _blocks.end( ) ) {
		Block& block = *it;
		block.pos += block.vec;

		if ( block.pos.x > WIDTH + BLOCK_WIDTH ||
			 block.pos.x < 0 - BLOCK_WIDTH ||
			 block.pos.y > HEIGHT + BLOCK_WIDTH ||
			 block.pos.y < 0 - BLOCK_WIDTH ) {
			it = _blocks.erase( it );
			spawnBlock( );
		} else {
			rotate( block.ang );
			rect( block.pos.x, block.pos.y, BLOCK_WIDTH, BLOCK_HEIGHT );
			rotate( -block.ang );

			it++;
		}
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noFill( );
	stroke( BLOCK_GRAY );

	for ( int i = 0; i < START_NUM; i++ ) {
		spawnBlock( );
	}
}

void draw( ) {
	background( BACKGROUND );

	drawBlock( );
}


