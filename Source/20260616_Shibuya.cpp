#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 0;
const int SPAWN_NUM = 1500;
const int FRAME_LOOP = 500;
const int BALL_COL_GAP = 80;
const double BALL_SPD = 0.08;
const double NOISE_SCALE = 0.005;

Vector2 _vec;
Vector2 _center;
std::vector<Vector2> _balls;

void warp( Vector2& val ) {
	if ( val.x > CENTER_X ) {
		val.x -= CENTER_X;
	} else if ( val.x < 0 ) {
		val.x += CENTER_X;
	}

	if ( val.y > CENTER_Y ) {
		val.y -= CENTER_Y;
	} else if ( val.y < 0 ) {
		val.y += CENTER_Y;
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H );

	_vec = Vector2( 0, 0 );
	_center = Vector2( CENTER_X, CENTER_Y );

	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		int x00 = (int)random( CENTER_X );
		int y00 = (int)random( CENTER_Y );
		Vector2 pos00 { x00, y00 };
		_balls.push_back( pos00 );
	}
}

void draw( ) {
	int frame_count = getFrameCount( ) % FRAME_LOOP;
	double n3 = _vec.getLength( ) + frame_count * NOISE_SCALE;
	for ( Vector2& ball : _balls ) {
		ball += _vec;
		warp( ball );

		double n1 = ball.x * NOISE_SCALE;
		double n2 = ball.y * NOISE_SCALE;
		double make_noise = noise( n1, n2, n3 );

		int col_h = ( int )( make_noise * MAX_H ) + BALL_COL_GAP % MAX_H;
		stroke( col_h, MAX_S, MAX_B );

		point( ball );

		int x01 = WIDTH - ball.x;
		int y01 = ball.y;
		point( x01, y01 );

		int x10 = ball.x;
		int y10 = HEIGHT - ball.y;
		point( x10, y10 );

		int x11 = x01;
		int y11 = y10;
		point( x11, y11 );
	}
}

void mouseDragged( ) {
	Vector2 m_pos { getMouseX( ),getMouseY( ) };
	_vec = ( _center - m_pos ) * BALL_SPD;
}

void mouseReleased( ) {
	_vec = Vector2( 0, 0 );
}


