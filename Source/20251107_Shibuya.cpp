#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CX = WIDTH / 2;
const int CY = HEIGHT / 2;
const int V_NUM = 10;
const int GAP = 500;

class Col_V {
public:
	int x, y;
	double ang;
	int gap;
public:
	void Setup(int i) {
		ang = 360 * i / V_NUM;
		gap = GAP;
		x = CX;
		y = CY;
	}
	void Draw( ) {
		stroke(noise(x * 0.01, y * 0.01, x + y * 0.005) * 360,
			   noise(x * 0.01 + 200, y * 0.01, x + y * 0.005) * 360,
			   noise(x * 0.01, y * 0.01 + 200, x + y * 0.005) * 360,
			   10);
	}
	void Update( ) {
		x = CX + cos(radians(ang)) * gap;
		y = CY + sin(radians(ang)) * gap;
		gap = noise(x * 0.01, y * 0.01) * GAP;
		ang += noise(x * 0.01, y * 0.01, x + y * 0.005 ) * 2;
	}
};

Col_V vers[ V_NUM ];

void setup( ) {
	size(WIDTH, HEIGHT);
	background(0);
	strokeWeight(5);
	for (int i = 0; i < V_NUM; i++)
	{
		vers[ i ].Setup(i);
	}
}

void draw( ) {
	//background(0, 1);
	beginShape( );
	for (int i = 0; i < V_NUM; i++)
	{
		vers[ i ].Draw( );
		vers[ i ].Update( );
		vertex(vers[ i ].x, vers[ i ].y);
	}
	endShape(CLOSE);
}


