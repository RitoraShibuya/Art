#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int BACK_ALPHA = 10;

const int LINE_GRAY = 255;
const int START_NUM = 100;
const int MIN_BALL_DIA = 50;
const int MAX_BALL_DIA = 100;
const int BALL_SPD = 3;
const int MIN_RECT_DIA = 25;
const int MAX_RECT_DIA = 50;

struct Ball {
	Vector2 pos;
	Vector2 vec;
	int dia = MAX_BALL_DIA;
};

struct Block {
	Vector2 pos;
	Vector2 pos2;
};

std::list<Ball> _balls;
std::list<Block> _blocks;

bool checkCollision( Ball& ball, Vector2 line_start, Vector2 line_end ) {
	bool hit = false;
	double radius = ( double )ball.dia * 0.5;
	double radius_sqrt = radius * radius;

	Vector2 line_vec = line_end - line_start;
	Vector2 start_to_ball = ball.pos - line_start;

	double line_length_sqrt = line_vec.getLength2( );

	if ( line_length_sqrt < 0.0001 ) {
		return start_to_ball.getLength2( ) <= radius_sqrt;
	}

	double dot = start_to_ball.dot( line_vec );
	double t = dot / line_length_sqrt;

	if ( t < 0.0 ) {
		t = 0.0;
	} else if ( t > 1.0 ) {
		t = 1.0;
	}

	Vector2 nearest = line_start + ( line_vec * t );
	Vector2 diff = ball.pos - nearest;
	double dist_sqrt = diff.getLength2( );

	if ( dist_sqrt <= radius_sqrt ) {
		double dist = sqrt( dist_sqrt );

		if ( dist > 0.0 ) {
			Vector2 normal = diff * ( 1.0 / dist );

			double overlap = radius - dist;
			ball.pos = ball.pos + ( normal * overlap );
			ball.vec *= -1;
		}
		hit = true;
	}

	return hit;
}

bool checkHit( Ball& ball ) {
	bool hit = false;
	std::list<Block>::iterator it = _blocks.begin( );
	while ( it != _blocks.end( ) ) {
		Block& block = *it;
		for ( int i = 0; i < 4; i++ ) {
			Vector2 start_pos( 0, 0 );
			Vector2 end_pos( 0, 0 );
			switch ( i ) {
			case 0:
				start_pos = block.pos;
				end_pos = Vector2( block.pos2.x, block.pos.y );
				break;
			case 1:
				start_pos = Vector2( block.pos2.x, block.pos.y );
				end_pos = block.pos2;
				break;
			case 2:
				start_pos = block.pos2;
				end_pos = Vector2( block.pos.x, block.pos2.y );
				break;
			case 3:
				start_pos = Vector2( block.pos.x, block.pos2.y );
				end_pos = block.pos;
				break;
			}
			if ( checkCollision( ball, start_pos, end_pos ) ) {
				hit = true;
				int width = block.pos2.x - block.pos.x;
				int height = block.pos2.y - block.pos.y;
				rect( block.pos.x, block.pos.y, width, height );
			}

		}
		it++;
	}
	return hit;
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	noFill( );
	stroke( LINE_GRAY );

	for ( int i = 0; i < START_NUM; i++ ) {
		Ball b;
		b.pos = Vector2( random( WIDTH ), HEIGHT / 2 );
		b.vec = Vector2( BALL_SPD, 0 ).rotate( random( PI2 ) );
		b.dia = ( int )random( MIN_BALL_DIA, MAX_BALL_DIA );
		_balls.push_back( b );
	}
}

void draw( ) {

	background( BACKGROUND, BACK_ALPHA );

	std::list<Ball>::iterator it = _balls.begin( );
	while ( it != _balls.end( ) ) {
		Ball& ball = *it;

		ball.pos += ball.vec;

		if ( ball.pos.x > WIDTH || ball.pos.x < 0 ) {
			ball.vec.x *= -1;
		}
		if ( ball.pos.y > HEIGHT || ball.pos.y < 0 ) {
			ball.vec.y *= -1;
		}

		ellipse( ball.pos.x, ball.pos.y, ball.dia );
		if ( checkHit( ball ) ) {
			ball.vec *= -1;
		}

		it++;
	}

}

void mouseClicked( ) {
	Block r;
	r.pos = Vector2( getMouseX( ), getMouseY( ) );
	Vector2 dia = Vector2( ( int )random( MIN_RECT_DIA, MAX_RECT_DIA ), ( int )random( MIN_RECT_DIA, MAX_RECT_DIA ) );
	r.pos2 = r.pos + dia;
	_blocks.push_back( r );
}

