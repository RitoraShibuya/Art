#include "Processing.h"

const int WIDTH = 1000;

const int HEIGHT = 1000;

const int BACKGROUNDCOLOR = 0;

const int BACKGROUNDCOLORGRAYSCALE = 0;

const double CENTER_X = (double)WIDTH / 2;

const double CENTER_Y = (double)HEIGHT / 2;

const int DRAWNUM = 100;

const int SHAPEALPHA = 50;

void drawEllipse();

void drawRect();

void drawDiamond();



void setup( ) {

	size(WIDTH, HEIGHT);

	background(BACKGROUNDCOLOR);

	setFrameRate(5);

	noStroke();
}

void draw( ) {

	

	switch ((int)random(1, 4))
	{
	default:
	case 1:drawEllipse();
		break;
	case 2:drawRect();
		break;
	case 3:drawDiamond();
		break;
	}

	

	
}

void drawEllipse() {

	int nowsize = getWidth() * 1.5;

	int r = random(255);

	int g = random(255);

	int b = random(255);

	double num_e = DRAWNUM * 1.5;

	for (int i = 0; i < num_e; i++)
	{

		fill(r - ((r / num_e) * i),g -(g / num_e * i),b - (b / num_e * i),SHAPEALPHA);

		ellipse(CENTER_X, CENTER_Y, nowsize);
		
		nowsize -= getWidth() / num_e;
	}

}

void drawRect() {

	int nowsize = getWidth(); 
	int r = random(255);     
	int g = random(255);      
	int b = random(255);      

	for (int i = 0; i < DRAWNUM; i++) {

		fill(r - ((r / DRAWNUM) * i), g - ((g / DRAWNUM) * i), b - ((b / DRAWNUM) * i), SHAPEALPHA);

		rect(CENTER_X - nowsize / 2, CENTER_Y - nowsize / 2, nowsize, nowsize);


		nowsize -= getWidth() / DRAWNUM;
	}
}



void drawDiamond() {

	int nowsize = getWidth(); 

	int r = random(255);      
	int g = random(255);      
	int b = random(255);      

	for (int i = 0; i < DRAWNUM; i++) {

		

		beginShape();
		stroke(r - ((r / DRAWNUM) * i), g - ((g / DRAWNUM) * i), b - ((b / DRAWNUM) * i), SHAPEALPHA);
		vertex(CENTER_X, CENTER_Y - nowsize / 2);            // ã
		vertex(CENTER_X + nowsize / 2, CENTER_Y);            // ‰E
		vertex(CENTER_X, CENTER_Y + nowsize / 2);            // ‰º
		vertex(CENTER_X - nowsize / 2, CENTER_Y);            // ¶
		endShape(CLOSE);

		nowsize -= getWidth() / DRAWNUM;
	}

}