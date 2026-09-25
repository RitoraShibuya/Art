#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 255;

const int BALL_GRAY = 0;
const int BALL_ALPHA = 30;
const int BALL_SIZE = 50;
const int BALL_SPD = 5;

const int POINT_GRAY = 0;
const int POINT_NUM = 360;
const int BLOCK_GAP = 300;
double NOISE_RANGE = 0.05;

struct Ball {
	Vector2 pos { WIDTH / 2,HEIGHT / 2 };
	Vector2 vec { BALL_SPD,0 };
	double ang = PI2 * 0.25;
};

struct Block {
	Vector2 pos;
	std::list<Vector2>collision;
};

int _frame_count;
Ball _ball;
std::list<Block> _blockes;

void updateBall( ) {
	_ball.vec = Vector2( BALL_SPD, 0 ).rotate( _ball.ang );
	_ball.pos += _ball.vec;
	if ( _ball.pos.x < 0 ||
		 _ball.pos.x > WIDTH ) {
		_ball.pos.x = WIDTH - _ball.pos.x;
	}
	if ( _ball.pos.y < 0 ||
		 _ball.pos.y > HEIGHT ) {
		_ball.pos.y = HEIGHT - _ball.pos.y;
	}
}

void updateBlock( ) {
	std::list<Block>::iterator it = _blockes.begin( );
	while ( it != _blockes.end( ) ) {
		Block& block = *it;
		block.collision.clear( );
		for ( int i = 0; i < POINT_NUM; i++ ) {
			double ang = PI2 * i / POINT_NUM;
			double n1 = i * NOISE_RANGE;
			double n2 = ang * NOISE_RANGE;
			double n3 = _frame_count * NOISE_RANGE;
			double gap = noise( n1, n2, n3 ) * BLOCK_GAP;
			double x = block.pos.x + cos( ang ) * gap;
			double y = block.pos.y + sin( ang ) * gap;
			Vector2 c { x,y };
			block.collision.push_back( c );
			point( x, y );

			if ( ( _ball.pos - c ).getLength( ) < BALL_SIZE / 2 ) {
				_ball.ang = atan2( _ball.pos.y - c.y, _ball.pos.x - c.x );
				_ball.pos += Vector2( BALL_SPD, 0 ).rotate( _ball.ang );
			};
		}

		it++;
	}
};

void drawBall( ) {
	ellipse( _ball.pos.x, _ball.pos.y, BALL_SIZE );
};

void spawnBlock( ) {
	Block b;
	b.pos = Vector2( getMouseX( ), getMouseY( ) );
	_blockes.push_back( b );
};

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	fill( BALL_GRAY, BALL_ALPHA );
	stroke( POINT_GRAY );
}

void draw( ) {
	updateBall( );
	updateBlock( );
	drawBall( );

	_frame_count++;
}

void mouseClicked( ) {
	spawnBlock( );
}
