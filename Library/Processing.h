#pragma once
#include "mathematics.h"
#include <math.h>
#include <vector>
#include <list>
#include <array>
#include <string>

#ifdef _DEBUG
#pragma comment( lib, "processing_d.lib" )
#else
#pragma comment( lib, "processing_r.lib" )
#endif

//
// symbol
//

enum SYMBOL {
	NONE,
	LEFT,
	RIGHT,
	CENTER,
	CORNERS,
	CORNER,
	RADIUS,
	RADIANS,
	DEGREES,
	LINES,
	TRIANGLES,
	TRIANGLE_FAN,
	TRIANGLE_STRIP,
	QUADS,
	QUAD_STRIP,
	TESS,
	CLOSE,
	RGB,
	HSB,
	BLEND,
	ADD,
	SUBTRACT,
	MULTIPLY,
	KEY_BACK,// バックスペースキー
	KEY_TAB,// タブキー
	KEY_RETURN,// エンターキー
	KEY_LSHIFT,// 左シフトキー
	KEY_RSHIFT,// 右シフトキー
	KEY_LCONTROL,// 左コントロールキー
	KEY_RCONTROL,// 右コントロールキー
	KEY_ESCAPE,// エスケープキー
	KEY_SPACE,// スペースキー
	KEY_PGUP,// ＰａｇｅＵＰキー
	KEY_PGDN,// ＰａｇｅＤｏｗｎキー
	KEY_END,// エンドキー
	KEY_HOME,// ホームキー
	KEY_LEFT,// 左キー
	KEY_UP,// 上キー
	KEY_RIGHT,// 右キー
	KEY_DOWN,// 下キー
	KEY_INSERT,// インサートキー
	KEY_DELETE,// デリートキー
	KEY_MINUS,// －キー
	KEY_YEN,// ￥キー
	KEY_PREVTRACK,// ＾キー
	KEY_PERIOD,// ．キー
	KEY_SLASH,// ／キー
	KEY_LALT,// 左ＡＬＴキー
	KEY_RALT,// 右ＡＬＴキー
	KEY_SCROLL,// ScrollLockキー
	KEY_SEMICOLON,// ；キー
	KEY_COLON,// ：キー
	KEY_LBRACKET,// ［キー
	KEY_RBRACKET,// ］キー
	KEY_AT,// ＠キー
	KEY_BACKSLASH,// ＼キー
	KEY_COMMA,// ，キー
	KEY_CAPSLOCK,// CaspLockキー
	KEY_PAUSE,// PauseBreakキー
	KEY_NUMPAD0,	// テンキー０
	KEY_NUMPAD1,	// テンキー１
	KEY_NUMPAD2,	// テンキー２
	KEY_NUMPAD3,	// テンキー３
	KEY_NUMPAD4,	// テンキー４
	KEY_NUMPAD5,	// テンキー５
	KEY_NUMPAD6,	// テンキー６
	KEY_NUMPAD7,	// テンキー７
	KEY_NUMPAD8,// テンキー８
	KEY_NUMPAD9,// テンキー９
	KEY_MULTIPLY,// テンキー＊キー
	KEY_ADD,// テンキー＋キー
	KEY_SUBTRACT,// テンキー－キー
	KEY_DECIMAL,// テンキー．キー
	KEY_DIVIDE,	// テンキー／キー
	KEY_NUMPADENTER, // テンキーのエンターキー
	KEY_F1,	// Ｆ１キー
	KEY_F2,	// Ｆ２キー
	KEY_F3,	// Ｆ３キー
	KEY_F4,	// Ｆ４キー
	KEY_F5,	// Ｆ５キー
	KEY_F6,	// Ｆ６キー
	KEY_F7,	// Ｆ７キー
	KEY_F8,	// Ｆ８キー
	KEY_F9,	// Ｆ９キー
	KEY_F10,	// Ｆ１０キー
	KEY_F11,	// Ｆ１１キー
	KEY_F12,	// Ｆ１２キー
	KEY_A,	// Ａキー
	KEY_B,	// Ｂキー
	KEY_C,	// Ｃキー
	KEY_D,	// Ｄキー
	KEY_E,	// Ｅキー
	KEY_F,	// Ｆキー
	KEY_G,	// Ｇキー
	KEY_H,	// Ｈキー
	KEY_I,	// Ｉキー
	KEY_J,	// Ｊキー
	KEY_K,	// Ｋキー
	KEY_L,	// Ｌキー
	KEY_M,	// Ｍキー
	KEY_N,	// Ｎキー
	KEY_O,	// Ｏキー
	KEY_P,	// Ｐキー
	KEY_Q,	// Ｑキー
	KEY_R,	// Ｒキー
	KEY_S,	// Ｓキー
	KEY_T,	// Ｔキー
	KEY_U,	// Ｕキー
	KEY_V,	// Ｖキー
	KEY_W,	// Ｗキー
	KEY_X,	// Ｘキー
	KEY_Y,	// Ｙキー
	KEY_Z,	// Ｚキー
	KEY_0,	// ０キー
	KEY_1,	// １キー
	KEY_2,	// ２キー
	KEY_3,	// ３キー
	KEY_4,	// ４キー
	KEY_5,	// ５キー
	KEY_6,	// ６キー
	KEY_7,	// ７キー
	KEY_8,	// ８キー
	KEY_9,	// ９キー
};

