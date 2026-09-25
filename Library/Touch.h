#pragma once

#include "Task.h"
#include "mathematics.h"
#include <string>
#include <vector>

PTR( Touch );

class Touch : public Task {
public:
	struct Data {
		int x = 0;
		int y = 0;
		int id = 0;
		Data( ) { }
		Data( int x_, int y_, int id_ ) : x( x_ ), y( y_ ), id( id_ ) { }
	};
public:
	Touch( );
	virtual ~Touch( );
public:
	std::vector< Data > getData( ) const;
private:
	void update( );
private:
	std::vector< Data > _data;
};
