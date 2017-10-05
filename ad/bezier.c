
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
struct Point
{
	float x, y;
}p[50];
int noPts;

void setpixel(float x, float y)
{
	glPointSize(5);
	glBegin(GL_POINTS);

	glVertex2f(x, y);
	glEnd();
}
float calcFact(int n)
{
	float fact = 1, i;
	for (i = 1; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}
float calcBC(int n, int i)
{
	float binC = 0;
	binC = calcFact(n) / (calcFact(n - i) * calcFact(i));
	return binC;
}
void draw()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	float  u = 0;
	int i = 0;
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_STRIP);

	for (u = 0; u <= 1.0; u += 0.0005)
	{
		float x = 0;
		float y = 0;
		for (i = 0; i < noPts; i++)
		{
			x += calcBC((noPts - 1), i) * (pow((1 - u), ((noPts - 1) - i)) * pow(u, i) * p[i].x);

			y += calcBC((noPts - 1), i) * (pow((1 - u), ((noPts - 1) - i)) * pow(u, i) * p[i].y);

		}
		glVertex2f(x, y);

	}
	glEnd();
	glColor3f(0, 0, 0);
	for (i = 0; i < noPts; i++)
	{
		setpixel(p[i].x, p[i].y);
	}
	glFlush();
}
void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	draw();
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	int q;
	printf("Enter no of Control Points :");
	scanf_s("%d", &noPts);

	for (q = 0; q<(int)noPts; q++)
	{
		printf("Enter Control Point P%d(x1, y1):", q);
		scanf_s("%f %f", &p[q].x, &p[q].y);
	}


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("curve");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

