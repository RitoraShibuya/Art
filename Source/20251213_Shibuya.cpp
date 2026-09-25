#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;

const int BALL_GRAY = 255;
const int BALL_DIA = 2;
const int BALL_SPD = 3;

struct Ellipse {
	Vector2 pos = { 0, 0 };
};

std::list<Ellipse> _ball;

void spawnBall( ) {
	Ellipse b;
	b.pos = Vector2( getMouseX( ), HEIGHT );
	_ball.push_back( b );
}

void drawBall( ) {
	std::list<Ellipse>::iterator it = _ball.begin( );
	while ( it != _ball.end( ) ) {
		Vector2 add_vec = Vector2( 0, BALL_SPD );
		it->pos -= add_vec;

		fill( BALL_GRAY );
		ellipse( it->pos.x, it->pos.y, BALL_DIA );

		if ( it->pos.y > 0 ) {
			it++;
		} else {
			it = _ball.erase( it );
		}
	}

}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noStroke( );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );

	drawBall( );
}

void mouseDragged( ) {
	spawnBall( );
}
