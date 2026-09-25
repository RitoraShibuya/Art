#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACK_GRAY = 0;
const int BACK_ALPHA = 1;

int _frame_count = 0;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACK_GRAY );
}

void draw( ) {
	background( BACK_GRAY, BACK_ALPHA );
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			int a = i * i;
			int b = i * j;
			int c = ( i - j ) * i;
			int mul = ( int )( a + b * c * 0.005 * _frame_count  );
			int gray = mul % 255;
			int alpha = mul % 155;

			stroke( gray, alpha );
			point( i, j );
		}
	}
	_frame_count++;
}


