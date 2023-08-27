#include <Arduino.h>
#include <TVout.h>


TVout TV;
int currentSize;
int maxSize;
int radius;


void setup()
{
	TV.begin(NTSC);
	currentSize = 0;
	maxSize = TV.vres();
	radius = 1;
}


void loop()
{
	TV.clear_screen();

	TV.draw_circle(TV.hres() / 2, TV.vres() / 2, radius, WHITE);
	++radius;
	if (radius > maxSize)
		radius = 1;

	int x1 = random(TV.hres());
	int y1 = random(TV.vres());
	int x2 = random(TV.hres());
	int y2 = random(TV.vres());

	TV.draw_line(x1, y1, x2, y2, WHITE);

	TV.delay(10);
}