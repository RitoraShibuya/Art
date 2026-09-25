#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int E_SIZE = 80;
const int E_NUM = 4;
const int GAP = 200;

// --- 公転・自転のスピードを別々に設定 ---
const double THETAADD = 0.05;   // 自転の速度
const double ANGADD = 1.2;    // 公転の速度

double ang = 0;     // 公転用角度
double theta = 0;   // 自転用角度

void setup( ) {
	size( WIDTH, HEIGHT );
	background( BACKCOLOR );
	setFrameRate( 30 );
}

void draw( ) {
	background( BACKCOLOR,1 ); // 少し残像を残す
	translate( CENTER_X, CENTER_Y );

	// --- 公転（全体がずれる） ---
	translate( sin( radians( ang ) ) * 150, cos( radians( ang ) ) * 150 );

	// --- 色を時間で変える ---
	fill(
		( noise( ang * 0.01 ) ) * 255,
		( noise( theta * 0.02 ) ) * 255,
		( noise( ang * 0.015 + theta * 0.01 ) ) * 255,
		255
	);

	// --- 自転（円を多角形の位置に配置） ---
	for ( int i = 0; i < E_NUM; i++ ) {
		double localTheta = PI2 * ( i / ( double )E_NUM ) + theta;
		double x = cos( localTheta ) * ( sin( radians( ang ) ) * GAP );
		double y = sin( localTheta ) * ( cos( radians( ang ) ) * GAP );
		ellipse( x, y, E_SIZE, E_SIZE );
	}

	// 角度更新
	theta += THETAADD; // 自転
	ang += ANGADD;   // 公転
}
