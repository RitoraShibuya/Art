#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int SPAWN_NUM = 500;
const int MIN_DIA = 80;
const int MAX_DIA = 120;

struct Ball {
	Vector2 pos;
	int dia = MIN_DIA;
};

std::vector<Ball> _whites;
std::vector<Ball> _reds;
std::vector<Ball> _blacks;

void spawnBall( ) {
	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		Ball b;

		int x = ( int )random( WIDTH );
		int y = ( int )random( HEIGHT );
		b.pos = Vector2( x, y );

		int dia = ( int )random( MIN_DIA, MAX_DIA );
		b.dia = dia;

		int rand_section = ( int )random( 3 );
		switch ( rand_section ) {
		case 0:
			_whites.push_back( b );
			break;
		case 1:
			_reds.push_back( b );
			break;
		case 2:
			_blacks.push_back( b );
			break;
		}
	}
}

void drawWhite( ) {
	fill( 255, 200 );
	for ( Ball& white : _whites ) {
		ellipse( white.pos.x, white.pos.y, white.dia );
	}
}

void drawRed( ) {
	fill( 255, 0, 0, 80 );
	for ( Ball& red : _reds ) {
		ellipse( red.pos.x, red.pos.y, red.dia );
	}
}

void drawBlack( ) {
	fill( 0 );
	for ( Ball& black : _blacks ) {
		ellipse( black.pos.x, black.pos.y, black.dia );
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );

	spawnBall( );

	drawRed( );
	drawWhite( );
	drawBlack( );
}
