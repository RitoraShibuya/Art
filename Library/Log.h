#pragma once
#include "Task.h"
#include <string>
#include <array>

PTR( Log );

class Log : public Task {
public:
	Log( );
	virtual ~Log( );
public:
	void draw( );
	void toggleShow( );
	void show( );
	void off( );
	void chat( const char * format, ... );
	void status( const char * format, ... );
	void chat( const std::string& str );
	void status( const std::string& str );
private:
	static const int LINES_CHAT = 30;
	static const int LINES_STATUS = 100;
private:
	void drawStatus( );
	void drawChat( );
private:
	std::array< std::string, LINES_CHAT > _line_chat;
	std::array< std::string, LINES_STATUS > _line_status;
	int _status_idx;
	bool _show;
};

