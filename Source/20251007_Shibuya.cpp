#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CX = WIDTH / 2;
const int BACKCOL = 0;
const int P_DIA = 50;
const int P_SPD = 3;
const int MIN_M_DIA = 50;
const int MAX_M_DIA = 100;
const int MIN_M_SPD = 1;
const int MAX_M_SPD = 5;
const int MAX_M_NUM = 10;

struct Meteo {
	int x, y;
	int dia;
	int spd;
	bool isdead;
};

struct Player {
	int x, y;
	int dia;
	int spd;
	bool isdead;
	int r, g, b;
};

std::vector<Meteo> enemyes;
Player myplayer;

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKCOL );
	noStroke( );

	myplayer.dia = P_DIA;
	myplayer.x = CX;
	myplayer.y = HEIGHT - myplayer.dia * 2;
	myplayer.spd = P_SPD;
	myplayer.isdead = false;
	myplayer.r = 255; myplayer.b = 255; myplayer.g = 255;
	for ( int i = 0; i < MAX_M_NUM; i++ ) {
		Meteo M;
		M.x = ( int )random( WIDTH );
		M.y = ( int )random( -MAX_M_DIA, 0 ); 
		M.dia = ( int )random( MIN_M_DIA, MAX_M_DIA );
		M.spd = ( int )random( MIN_M_SPD, MAX_M_SPD );
		M.isdead = false;
		enemyes.push_back( M );
	}
}

void draw( ) {
	background( BACKCOL );

	int mx = getMouseX( );
	myplayer.x = mx;

	bool isHit = false;  // 接触しているかどうかを記録

	fill( 255, 255, 0 );  // 隕石の色
	int num = 0;

	for ( auto& M : enemyes ) {
		// 隕石の描画
		ellipse( M.x, M.y, M.dia );


		// 隕石のリセット処理
		if ( M.y >= HEIGHT ) {
			Meteo newM;
			newM.x = ( int )random( WIDTH );
			newM.y = 0;
			newM.dia = ( int )random( MIN_M_DIA, MAX_M_DIA );
			newM.spd = ( int )random( MIN_M_SPD, MAX_M_SPD );
			newM.isdead = false;
			enemyes.push_back( newM );

			enemyes.erase( enemyes.begin( ) + num );
			num--;
		}
		int dx = M.x - myplayer.x;
		int dy = M.y - myplayer.y;
		int distSquared = dx * dx + dy * dy;

		int radiusSum = ( myplayer.dia + M.dia ) * 0.5;
		int radiusSumSquared = radiusSum * radiusSum;

		if ( distSquared < radiusSumSquared ) {
			isHit = true;
		}

		M.y += M.spd;
		num++;
	}

	// 色の変更（当たっていれば赤、そうでなければ白）
	if ( isHit ) {
		fill( 255, 0, 0 );  // 赤
	} else {
		fill( 255 );  // 白
	}

	// プレイヤーの描画
	ellipse( myplayer.x, myplayer.y, myplayer.dia );
}




