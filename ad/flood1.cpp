//fixed floodfill pastebin.com/9wBLQgSW	
#include<GL/glut.h>
struct Col
{
	float r, g, b;
};
void setPixel(int x, int y,Col fillColor)
{
	glPointSize(10);
	glColor3f(fillColor.r, fillColor.g, fillColor.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void drawsquare()
{
	glLineWidth(10);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(0, 0);
	glVertex2i((400)/2, 0);
	glVertex2i((400)/2, 0);
	glVertex2i((400)/2, (400)/2);
	glVertex2i((400)/2, (400)/2);
	glVertex2i(0, (400)/2);
	glVertex2i(0, (400)/2);
	glVertex2i(0, 0);
	glEnd();
	glFlush();
}
void init()
{
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
void floodfill(int x, int y, Col oldColor, Col fillColor)
{
	Col currentColor;
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &currentColor);
	if (currentColor.r == oldColor.r&&currentColor.g == oldColor.g&&currentColor.b == oldColor.b)
	{
		setPixel(x, y, fillColor);
		floodfill(x+10, y, oldColor, fillColor);
		floodfill(x - 10, y, oldColor, fillColor);
		floodfill(x, y + 10, oldColor, fillColor);
		floodfill(x, y - 10, oldColor, fillColor);
		//floodfill(x, y + 1, oldColor, fillColor);
		//floodfill(x, y + 1, oldColor, fillColor);
		//floodfill(x, y + 1, oldColor, fillColor);
		//floodfill(x, y + 1, oldColor, fillColor);
		//floodfill(x - 1, y - 1, oldColor, fillColor);
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawsquare();
	Col oldColor, fillColor = { 0.0, 1.0, 0.0 };
	glReadPixels(59, 59, 1.0, 1.0, GL_RGB, GL_FLOAT, &oldColor);
	floodfill(50, 50, oldColor, fillColor);
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