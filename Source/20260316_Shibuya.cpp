#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int RGB_MAX = 255;
const int BACK_R = 255;
const int BACK_G = 255;
const int BACK_B = 0;
const int GRID_SIZE = 10;
const int GRID_RADIUS = GRID_SIZE / 2;
const int GRID_NUM_WIDTH = WIDTH / GRID_SIZE;
const int GRID_NUM_HEIGHT = HEIGHT / GRID_SIZE;
const int SPAWN_INTERVAL = 60;
const int BALL_SPD = 10;
const double ERASE_RANGE = BALL_SPD * 2;

struct Ball {
	Vector2 pos;
	int col_r = 0;
	int col_g = 0;
	int col_b = 0;
};

int _frame_count = 0;
std::list<Ball> _balls;

void spawnBall( int x, int y ) {
	Ball b;
	b.pos = Vector2( x, y );
	b.col_r = ( x * x + x * y ) % RGB_MAX;
	b.col_g = ( y * y + x * y ) % RGB_MAX;
	b.col_b = ( _frame_count * x * y ) % RGB_MAX;
	_balls.push_back( b );
}

void spawnRequest( ) {
	if ( _frame_count % SPAWN_INTERVAL == 0 ) {

		for ( int i = 0; i < GRID_NUM_HEIGHT; i++ ) {
			int y = GRID_RADIUS + i * GRID_SIZE;
			spawnBall( GRID_RADIUS, y );
			spawnBall( WIDTH - GRID_RADIUS, y );
		}

		for ( int i = 0; i < GRID_NUM_WIDTH; i++ ) {
			int x = GRID_RADIUS + i * GRID_SIZE;
			spawnBall( x, GRID_RADIUS );
			spawnBall( x, HEIGHT - GRID_RADIUS );
		}
	}
}


void updateBalls( ) {
	Vector2 m_pos( getMouseX( ), getMouseY( ) );
	std::list<Ball>::iterator it = _balls.begin( );
	while ( it != _balls.end( ) ) {
		Ball& ball = *it;
		Vector2 dist = m_pos - ball.pos;
		if ( dist.getLength( ) > ERASE_RANGE ) {
			Vector2 vec = dist.normalize( ) * BALL_SPD;
			ball.pos += vec;

			stroke( ball.col_r, ball.col_g, ball.col_b );
			ellipse( ball.pos.x, ball.pos.y, GRID_SIZE );

			it++;
		} else {
			it = _balls.erase( it );
		}
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_R, BACK_B, BACK_G );
	noFill( );
}

void draw( ) {
	spawnRequest( );
	updateBalls( );
	_frame_count++;
}


