#include<GL/glut.h>
#include<iostream>
GLint length = 50;
GLint X, Y;
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
	glClearColor(0.0, 0.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(GLint x, GLint y, Color setColor)
{
	setDrawingColor(setColor.r, setColor.g, setColor.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
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
void DDA(Point a, Point b, Color myLineColor)
{
	GLint x1 = a.x;
	GLint y1 = a.y;
	GLint x2 = b.x;
	GLint y2 = b.y;
	setPixel(x1, y1, myLineColor);
	setPixel(x2, y2, myLineColor);
	GLint dx = x2 - x1;
	GLint dy = y2 - y1;
	GLint steps = abs(dy);//ASSUMED
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	GLfloat incrx = dx / float(steps);
	GLfloat incry = dy / float(steps);
	for (GLint i = 0; i < steps; i++)
	{
		x1 = x1 + incrx;
		y1 = y1 + incry;
		setPixel(x1, y1, myLineColor);
	}
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	setAxes();
	glFlush();
}
void myMouse(int btn,int state,int x,int y)
{
	//if (btn == GLUT_LEFT_BUTTON&&state == GLUT_DOWN)
		//exit(0);
}
void draw_square(int x, int y)
{
    Point a, b, c, d;
	a.x = x; a.y = 500-y;
	b.x = x + length; b.y =500- y;
	c.x = x + length; c.y = 500-y + length;
	d.x = x; d.y = 500-y + length;
	Color myLineColor = { 0.0, 0.0, 0.0 };
	DDA(a, b, myLineColor);
	DDA(b, c, myLineColor);
	//myLineColor = { 0.0, 0.0, 1.0 }; //For changing color of a line between two points
	DDA(c, d, myLineColor);
	DDA(d, a, myLineColor);
	myLineColor = { 0.0, 1.0, 0.0 };
	//for (int i = 0; i < 360; i++)
	///{
		//setPixel(x + 30 * cos(3.14*i / 180.0), y + 30 * sin(3.14*i / 180.0), myLineColor);
	//}
	//glColor3f(0.0, 1.0, 0.0);
	//glPointSize(10);
	//glBegin(GL_POINTS);
	//glVertex2i(x, 500-y);
	//glEnd();
	//glFlush();
}
void myKeyboard(unsigned char c, int x, int y)
{
	if (c == 'a'||c=='A')
		exit(0);
	else
		draw_square(x, y);
}
void demo_menu(int id)
{
	switch (id)
	{
	case 1:exit(0);
		break;
	case 2:draw_square(30,30);
		break;
	case 3:
		Color myLineColor = { 0.0, 0.0, 1.0 };
		//for (int i = 0; i < 360; i++)
		//{
			//setPixel(30 + 30 * cos(3.14*i / 180.0), 30 + 30 * sin(3.14*i / 180.0), myLineColor);
		//}
		break;
	}
	glutPostRedisplay();
}
void demo_menu1(int id)
{
	switch (id)
	{
	case 1:exit(0); break;
	case 2:
		draw_square(100, 100); break;
	case 3:
		draw_square(250, 250); break;
	}
	glutPostRedisplay();
}
void size_menu(int id)
{
	switch (id)
	{
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void top_menu(int id)
{
	switch (id)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
	glutPostRedisplay();

}
void menu()
{
	int x=glutCreateMenu(size_menu);
	glutAddMenuEntry("increase square size", 2);
	glutAddMenuEntry("decrease square size", 3);
	glutCreateMenu(top_menu);
	glutAddMenuEntry("quit", 1);
	glutAddSubMenu("Resize", x);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutCreateMenu(demo_menu1);
	glutAddMenuEntry("quit", 1);
	glutAddMenuEntry("increase square size", 2);
	glutAddMenuEntry("decrease square size", 3);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}
int main(int argc, char **argv)
{
	std::cout << "Select the screen by double clicking on it and drag to draw squares";
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Hello\n");
	init();
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutMotionFunc(draw_square);
	//menu();
	glutMainLoop();
	return 0;
}