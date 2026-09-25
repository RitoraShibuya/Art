#include "Processing.h"

double constrain(double val, double minVal, double maxVal) {
	if (val < minVal) return minVal;
	if (val > maxVal) return maxVal;
	return val;
}

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int CENTER_X = WIDTH / 2;
const int CENTER_Y = HEIGHT / 2;
const int BACKCOLOR = 255;
const int BACKALPHA = 50;
const int E_SIZE = 200;
const double E_SPD = 100;
const double FRICTION = 1;
const double DECAY = 0.1;

struct ELLIPSE
{
	double x;
	double y;
	double spd;
	double rad_x;
	double rad_y;

	void SetUp()
	{
		x = CENTER_X;
		y = CENTER_Y;
		spd = 0;
	}

	void SpdSet(double cx, double cy)
	{
		double dx = cx - x;
		double dy = cy - y;
		double len = sqrt(dx * dx + dy * dy);

		if (len != 0) {
			rad_x = -dx / len;
			rad_y = -dy / len;
		} 
		spd = E_SPD - len * DECAY;
		if (spd < 0) spd = 0;
	}

	void SpdUpdate()
	{
		fill(255,80);
		stroke(0);
		strokeWeight(1);
		ellipse(x, y, E_SIZE);

		if (spd > 0)
		{
			x += spd * rad_x;
			y += spd * rad_y;

			if (x <= E_SIZE / 2 || x >= WIDTH - E_SIZE / 2) {
				rad_x *= -1;
				x = constrain(x, E_SIZE / 2, WIDTH - E_SIZE / 2);
			}
			if (y <= E_SIZE / 2 || y >= HEIGHT - E_SIZE / 2) {
				rad_y *= -1;
				y = constrain(y, E_SIZE / 2, HEIGHT - E_SIZE / 2);
			}

			spd -= FRICTION;
			if (spd < 0) spd = 0;
		}
	}

};

ELLIPSE ball;

void setup() {
	size(WIDTH, HEIGHT);
	background(BACKCOLOR);
	//setFrameRate(10);
	ball.SetUp();
}

void mouseClicked()
{
	double cx = getMouseX();
	double cy = getMouseY();
	ball.SpdSet(cx, cy);
}

void draw()
{
	ball.SpdUpdate();
	background(BACKCOLOR,BACKALPHA);
	if (ball.spd == 0)
	{
		stroke(0);
		strokeWeight(10);
		line(ball.x, ball.y, getMouseX(), getMouseY());
	}
}


