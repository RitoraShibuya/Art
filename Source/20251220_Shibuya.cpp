#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int LINE_GRAY = 255;
const int LINE_ALPHA = 15;
const int LINE_NUM = 5;
const int LINE_SPD = 10;

struct Cross {
	Vector2 pos;
	Vector2 vec;
};

std::list<Cross> _beams;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	blendMode( ADD );
	stroke( LINE_GRAY, LINE_ALPHA );
}

void draw( ) {

	std::list<Cross>::iterator it = _beams.begin( );
	while ( it != _beams.end( ) ) {
		Cross& beam = *it;
		Vector2 old_pos = beam.pos;
		beam.pos += beam.vec;
		
		line( old_pos.x, old_pos.y, beam.pos.x, beam.pos.y );
		if ( beam.pos.x > WIDTH || beam.pos.y > HEIGHT ||
			 beam.pos.x < 0 || beam.pos.y < 0 ) {
			it = _beams.erase( it );
		} else {
			it++;
		}
	}
}

void mouseDragged( ) {
	Vector2 m_pos( getMouseX( ), getMouseY( ) );

	for ( int i = 0; i < LINE_NUM; i++ ) {
		double rand_ang = random( PI );
		double ang = PI2 * i / LINE_NUM + rand_ang;

		Cross b;
		b.pos = m_pos;
		b.vec = Vector2( LINE_SPD, 0 ).rotate( ang );
		_beams.push_back( b );
	}
}