#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int GRID_SIZE = 20;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BLOCK_ALPHA = 10;
const int SPAWN_NUM = 10;
const int SPAWN_INTERVAL = 20;
const int BLOCK_SPD = 5;


struct Block {
	Vector2 pos;
	Vector2 vec;
	int col_h = MAX_H;
};

std::list<Block> _blocks;
int _frame_count = 0;

void spawnBlock( ) {
	int spawn_x = ( int )random( WIDTH );
	int random_h = ( int )random( MAX_H );
	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		double ang = PI * i / SPAWN_NUM;
		Block b;
		b.pos = Vector2( spawn_x, 0 );
		b.vec = Vector2( BLOCK_SPD, 0 ).rotate( ang );
		b.col_h = random_h;
		_blocks.push_back( b );
	}
}


void drawBlock( ) {
	std::list<Block>::iterator it = _blocks.begin( );
	while ( it != _blocks.end( ) ) {
		Block& block = *it;
		if ( block.pos.x > WIDTH || block.pos.x < 0 ||
			 block.pos.y > HEIGHT || block.pos.y < 0 ) {
			it = _blocks.erase( it );
			continue;
		}
		block.pos += block.vec;
		int grid_x = ( int )block.pos.x / GRID_SIZE;
		int grid_y = ( int )block.pos.y / GRID_SIZE;
		Vector2 grid_pos = Vector2( grid_x, grid_y ) * GRID_SIZE;

		fill( block.col_h, MAX_S, MAX_B, BLOCK_ALPHA );
		rect( grid_pos.x, grid_pos.y, GRID_SIZE, GRID_SIZE );

		it++;
	}
}


void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	blendMode( ADD );
}

void draw( ) {
	if ( _frame_count % SPAWN_INTERVAL == 0 ) {
		spawnBlock( );
	}
	drawBlock( );

	_frame_count++;
}


