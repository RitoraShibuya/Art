#include "Processing.h"

const int WIDTH = 500;
const int HEIGHT = 1000;
const int BACKGROUND = 255;

const int RAIN_R = 0;
const int RAIN_G = 0;
const int RAIN_B = 255;
const int SPAWN_NUM = 500;
const double RAIN_SPD = 5.0;
const double GRAVITY = 0.1;
const double MAX_GRAVITY = 5.0;

const int MIN_DIA = 10;
const int MAX_DIA = 100;

struct Drop {
	Vector2 pos;
	Vector2 vec;
};

struct Block {
	Vector2 pos;
	Vector2 left_top;
	Vector2 right_bot;
	int width = 0;
	int height = 0;
};

std::list<Drop> _rain;
std::list<Block> _blockes;

bool checkHitBlock( Drop& rain ) {
	bool hit = false;
	std::list<Block>::iterator it = _blockes.begin( );
	while ( it != _blockes.end( ) ) {
		Block& block = *it;

		if ( rain.pos.x > block.left_top.x &&
			 rain.pos.x < block.right_bot.x ) {
			if ( rain.pos.y > block.left_top.y &&
				 rain.pos.y < block.right_bot.y ) {
				hit = true;
				break;
			}
		}

		it++;
	}

	return hit;
}

void spawnDrop( ) {
	Drop r;
	r.pos = Vector2( ( int )random( WIDTH ), 0 );
	r.vec = Vector2( random( -RAIN_SPD, RAIN_SPD ), 0 );

	_rain.push_back( r );
}

void drawDrop( ) {
	std::list<Drop>::iterator it = _rain.begin( );
	while ( it != _rain.end( ) ) {
		Drop& rain = *it;

		if ( checkHitBlock( rain ) ) {
			rain.vec *= -1;
			//rain.vec.y = 0;
		} else {
			if ( rain.vec.y < MAX_GRAVITY ) {
				rain.vec.y += GRAVITY;
			}
		}
		rain.pos += rain.vec;

		point( rain.pos.x, rain.pos.y );

		if ( rain.pos.x > WIDTH ||
			 rain.pos.x < 0 ||
			 rain.pos.y > HEIGHT ) {
			spawnDrop( );
			it = _rain.erase( it );
		} else {
			it++;
		}
	}
}

void spawnBlock( ) {
	Block b;

	b.width = ( int )random( MIN_DIA, MAX_DIA );
	b.height = ( int )random( MIN_DIA, MAX_DIA );
	int offset_x = b.width / 2;
	int offset_y = b.height / 2;
	int x = ( int )random( offset_x, WIDTH - offset_x );
	int y = ( int )random( offset_y, HEIGHT - offset_y );
	b.pos = Vector2( x, y );
	Vector2 offset = Vector2( offset_x, offset_y );
	b.left_top = b.pos - offset;
	b.right_bot = b.pos + offset;

	_blockes.push_back( b );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	rectMode( CENTER );
	stroke( RAIN_R,RAIN_G,RAIN_B );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		spawnDrop( );
	}
}

void draw( ) {
	background( BACKGROUND );

	drawDrop( );

}

void mouseClicked( ) {
	spawnBlock( );
}
