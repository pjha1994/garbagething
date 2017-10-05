#include<GL/glut.h>
#define offset 250
void setDrawingColor(GLfloat d, GLfloat e, GLfloat f)
{
	glColor3f(d, e, f);
}
void init()
{
	glClearColor(.0, .0, .0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setAxes()
{
	setDrawingColor(1.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	setDrawingColor(1.0, 0.0, 0.0);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	setDrawingColor(1.0, 1.0, 0.0);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	setDrawingColor(0.0, 1.0, 1.0);
	glVertex2i(50, 250);
	glVertex2i(250, 250);
	setDrawingColor(0.0, 0.0, 1.0);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glEnd();
	glFlush();
}
void setPixel(GLint x, GLint y)
{
	setDrawingColor(0.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(offset+x, offset + y);
	glEnd();
	glFlush();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	setAxes();
	for (int i = 0; i < 200; i++){
		setPixel(i, i);
		setPixel(-i, i);
		setPixel(-i, -i);
		setPixel(i, -i);
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OPenGl");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}