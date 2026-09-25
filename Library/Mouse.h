#pragma once
#include "smart_ptr.h"
#include "Task.h"
#include <string>

PTR( Mouse );

enum MOUSE {
	MOUSE_LEFT_BUTTON,
	MOUSE_RIGHT_BUTTON,
	MAX_MOUSE,
};

class Mouse : public Task {
public:
	Mouse( );
	virtual ~Mouse( );
public:
	void update( );
	void setDispFlag( bool flag );
	int getX( ) const;
	int getY( ) const;
	int getWheelRotValue( ) const;
	bool isPushRightButton( ) const;
	bool isHoldRightButton( ) const;
	bool isPushLeftButton( ) const;
	bool isHoldLeftButton( ) const;
private:
	int _wheel_value;
	int _x;
	int _y;
	int _key[ MAX_MOUSE ];
};
