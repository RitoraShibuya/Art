#include "Processing.h"
#include <vector>
#include <algorithm>  // remove_if用

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 0;
const int SCREENSPD = 3;   // スクロール速度
const int R_SIZE = 80;

int screenspd = 0;
double ang = 0;

struct MUSICWAVES {
	int mx, my, r, g, b, weight;
	bool sizeswitch;

	void Setup( int smx, int smy ) {
		mx = smx;
		my = smy;
		r = g = b = 0;
		switch ( ( int )random( 3 ) ) {
		case 0: r = 255; break;
		case 1: g = 255; break;
		case 2: b = 255; break;
		}
		weight = R_SIZE;
		sizeswitch = false;
	}

	void Draw( ) {
		fill( r, g, b );
		rect( mx, my, weight, weight );
		fill( 0 );
		ellipse( mx, my, weight );
	}

	bool isOutOfScreen( ) const {
		// 左端より外に行ったら true を返す
		return ( mx - screenspd + weight < 0 );
	}

	void Update( ) {
		if ( sizeswitch && weight <= R_SIZE + 20 )
		{
			weight++;

		} else
		{
			sizeswitch = false;
			weight--;
			if ( weight <= R_SIZE - 20 )
			{
				sizeswitch = true;
			}
		}

	}
};

std::vector<MUSICWAVES> Lines;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKCOLOR );
	rectMode( CENTER );
	noStroke( );
}

void draw( ) {
	background( BACKCOLOR, 20 );

	rotate( ang );
	ang += 0.01;
	// 全体を左にスクロール
	translate( -screenspd, 0 );
	screenspd += SCREENSPD;

	// 追加された矩形を描画
	for ( auto& L : Lines ) {
		L.Draw( );
		L.Update( );
	}

	// ★ 画面外に出た要素を消去
	Lines.erase(
		std::remove_if( Lines.begin( ), Lines.end( ),
						[] ( const MUSICWAVES& L ) { return L.isOutOfScreen( ); } ),
		Lines.end( )
	);
}

void mouseClicked( ) {
	int smx = ( int )getMouseX( );
	int smy = ( int )getMouseY( );
	MUSICWAVES L;
	L.Setup( smx + screenspd, smy );  // スクロール補正
	Lines.push_back( L );
}
