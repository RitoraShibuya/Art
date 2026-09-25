#pragma once

#include "smart_ptr.h"
#include <string>

PTR( Binary );

class Binary {
public:
	Binary( );
	virtual ~Binary( );
public:
	bool read( void* data, int size );
	void write( void* data, int size );
	bool save( std::string filename );
	bool load( std::string filename );
	void seek( );
	void ensure( int size );
	int getSize( ) const;
	void* getPtr( );
private:
	unsigned char* _data;
	unsigned int _size;
	unsigned int _pos;
};

