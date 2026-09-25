#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;

const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BALL_SPD = 3;
const double NOISE_RANGE = 0.01;

class Ball {
public:
	void init( Vector2 new_pos ) {
		_pos = new_pos;
		double ang = atan2( _pos.y - CENTER_X, _pos.x - CENTER_X );
		_vec = Vector2( BALL_SPD, 0 ).rotate( ang );
	}

	void update( ) {
		if ( _pos.x > WIDTH || _pos.x < 0 ) {
			_vec.x *= -1;
		}
		if ( _pos.y > HEIGHT || _pos.y < 0 ) {
			_vec.y *= -1;
		}

		_pos += _vec;
	}

	void draw( double h ) {
		stroke( h, MAX_S, MAX_B );
		point( _pos );
	}

	Vector2 getPos( ) {
		return _pos;
	}
private:
	Vector2 _pos;
	Vector2 _vec;
};

int _frame_count = 0;
std::vector<Ball> _balls;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
}

void draw( ) {
	background( BACKGROUND, BACK_ALPHA );
	double n1 = _frame_count * NOISE_RANGE;
	double col = noise( n1 ) * MAX_H;
	for ( Ball& ball : _balls ) {
		ball.update( );
		ball.draw( col );
	}
	_frame_count++;
}

void mouseDragged( ) {
	Ball b;
	Vector2 m_pos( getMouseX( ), getMouseY( ) );
	b.init( m_pos );
	_balls.push_back( b );
}

