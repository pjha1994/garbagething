#include<GL/glut.h>
#include<iostream>
using namespace std;
int center_x, center_y, radius;
struct Point{
	GLint x;
	GLint y;
};
struct Color{
	GLfloat r, g, b;
};
void setDrawingColor(GLfloat d, GLfloat e, GLfloat f)
{
	glColor3f(d, e, f);
}
void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(GLint x, GLint y)
{

	setDrawingColor(0.0,1.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(250+x,250+ y);
	glEnd();
	glFlush();
}

void setAxes()
{
	setDrawingColor(0.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glEnd();
	glFlush();
}

void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON&&state == GLUT_DOWN)
		exit(0);
}
void rotate_circle(int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int decisionOver2 = 1 - x;   // Decision criterion divided by 2 evaluated at x=r, y=0

	while (x >= y)
	{
		setPixel(x + x0, y + y0);
		setPixel(y + x0, x + y0);
		setPixel(-x + x0, y + y0);
		setPixel(-y + x0, x + y0);
		setPixel(-x + x0, -y + y0);
		setPixel(-y + x0, -x + y0);
		setPixel(x + x0, -y + y0);
		setPixel(y + x0, -x + y0);
		y++;
		if (decisionOver2 <= 0)
		{
			decisionOver2 += 2 * y + 1;   // Change in decision criterion for y -> y+1
		}
		else
		{
			x--;
			decisionOver2 += 2 * (y - x) + 1;   // Change for y -> y+1, x -> x-1
		}
	}
	glPushMatrix();
	glTranslatef(x, y, 0);  // Moves rotated circle to desired location.
	glRotatef(10, 0, 0, 1);
	glTranslatef(-x, -y, 0);  // Centers circle at origin.
	//newCircle(x, y, r);
	glPopMatrix();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	setAxes();
	rotate_circle(center_x,center_y,radius);
}
int main(int argc, char **argv)
{
	cout << "Enter the coordinates\n";
	cin >> center_x >> center_y >> radius;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("opengl");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutMainLoop();
	return 0;
}