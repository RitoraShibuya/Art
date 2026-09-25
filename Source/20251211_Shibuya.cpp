#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKGROUND = 0;
const int SPAWN_TIME = 30;
const int BULLET_SPAWN_TIME = 10;
const int FRAME_RATE = 30;
const int RANDOM_SECTION = 4;

const double PLAYER_SPD = 0.03;

const int ENEMY_DIA = 150;
const int ENEMY_SPD = 5;
const int ENEMY_GRAY = 255;
const int ENEMY_ALPHA = 5;

const int BULLET_DIA = 10;
const int BULLET_SPD = 10;

const int SPACE = ENEMY_DIA / 2 + BULLET_DIA / 2;

struct Pawn {
	Vector2 pos = { 0, 0 };
	double ang = 0;
};

int _frame_count = 0;
Pawn _player;
std::list<Pawn> _enemy;
std::list<Pawn> _bullet;

bool checkBullet( Pawn& it ) {
	bool hit = false;
	std::list<Pawn>::iterator other = _bullet.begin( );
	while ( other != _bullet.end( ) ) {
		double dx = it.pos.x - other->pos.x;
		double dy = it.pos.y - other->pos.y;
		double dist = sqrt( dx * dx + dy * dy );

		if ( dist < SPACE ) {
			other = _bullet.erase( other );
			hit = true;
		} else {
			other++;
		}
	}
	return hit;
}

void spawnEnemy( ) {
	if ( _frame_count % SPAWN_TIME == 0 ) {
		Pawn e;
		switch ( ( int )random( RANDOM_SECTION ) ) {
		case 0:
			e.pos.x = ( int )random( WIDTH );
			break;
		case 1:
			e.pos.y = ( int )random( HEIGHT );
			break;
		case 2:
			e.pos.x = ( int )random( WIDTH );
			e.pos.y = HEIGHT;
			break;
		case 3:
			e.pos.x = WIDTH;
			e.pos.y = ( int )random( HEIGHT );
			break;
		}
		_enemy.push_back( e );
	}
}

void spawnBullet( ) {
	if ( _frame_count % BULLET_SPAWN_TIME == 0 ) {
		Pawn b;
		b.pos = _player.pos;
		b.ang = _player.ang;
		_bullet.push_back( b );
	}
}

void updateBullet( ) {
	std::list<Pawn>::iterator it = _bullet.begin( );
	while ( it != _bullet.end( ) ) {
		Vector2 b_spd( 1, 0 );
		b_spd = b_spd.rotate( it->ang );
		b_spd = b_spd * BULLET_SPD;
		it->pos += b_spd;

		if ( it->pos.x < 0 || it->pos.x > WIDTH ||
			 it->pos.y < 0 || it->pos.y > HEIGHT ) {
			it = _bullet.erase( it );
		} else {
			it++;
		}
	}
}

void updateEnemy( ) {
	std::list<Pawn>::iterator it = _enemy.begin( );
	while ( it != _enemy.end( ) ) {
		Vector2 dist = _player.pos - it->pos;

		it->ang = atan2( dist.y, dist.x );

		Vector2 vec( 1, 0 );
		vec = vec.rotate( it->ang );
		vec = vec * ENEMY_SPD;
		it->pos += vec;

		fill( ENEMY_GRAY, ENEMY_ALPHA );
		ellipse( it->pos.x, it->pos.y, ENEMY_DIA );

		if ( checkBullet( *it ) ) {
			it = _enemy.erase( it );
		} else {
			it++;
		}
	}
}

void updatePlayer( ) {
	Vector2 mouse( getMouseX( ), getMouseY( ) );
	Vector2 dist = mouse - _player.pos;
	_player.pos += dist * PLAYER_SPD;
	_player.ang = atan2( dist.y, dist.x );
}

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKGROUND );
	setFrameRate( FRAME_RATE );
	noStroke( );
}

void draw( ) {

	spawnEnemy( );

	spawnBullet( );

	updatePlayer( );

	updateBullet( );

	updateEnemy( );

	_frame_count++;
}