//
// Callback
//

extern "C" {
	void setup( );
	void draw( );
	void mouseClicked( );
	void mouseMoved( );
	void mouseDragged( );
	void mousePressed( );
	void mouseReleased( );
	void keyPressed( );
};

//
// method
//

int getWidth( );
int getHeight( );
int getMouseX( );
int getMouseY( );
int getLastMouseX( );
int getLastMouseY( );
int getFrameCount( );
bool isMousePressed( );
std::vector< unsigned char >& pixels( );
void size( const int width, const int height );
void background( const double gray );
void background( const double gray, const double alpha );
void background( const double v1, const double v2, const double v3 );
void background( const double v1, const double v2, const double v3, const double alpha );
void ellipse( const double x, const double y, const double diameter );
void ellipse( const double x, const double y, const double rx, const double ry );
void triangle( const Vector2& pos1, const Vector2& pos2, const Vector2& pos3 );
void triangle( const double x1, const double y1, const double x2, const double y2, const double x3, const double y3 );
void noFill( );
void fill( const double gray );
void fill( const double gray, const int alpha );
void fill( const double v1, const double v2, const double v3 );
void fill( const double v1, const double v2, const double v3, const double alpha );
void noStroke( );
void stroke( const double gray );
void stroke( const double gray, const double alpha );
void stroke( const double v1, const double v2, const double v3 );
void stroke( const double v1, const double v2, const double v3, const double alpha );
void strokeWeight( const int weight );
double random( double high );
double random( double low, double high );
int random( int high );
int random( int low, int high );
void rect( const double x1, const double y1, const double x2, const double y2 );
void line( const Vector2& pos1, const Vector2& pos2 );
void line( const double x1, const double y1, const double x2, const double y2 );
double noise( const double value );
double noise( const double value1, const double value2 );
double noise( const double value1, const double value2, const double value3 );
void loadPixels( );
int random( const int value );
void updatePixels( );
void colorMode( const SYMBOL mode );
void colorMode( const SYMBOL mode, const double max );
void colorMode( const SYMBOL mode, const double max1, const double max2, const double max3 );
void colorMode( const SYMBOL mode, const double max1, const double max2, const double max3, const double alpha_max );
void rectMode( const SYMBOL mode );
double radians( const double deg );
void point( const Vector2& pos );
void point( const double x, const double y );
void angleMode( const SYMBOL mode );
void rotate( const double angle );
void beginShape( const SYMBOL mode );
void beginShape( );
void endShape( const SYMBOL mode );
void endShape( );
void vertex( const double x, const double y );
void bezier( const double x1, const double y1,
			 const double x2, const double y2,
			 const double x3, const double y3,
			 const double x4, const double y4 );
void noLoop( );
void loop( );
double map( const double src_value,
			const double src_start, const double src_end,
			const double dst_start, const double dst_end );
double dist( const double x1, const double y1, const double x2, const double y2 );
void blendMode( const SYMBOL mode );
int getFrameRate( );
void setFrameRate( const int rate );
void translate( const Vector2& translation );
void translate( const double x, const double y );
unsigned int getKey( );
void text( const char* str, const double x, const double y );
void push( );
void pop( );
double constrain( double value, double min_value, double max_value );

