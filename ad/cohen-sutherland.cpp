#include<iostream>
#include<GL/glut.h>
#define offset 250
#define ROUND(a) ((int)(a+0.5))
GLint xmin=5, ymin=5, xmax=34, ymax=67;
void setDrawingColor(GLfloat d = 255.0, GLfloat e = 255.0, GLfloat f = 255.0)
{
	glClearColor(0.0, 0.0, 1.0, 1.0);
	glColor3f(d, e, f);
}
void setPixel(int x, int y)
{
	setDrawingColor();
	glBegin(GL_POINTS);
	glVertex2i(offset + x, offset + y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glEnd();
	glFlush();
}

typedef int OutCode;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Compute the bit code for a point (x, y) using the clip rectangle
// bounded diagonally by (xmin, ymin), and (xmax, ymax)

// ASSUME THAT xmax, xmin, ymax and ymin are global constants.

OutCode ComputeOutCode(double x, double y)
{
	OutCode code;

	code = INSIDE;          // initialised as being inside of clip window

	if (x < xmin)           // to the left of clip window
		code |= LEFT;
	else if (x > xmax)      // to the right of clip window
		code |= RIGHT;
	if (y < ymin)           // below the clip window
		code |= BOTTOM;
	else if (y > ymax)      // above the clip window
		code |= TOP;

	return code;
}
void DDA(int cor_1, int cor_2, int cor_3, int cor_4)
{
	int dx, dy, step;// offset = 250;
	dx = (cor_3 - cor_1);
	dy = (cor_4 - cor_2);
	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	setPixel(offset + cor_3, offset + cor_4);
	for (int i = 0; i < step; i++)
	{
		cor_1 = cor_1 + dx / step;
		cor_2 = cor_2 + dy / step;
		setPixel(offset + ROUND(cor_1), offset + ROUND(cor_2));
	}
}
// Cohen–Sutherland clipping algorithm clips a line from
// P0 = (x0, y0) to P1 = (x1, y1) against a rectangle with 
// diagonal from (xmin, ymin) to (xmax, ymax).
void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1)
{
	// compute outcodes for P0, P1, and whatever point lies outside the clip rectangle
	OutCode outcode0 = ComputeOutCode(x0, y0);
	OutCode outcode1 = ComputeOutCode(x1, y1);
	bool accept = false;

	while (true) {
		if (!(outcode0 | outcode1)) { // Bitwise OR is 0. Trivially accept and get out of loop
			accept = true;
			break;
		}
		else if (outcode0 & outcode1) { // Bitwise AND is not 0. Trivially reject and get out of loop
			break;
		}
		else {
			// failed both tests, so calculate the line segment to clip
			// from an outside point to an intersection with clip edge
			double x, y;

			// At least one endpoint is outside the clip rectangle; pick it.
			OutCode outcodeOut = outcode0 ? outcode0 : outcode1;

			// Now find the intersection point;
			// use formulas y = y0 + slope * (x - x0), x = x0 + (1 / slope) * (y - y0)
			if (outcodeOut & TOP) {           // point is above the clip rectangle
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
			}
			else if (outcodeOut & BOTTOM) { // point is below the clip rectangle
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			}
			else if (outcodeOut & RIGHT) {  // point is to the right of clip rectangle
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			}
			else if (outcodeOut & LEFT) {   // point is to the left of clip rectangle
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}

			// Now we move outside point to intersection point to clip
			// and get ready for next pass.
			if (outcodeOut == outcode0) {
				x0 = x;
				y0 = y;
				outcode0 = ComputeOutCode(x0, y0);
			}
			else {
				x1 = x;
				y1 = y;
				outcode1 = ComputeOutCode(x1, y1);
			}
		}
	}
	if (accept) {
		// Following functions are left for implementation by user based on
		// their platform (OpenGL/graphics.h etc.)
		//DrawRectangle(xmin, ymin, xmax, ymax);
		DDA(xmin, ymin, xmax, ymin);
		DDA(xmax, ymin, xmax, ymax);
		DDA(xmax, ymax, xmin, ymax);
		DDA(xmin, ymax, xmin, ymin);
		//LineSegment(x0, y0, x1, y1);
		DDA(x0, y0, x1, y1);
	}
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	CohenSutherlandLineClipAndDraw(10, 10, 100, 100);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}