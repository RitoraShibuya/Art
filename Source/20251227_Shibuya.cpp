#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 5;
const int BACK_R = 255;
const int BACK_G = 0;
const int BACK_B = 0;

const int FLOWER_GRAY = 255;
const int POINT_NUM = 1000;
const int MAX_LIFE = 180;
const double NOISE_RANGE = 0.01;

struct Flower {
	Vector2 pos;
	int life = MAX_LIFE;
};

int _frame_count = 0;
std::list<Flower> _flowers;

void drawFlower( ) {
	std::list<Flower>::iterator it = _flowers.begin( );
	while ( it != _flowers.end( ) ) {
		Flower& flower = *it;

		for ( int i = 0; i < POINT_NUM; i++ ) {
			double ang = PI2 * i / POINT_NUM;
			double n1 = ang * NOISE_RANGE;
			double n2 = i * NOISE_RANGE;
			double n3 = _frame_count * NOISE_RANGE;
			double gap = noise( n1, n2, n3 ) * flower.life;
			double x = flower.pos.x + cos( ang ) * gap;
			double y = flower.pos.y + sin( ang ) * gap;
			point( x, y );
		}

		if ( flower.life < 0 ) {
			it = _flowers.erase( it );
		} else {
			flower.life--;
			it++;
		}
	}
}

void drawBack( ) {
	blendMode( MULTIPLY );
	fill( BACK_R, BACK_G, BACK_B );
	rect( 0, 0, WIDTH, HEIGHT );
	blendMode( BLEND );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	stroke( FLOWER_GRAY );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	drawFlower( );
	drawBack( );

	_frame_count++;
}

void mouseClicked( ) {
	Flower f;
	f.pos = Vector2( getMouseX( ), getMouseY( ) );
	_flowers.push_back( f );
}
