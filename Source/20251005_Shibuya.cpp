#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CEN_X = WIDTH / 2;
const int CEN_Y = HEIGHT / 2;
const int BACKCOL = 0;
const int GAP = 500;
const double NOISE = 0.01;
const int L_DIA = 10;
const int SPD = 3;
const int MAX_L = 50;

int Framecount = 0;
int cx;
int cy;


struct CP {
	int x, y;
	int ang;
};

class CL {
public:
	int x, y;
	int ang;
public:
	void Setup(int sx, int sy) {
		x = sx;
		y = sy;
		ang = noise(x * NOISE, y * NOISE) * 360;
	};
	void Draw( ) {
		fill(noise(x * NOISE, y * NOISE, ang * NOISE) * 360, 100, 100, 5);
		ellipse(x, y, L_DIA);
	};
	void Update( ) {
		x = x + cos(radians(ang)) * SPD;
		y = y + sin(radians(ang)) * SPD;
		ang = (noise(x * NOISE, y * NOISE) - 0.5) * 360;
	};
};

CP cen_p;
std::vector<CL> c_lines;

void setup( ) {

	size(WIDTH, HEIGHT);
	background(BACKCOL);
	colorMode(HSB, 360, 100, 100,100);
	noStroke( );

	cen_p.ang = 0;
	int x = CEN_X + cos(radians(cen_p.ang)) * GAP;
	int y = CEN_Y + sin(radians(cen_p.ang)) * GAP;
	cen_p = { x,y,0 };
}

void draw( ) {
	int gap = noise(cx * NOISE, cy * NOISE, cen_p.ang * NOISE) * GAP ;
	cx = CEN_X + cos(radians(cen_p.ang)) * gap;
	cy = CEN_Y + sin(radians(cen_p.ang)) * gap;

	if (Framecount % 3 == 0) {
		CL C;
		C.Setup(cx, cy);
		c_lines.push_back(C);
		if (c_lines.size( ) > MAX_L)
		{
			c_lines.erase(c_lines.begin( ));
		}
	}

	for (auto& C : c_lines)
	{
		C.Draw( );
		C.Update( );
	}

	cen_p.ang++;
	Framecount++;
}


