//fixed floodfill pastebin.com/BwCgJ7Sj
#include<GL/glut.h>
struct Col
{
	GLfloat r, g, b;
} currentColor, oldColor, fillColor;
void setPixel(int x, int y,Col fillColor)
{
	glColor3f(fillColor.r, fillColor.g, fillColor.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void drawsquare()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(10, 10);
	glVertex2i(410, 10);
	glVertex2i(410, 10);
	glVertex2i(410, 410);
	glVertex2i(410, 410);
	glVertex2i(10, 410);
	glVertex2i(10, 410);
	glVertex2i(10, 10);
	glEnd();
	glFlush();
}
void init()
{

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
void floodfill(int x, int y ,Col oldColor,Col fillColor)
{
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &currentColor);
	if (currentColor.r == oldColor.r&&currentColor.g == oldColor.g&&currentColor.b == oldColor.b)
	{
		setPixel(x, y, fillColor);
		floodfill(x, y + 1,  oldColor, fillColor);
		floodfill(x, y - 1,  oldColor, fillColor);
		floodfill(x - 1, y,  oldColor, fillColor);
		floodfill(x + 1, y ,  oldColor, fillColor);
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawsquare();
	fillColor = { 0.0, 1.0, 1.0 };
	glReadPixels(351, 351, 1.0, 1.0, GL_RGB, GL_FLOAT, &oldColor);
	floodfill(351, 351, oldColor, fillColor);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}