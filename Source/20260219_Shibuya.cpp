#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int MAX_H = 360;
const int MAX_S = 100;
const int MAX_B = 100;

const int GRID_SIZE = 10;
const int GRID_RADIUS = GRID_SIZE / 2;
const int GRID_NUM_X = WIDTH / GRID_SIZE;
const int GRID_NUM_Y = HEIGHT / GRID_SIZE;
const int STROKE_WEIGHT = 2;
const double NOISE_RANGE = 0.01;

struct Compas {
	Vector2 pos;
	double ang = 0;
};

std::vector<Compas> _compas;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	colorMode( HSB, MAX_H, MAX_S, MAX_B );
	strokeWeight( STROKE_WEIGHT );

	for ( int i = 0; i < GRID_NUM_X; i++ ) {
		for ( int j = 0; j < GRID_NUM_Y; j++ ) {
			Compas c;
			int x = GRID_RADIUS + i * GRID_SIZE;
			int y = GRID_RADIUS + j * GRID_SIZE;
			c.pos = Vector2( x, y );
			_compas.push_back( c );
		}
	}
}

void draw( ) {

	for ( Compas& compas : _compas ) {
		double dx = getMouseX( ) - compas.pos.x;
		double dy = getMouseY( ) - compas.pos.y;
		compas.ang = atan2( dy, dx );
		Vector2 out_pos = compas.pos + Vector2( GRID_SIZE, 0 ).rotate( compas.ang );

		double n1 = compas.pos.x * NOISE_RANGE;
		double n2 = compas.pos.y * NOISE_RANGE;
		double n3 = compas.ang;
		double col_h = noise( n1, n2, n3 ) * MAX_H;

		stroke( col_h, MAX_S, MAX_B );
		line( compas.pos, out_pos );
	}
}


