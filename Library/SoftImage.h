#pragma once

#include <string>
#include "Color.h"

class SoftImage {
	friend class Drawer;
public:
	virtual ~SoftImage( );
protected:
	SoftImage( );
public:
	Color getPixel( int x, int y );
	void writeLine( int x1, int y1, int x2, int y2, const Color& color );
	void writeCircle( int x, int y, int radius, const Color& color, bool fill );
	void writePixel( int x, int y, const Color& color );
private:
	bool load( std::string path );
	bool make( int width, int height );
private:
	int _handle;
	int _width;
	int _height;
};

