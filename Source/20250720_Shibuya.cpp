#include "Processing.h"

const int WIDTH = 1000;

const int HEIGHT = 1000;

const int BACKGROUND_COLOR = 0;

const int BACKGROUND_GRAYSCALE = 1;

const int ELLIPSE_DIAMETER = 10;

const double CENTER_X = (double)WIDTH / 2;

const double CENTER_Y = (double)HEIGHT / 2;

const int ELLIPSE_MOVE_RANGE_1 = 100;

const int ELLIPSE_MOVE_RANGE_2 = 200;

const int ELLIPSE_MOVE_RANGE_3 = 250;

const int ANGLEADDSION = 1;

void drawEllipse();

void updateEllipse();

double _ellipse_1_x;

double _ellipse_1_y;

double _ellipse_2_x = CENTER_X;

double _ellipse_2_y = CENTER_Y;

double _ellipse_3_x = CENTER_X;

double _ellipse_3_y = CENTER_Y;

double _e_old_x = CENTER_X;

double _e_old_y = CENTER_Y;

double _angle_1 = 90;

double _angle_2 = 90;

double _angle_3 = 270;

double _size = 250;

int _rand;

void setup() {
	size(WIDTH, HEIGHT);

	background(BACKGROUND_COLOR);

	stroke(0);

	_rand = random(1,3);

}

void draw() {
	background(BACKGROUND_COLOR, BACKGROUND_GRAYSCALE);

	drawEllipse();

	updateEllipse();

	
}

void drawEllipse() {
	
	fill(0, 255, 0);

	noStroke();

	stroke(0,225,0,100);


	line(_ellipse_2_x, _ellipse_2_y, _ellipse_3_x, _ellipse_3_y);

	line(_e_old_x, _e_old_y, _ellipse_3_x, _ellipse_3_y);

}

void updateEllipse() {

	_e_old_x = _ellipse_3_x;

	_e_old_y = _ellipse_3_y;

	_ellipse_1_x = ELLIPSE_MOVE_RANGE_1 * cos(radians(_angle_1)) + CENTER_X;

	_ellipse_1_y = ELLIPSE_MOVE_RANGE_1 * sin(radians(_angle_1)) + CENTER_Y;

	_ellipse_2_x = ELLIPSE_MOVE_RANGE_2 * sin(radians(_angle_2)) + _ellipse_1_x;

	_ellipse_2_y = ELLIPSE_MOVE_RANGE_2 * cos(radians(_angle_2)) + _ellipse_1_y;

	_ellipse_3_x = ELLIPSE_MOVE_RANGE_3 * cos(radians(_angle_3)) + _ellipse_2_x;

	_ellipse_3_y = ELLIPSE_MOVE_RANGE_3 * sin(radians(_angle_3)) + _ellipse_2_y;

	_angle_1 += ANGLEADDSION;

	_angle_2 += ANGLEADDSION * (int)random(1,5);

	_angle_3 += ANGLEADDSION * (int)random(2,8);

}

