#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;
const int SPD = 5;

class Col_E {
public:
	int x, y;
	int ang;
	int dia;
public:
	void Setup(int sx, int sy) {
		x = sx;
		y = sy;
		ang = (int)random(360);
		dia = (int)random(50, 200);
	};
	void Draw( ) {
		ellipse(x, y, dia);
	};
	void Update( ) {
		x += cos(radians(ang)) * SPD;
		y += sin(radians(ang)) * SPD;
	};
};

std::vector<Col_E> c_e;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
}

void draw( ) {
	background(BACKCOL);
	colorMode(HSB, 360, 100, 100);
	int mx = getMouseX( );
	int my = getMouseY( );
	fill(255, 100, 100);
	for (auto& E : c_e)
	{
		E.Draw( );
		E.Update( );
	}
	blendMode(MULTIPLY);
	for (int x = 0; x < WIDTH; x += 10)
	{
		for (int y = 0; y < HEIGHT; y += 10)
		{
			fill(noise(x * 0.01, y * 0.01) * 360, 100, 100);
			rect(x, y, 10, 10);
		}
	}
	blendMode(BLEND);
	stroke(360, 100, 100);
	strokeWeight(10);
	line(WIDTH, HEIGHT, mx, my);
	line(0, HEIGHT, mx, my);
}

void mouseClicked( ) {
	c_e.clear( );
	for (int i = 0; i < 10; i++)
	{
		Col_E E;
		E.Setup(getMouseX( ), getMouseY( ));
		c_e.push_back(E);
	}
}
