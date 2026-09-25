#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const double NOISE_SCALE = 0.01;
const double X_SPD = 10.5;
const double Y_SPD = 10.5;

struct CubeVertex {
	Vector2 num = Vector2( 0, 0 );
	Vector2 pos = Vector2( 0.0, 0.0 );
};

std::vector<std::vector<CubeVertex>> _cubes;

Vector2 getVertex( int num1, int num2 ) {
	if ( num1 < 0 || num1 >= _cubes.size( ) )
		return Vector2( 0, 0 );

	if ( num2 < 0 || num2 >= _cubes[ num1 ].size( ) )
		return Vector2( 0, 0 );

	return _cubes[ num1 ][ num2 ].pos;
}


void makeVertices( ) {
	_cubes.clear( );
	int x = 0;
	int i = 0;

	while ( x < WIDTH ) {
		_cubes.push_back( { } );

		int y = 0;
		int j = 0;

		double n1 = ( getMouseX( ) + getMouseY( ) ) * NOISE_SCALE;

		while ( y < HEIGHT ) {
			CubeVertex cube;
			cube.num = Vector2( i, j );
			cube.pos = Vector2( x, y );

			_cubes.back( ).push_back( cube );

			double n2 = i * y * NOISE_SCALE;
			double n3 = j * x * NOISE_SCALE;
			double make_noise = noise( n1, n2, n3 );

			y += std::max( 1, ( int )( make_noise * Y_SPD ) );
			j++;
		}

		x += std::max( 1, ( int )( n1 * X_SPD ) );
		i++;
	}
}

void drawMesh( ) {
	for ( int i = 0; i < _cubes.size( ); i++ ) {
		for ( int j = 0; j < _cubes[ i ].size( ); j++ ) {
			beginShape( );

			Vector2 pos1 = getVertex( i, j );
			Vector2 pos2 = getVertex( i + 1, j );
			Vector2 pos3 = getVertex( i, j + 1 );

			vertex( pos1.x, pos1.y );
			vertex( pos2.x, pos2.y );
			vertex( pos3.x, pos3.y );

			endShape( CLOSE );
		}
	}
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( 255 );
	stroke( 0 );
}

void draw( ) {
	background( 255 );
	makeVertices( );
	drawMesh( );
}