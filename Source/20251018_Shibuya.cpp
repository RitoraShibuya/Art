#include "Processing.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int BACKCOL = 0;

int Framecount = 10;
int Switch = 0;
int Switch2 = 1;
int Switch3 = 2;
int Switch4 = 3;

void setup( ) {
	size(WIDTH, HEIGHT);
	background(BACKCOL);
	blendMode(ADD);
}

void draw( ) {

	int x = Framecount % 1000;

	if (x == 0) {
		if (Switch == 3) {
			Switch = 0;
		}
		else {
			Switch++;
		}
		if (Switch2 == 3) {
			Switch2 = 0;
		}
		else {
			Switch2++;
		}
		if (Switch3 == 3) {
			Switch3 = 0;
		}
		else {
			Switch3++;
		}
		if (Switch4 == 3) {
			Switch4 = 0;
		}
		else {
			Switch4++;
		}
	}

	stroke(noise(x * 0.09, x * 0.09, Framecount * 0.09) * 255,
		   noise(x * 0.09 + 100, x * 0.09, Framecount * 0.09) * 255,
		   noise(x * 0.09, x * 0.09 + 100, Framecount * 0.09) * 255, 5);
	strokeWeight(10);

	switch (Switch) {
	case 0:
		line(x, 0, 0, x);
		break;
	case 1:
		line(1000, x, x, 1000);
		break;
	case 2:
		line(0, 1000 - x, x, 1000);
		break;
	case 3:
		line(x, 0, 1000, 1000 - x);
		break;
	}

	switch (Switch2) {
	case 0:
		line(x, 0, 0, x);
		break;
	case 1:
		line(1000, x, x, 1000);
		break;
	case 2:
		line(0, 1000 - x, x, 1000);
		break;
	case 3:
		line(x, 0, 1000, 1000 - x);
		break;
	}

	switch (Switch3) {
	case 0:
		line(x, 0, 0, x);
		break;
	case 1:
		line(1000, x, x, 1000);
		break;
	case 2:
		line(0, 1000 - x, x, 1000);
		break;
	case 3:
		line(x, 0, 1000, 1000 - x);
		break;
	}

	switch (Switch4) {
	case 0:
		line(x, 0, 0, x);
		break;
	case 1:
		line(1000, x, x, 1000);
		break;
	case 2:
		line(0, 1000 - x, x, 1000);
		break;
	case 3:
		line(x, 0, 1000, 1000 - x);
		break;
	}


	Framecount += 2;
}


