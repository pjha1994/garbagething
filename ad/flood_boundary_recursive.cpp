#include<GL/glut.h>
struct Color{
	GLfloat r, g, b;
};
void init()
{
	glClearColor(0.0, 0.3, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 400, 0, 400);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(int x, int y, Color color)
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void draw()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(100 , 100);
	glVertex2i(150 , 100);
	glVertex2i(150, 100);
	glVertex2i(150, 150);
	glVertex2i(150, 150);
	glVertex2i(100, 150);
	glVertex2i(100, 150);
	glVertex2i(100, 100);
	glEnd();
	glFlush();
}
void boundaryfill(int x, int y, Color boundary,Color fill)
{
	Color current;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &current);
	if (current.r == boundary.r&&current.g != boundary.g&&current.b != boundary.b)
	{
		setPixel(x, y, fill);
		boundaryfill(x - 1, y, boundary, fill);
		boundaryfill(x + 1, y, boundary, fill);
		boundaryfill(x, y-1, boundary, fill);
		boundaryfill(x, y+1, boundary, fill);
	}
}
void floodfill(int x,int y,Color newColor,Color oldColor)
{
	Color current;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &current);
	if (current.r == oldColor.r&&current.g == oldColor.g&&current.b == oldColor.b)
	{
		setPixel(x, y, newColor);
		floodfill(x - 1, y, newColor, oldColor);
		floodfill(x + 1, y, newColor, oldColor);
		floodfill(x, y - 1, newColor, oldColor);
		floodfill(x, y + 1, newColor, oldColor);
	}
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	Color boundary = {0.0,1.0,1.0}, fill = { 0.0, 1.0, 0.0 };
	boundaryfill(120, 120, boundary, fill);
	Color newColor = {0.0,0.0,1.4}, oldColor;
	glReadPixels(125, 125, 1, 1, GL_RGB, GL_FLOAT, &oldColor);
	floodfill(125, 125, newColor, oldColor);
}
int main(int argc,char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("try");
	init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}