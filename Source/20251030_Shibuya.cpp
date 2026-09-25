#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int GRID = 20;

int timer = 0;

class Col_E {
public:
	float x, y;   // 円の位置
	float mx, my; // マウスの目標位置
	float ang = 0;            // 角度
	float dist = 0;           // 距離

	// マウス位置を受け取って角度と距離を計算
	void Setup( int sx, int sy ) {
		mx = getMouseX( );
		my = getMouseY( );
		x = sx;
		y = sy;
		float dx = mx - x;
		float dy = my - y;
		ang = atan2( dy, dx );             // ← 角度の正しい計算式
		dist = sqrt( dx * dx + dy * dy );  // 距離を計算
	}

	void Draw( ) {
		ellipse( x, y, GRID );
	}

	void Update( ) {
		// 少しずつマウスの方向へ移動
		x += cos( ang ) * ( dist / 90 );
		y += sin( ang ) * ( dist / 90 );

		// 180フレームごとに新しいマウス位置を取得
		if ( timer % 180 == 0 ) {
			mx = getMouseX( );
			my = getMouseY( );
			float dx = mx - x;
			float dy = my - y;
			ang = atan2( dy, dx );             // ← 角度の正しい計算式
			dist = sqrt( dx * dx + dy * dy );  // 距離を計算
		}
	}
};

std::list<Col_E> c_e;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKCOL );
	colorMode( HSB, 360, 100, 100 );
	setFrameRate( 30 );
	noStroke( );
	for ( int x = GRID / 2; x < WIDTH; x += GRID ) {
		for ( int y = GRID / 2; y < HEIGHT; y += GRID ) {
			Col_E E;
			E.Setup( x, y );
			c_e.push_back( E );
		}

	}
}

void draw( ) {
	background( BACKCOL );
	fill( 0,0,100 );
	for ( auto it = c_e.begin( ); it != c_e.end( ); ++it ) {
		it->Draw( );
		it->Update( );
	}

	
	blendMode( MULTIPLY );
	for ( int x = GRID; x < WIDTH; x += GRID ) {
		for ( int y = GRID; y < HEIGHT; y += GRID ) {
			fill( noise( x * 0.05 + 300, y * 0.05 + 300, timer * 0.05 ) * 360, 100, 100 );
			rect( x, y, GRID, GRID );
		}

	}
	blendMode( BLEND );
	timer++;
}
