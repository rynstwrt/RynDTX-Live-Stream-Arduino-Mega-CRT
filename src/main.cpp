#include <Arduino.h>
#include <TVout.h>


TVout TV;
int circleSize;
int maxCircleSize;
int circleRadius;
bool circleGrowing;


void setup()
{
	TV.begin(NTSC);
	
	circleSize = 0;
	maxCircleSize = TV.vres();
	circleRadius = 0;
	circleGrowing = false;
}


void drawLine()
{
	TV.draw_line(
		random(TV.hres()), 
		random(TV.vres()), 
		random(TV.hres()), 
		random(TV.vres()), 
		WHITE);
}


void drawCircleNoShrink()
{
	TV.draw_circle(TV.hres() / 2, TV.vres() / 2, circleRadius, WHITE);

	if (circleRadius == maxCircleSize)
		circleRadius = -1;

	++circleRadius;
}


void drawCircle()
{
	TV.draw_circle(TV.hres() / 2, TV.vres() / 2, circleRadius, WHITE);

	circleGrowing ? ++circleRadius : --circleRadius;

	if (circleRadius > maxCircleSize)
		circleGrowing = !circleGrowing;
	else if (circleRadius < 0)
		circleGrowing = !circleGrowing;
}


// void drawResizingCircles()
// {
// 	TV.draw_circle(TV.hres() / 2, TV.vres() / 2, circleRadius, WHITE);

// 	for (int i = 0; i < TV.vres(); i += 5)
// 	{
// 		if (circleRadius - i > 0)
// 			TV.draw_circle(TV.hres() / 2, TV.vres() / 2, circleRadius - i, WHITE);
// 	}

// 	circleGrowing ? ++circleRadius : --circleRadius;

// 	if (circleRadius > maxCircleSize / 2)
// 		circleGrowing = !circleGrowing;
// 	else if (circleRadius < 0)
// 		circleGrowing = !circleGrowing;
// }


void drawPixel()
{
	int x = random(TV.hres());
	int y = random(TV.vres());

	TV.draw_rect(x, y, 1, 1, WHITE);
}


void loop()
{
	TV.clear_screen();

	
	drawCircleNoShrink();
	drawLine();
	drawPixel();

	TV.delay(15);
}