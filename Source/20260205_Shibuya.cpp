#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;

const int GRID = 5;
const int GRID_NUM = WIDTH / GRID;
const int MAX_GRID_NUM = GRID_NUM * 3 / 4;

const int CLOUD_GRAY = 255;
const int INTERVAL = 5;
const int SPD = 1;

struct Cloud {
	int x = 0;
	int num = 0;
};

int _frame_count = 0;
std::list<Cloud> _clouds;

void spawnCloud( ) {
	Cloud c;
	c.num = ( int )random( MAX_GRID_NUM );
	_clouds.push_back( c );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );

	stroke( CLOUD_GRAY );
}

void draw( ) {
	background( BACKGROUND );

	std::list<Cloud>::iterator it = _clouds.begin( );
	while ( it != _clouds.end( ) ) {
		Cloud& cloud = *it;
		cloud.x += SPD;

		for ( int i = 0; i < cloud.num; i++ ) {
			int y = i * GRID;
			point( cloud.x, y );
		}

		if ( cloud.x > WIDTH ) {
			it = _clouds.erase( it );
		} else {
			it++;
		}
	}

	if ( _frame_count % INTERVAL == 0 ) {
		spawnCloud( );
	}

	_frame_count++;
}


