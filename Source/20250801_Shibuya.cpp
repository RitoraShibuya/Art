#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 0;
const int BACKALPHA = 20;
const int POINTS_NUM = 5;
const int SIZE = 10;
const int ADDSION = 500;

struct Vertex
{
	int x;
	int y;
	double ang;
	double s_width;
	double s_height;

	void Setup(int i) {
		ang = PI * i / POINTS_NUM * 2 ;
		s_width = ADDSION;
		x = CENTER_X + cos(ang) * s_width;
		y = CENTER_Y + sin(ang) * s_height;
	}

	void Draw(double m_x,double m_y) {
		s_width = ADDSION - (int)map(m_x,0,1000,0,ADDSION);
		s_height = ADDSION - (int)map(m_y,0,1000,0,ADDSION);

		x = CENTER_X + cos(ang) * s_width;
		y = CENTER_Y + sin(ang) * s_height;

		ang += 0.1;
	}
};

Vertex points[POINTS_NUM];

void setup( ) {

	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	stroke(255);
	fill(255);
	setFrameRate(15);

	for (int i = 0; i < POINTS_NUM; i++)
	{
		points[i].Setup(i);
	}

}

void draw( ) {

	background(BACKCOLOR, BACKALPHA);

	double m_x = getMouseX();
	double m_y = getMouseY();

	beginShape();
	for (int i = 0; i < POINTS_NUM; i++)
	{
		points[i].Draw(m_x,m_y);
		vertex(points[i].x, points[i].y);
	}
	endShape(CLOSE);

}


