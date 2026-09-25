#include "Processing.h"
#include <vector>

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOLOR = 255;
const int DIA = 10;
const int MAXP = 10;

int mx, my;

struct Vertexes {
	int x, y;
};

std::vector<Vertexes> points;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	rectMode(CENTER);
}

void draw( ) {
	background(BACKCOLOR,20);
	beginShape( );
	for (auto& V : points)
	{
		rect(V.x, V.y, DIA, DIA);
		stroke(noise(V.x * 0.01, V.y * 0.01) * 255, 100, 150);
		vertex(V.x, V.y);
	}
	endShape(CLOSE);
}

void mouseClicked( ) {
	mx = getMouseX( );
	my = getMouseY( );
	Vertexes V;
	V.x = mx;
	V.y = my;
	points.push_back(V);
	if (points.size() > MAXP)
	{
		points.erase(points.begin( ));
	}
}


