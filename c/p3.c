#include <math.h>
#include <GL/glut.h>
#include<stdio.h>
typedef struct  {
	GLint x;
	GLint y;
}Point;

typedef struct  {
	GLfloat r;
	GLfloat g;
	GLfloat b;
}Color;

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 0, 480,-1,1);
}

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		setPixelColor(x, y, newColor);
                printf("here\n");
		floodFill(x+1, y, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);
	}
	//return;
}

void onMouseClick(int button, int state, int x, int y)
{
	Color newColor = {1.0f, 0.0f, 0.0f};
	Color oldColor = {1.0f, 1.0f, 1.0f};
        printf("%d %d",x,y);
	//floodFill(x, y, oldColor, newColor);
}

void draw_circle(Point pC, GLfloat radius) {
	//GLfloat step = 1/radius;
	GLfloat x, y;
        GLfloat theta;
	for(theta = 0; theta <= 360; theta += 1) {
		x = pC.x + (radius * cos((22.0/7.0)*theta/180.0));
		y = pC.y + (radius * sin((22.0/7.0)*theta/180.0));
		glVertex2i(x, y);
                //break;
	}
}

void display(void) {
	Point pt = {250, 250};
	GLfloat radius = 100;
        //Color color={.5,.5,0.0};
	glClear(GL_COLOR_BUFFER_BIT);
        //glPointSize(5);
	glBegin(GL_POINTS);
		draw_circle(pt, radius);
        //setPixelColor(0,0,color);

	glEnd();
	glFlush();
        Color newColor = {1.0f, 0.0f, 0.0f};
	Color oldColor=getPixelColor(250, 250); ;//= {1.0f, 1.0f, 1.0f};
        //printf("%d %d",x,y);
        //glReadPixels(250,250,1.0,1.0,GL_RGB,GL_FLOAT,oldColor);
	floodFill(250, 250, oldColor, newColor);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Open GL");
	init();
	glutDisplayFunc(display);
	//glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}
