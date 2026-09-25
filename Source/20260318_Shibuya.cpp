#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;
const int BACK_H = 280;
const int SPAWN_NUM = 20;
const int VERTEX_NUM = 5;
const int STROKE_WEIGHT = 20;
const int MAX_DIA = 1000;
const double ANG_SPD = PI2 * 1 / 500;

struct Box {
	Vector2 center;
	int num = 0;
	int dia = 0;
	double base_ang = 0;
};

std::vector<Box> _boxes;

void setup( ) {
	size( WIDTH, HEIGHT );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	background( BACK_H, MAX_S, MAX_B );
	strokeWeight( STROKE_WEIGHT );

	Vector2 c_pos( WIDTH / 2, HEIGHT / 2 );
	for ( int i = 0; i < SPAWN_NUM; i++ ) {
		Box b;
		b.center = c_pos;
		b.num = i;
		b.dia = MAX_DIA * i / SPAWN_NUM;
		b.base_ang = i * ANG_SPD;
		_boxes.push_back( b );
	}
}

void draw( ) {
	Vector2 m_pos( getMouseX( ), getMouseY( ) );
	Vector2 c_pos( WIDTH / 2, HEIGHT / 2 );
	Vector2 step = ( m_pos - c_pos ) * ( double )( 1.0 / SPAWN_NUM );

	for ( Box& box : _boxes ) {
		box.center = c_pos + step * box.num;
		box.base_ang += ANG_SPD;

		double col_h = ( int )( box.center.x + box.center.y ) % MAX_H;
		stroke( col_h, MAX_S, MAX_B );
		beginShape( );
		for ( int i = 0; i < VERTEX_NUM; i++ ) {
			double ang = box.base_ang + PI2 * i / VERTEX_NUM;
			double x = box.center.x + cos( ang ) * box.dia;
			double y = box.center.y + sin( ang ) * box.dia;
			vertex( x, y );
		}
		endShape( CLOSE );
	}
}


