#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int BUBBLE_R = 150;
const int BUBBLE_G = 200;
const int BUBBLE_B = 255;
const int BUBBLE_ALPHA = 50;
const int MIN_DIA = 10;
const int MAX_DIA = 50;
const int MIN_SPD = -5;
const int MAX_SPD = -1;

struct Ball {
	Vector2 pos = { 0,0 };
	int dia = MIN_DIA;
	int spd = MIN_SPD;
};

std::list<Ball> _bubbles;

void spawnBubbles( ) {
	Ball b;
	b.pos = Vector2( getMouseX( ), HEIGHT );
	b.dia = ( int )random( MIN_DIA, MAX_DIA );
	b.spd = ( int )random( MIN_SPD, MAX_SPD );
	_bubbles.push_back( b );
}

void drawBubbles( ) {
	stroke( BUBBLE_R, BUBBLE_G, BUBBLE_B );
	fill( BUBBLE_R, BUBBLE_G, BUBBLE_B, BUBBLE_ALPHA );

	std::list<Ball>::iterator it = _bubbles.begin( );
	while ( it != _bubbles.end( ) ) {
		it->pos += Vector2( 0, it->spd );

		ellipse( it->pos.x, it->pos.y, it->dia );

		if ( it->pos.y < 0 ) {
			it = _bubbles.erase( it );
		} else {
			it++;
		}
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
}

void draw( ) {
	background( BACKGROUND );

	drawBubbles( );
}

void mouseDragged( ) {
	spawnBubbles( );
}
