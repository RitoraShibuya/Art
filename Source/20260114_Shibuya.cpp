#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKGROUND = 0;
const int GRID_NUM_WIDTH = 200;
const int GRID_NUM_HEIGHT = 200;
const int GRID_SIZE_WIDTH = WIDTH / GRID_NUM_WIDTH;
const int GRID_SIZE_HEIGHT = HEIGHT / GRID_NUM_HEIGHT;
const double GRAVITY = 0.1;
const double MAX_GRAVITY = 5;

const int SAND_GRAY = 255;
const int SAND_SPD = 3;

struct Sand {
    Vector2 pos;
    Vector2 vec;
};

std::list<Sand> _sands;

bool checkHit( Sand& sand ) {
    bool hit = false;
    std::list<Sand>::iterator it = _sands.begin( );
    while ( it != _sands.end( ) ) {
        Sand& other = *it;
        if ( &sand != &other ) {
            double dist_x = abs( sand.pos.x - other.pos.x );
            double dist_y = abs( sand.pos.y - other.pos.y );

            if ( dist_x < GRID_SIZE_WIDTH && dist_y < GRID_SIZE_HEIGHT ) {
                hit = true;
            }
        }
        it++;
    }
    return hit;
}

void setup( ) {
    size( WIDTH, HEIGHT );
    background( BACKGROUND );
    fill( SAND_GRAY );
}

void draw( ) {
    background( BACKGROUND );

    std::list<Sand>::iterator it = _sands.begin( );
    while ( it != _sands.end( ) ) {
        Sand& sand = *it;

        if ( sand.vec.y < MAX_GRAVITY ) {
            sand.vec.y += GRAVITY;
        }

        sand.pos.y += sand.vec.y; 

        if ( sand.pos.y > HEIGHT - GRID_SIZE_HEIGHT ) {
            sand.pos.y = 0;
        }
        else if ( checkHit( sand ) ) {
            sand.pos.y -= sand.vec.y;
            sand.vec.y = 0;
        }

        if ( sand.vec.x != 0 ) {
            sand.pos.x += sand.vec.x; 

            if ( sand.pos.x < 0 || sand.pos.x > WIDTH - GRID_SIZE_WIDTH ) {
                sand.pos.x -= sand.vec.x;
                sand.vec.x = 0;
            }
            else if ( checkHit( sand ) ) {
                sand.pos.x -= sand.vec.x;
                sand.vec.x = 0;
            }
        }

        rect( sand.pos.x, sand.pos.y, GRID_SIZE_WIDTH, GRID_SIZE_HEIGHT );

        it++;
    }
}

void mouseDragged( ) {
    Sand s;
    s.pos = Vector2( getMouseX( ), getMouseY( ) );
    s.vec = Vector2(  SAND_SPD, 0 ).rotate(random(PI));
    _sands.push_back( s );
}