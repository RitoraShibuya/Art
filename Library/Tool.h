#pragma once
#include "mathematics.h"
#include "Color.h"

class Tool {
private:
	Tool( );
	~Tool( );
public:
	static int getRand( int n );
	static void setSeed( int seed );
	static void createDirectory( const char* path );
	static bool deleteDirectory( const char* path );
	static Color makeColorFromHSB( const double h, const double s, const double b, const double alpha = 0.0 );
};

