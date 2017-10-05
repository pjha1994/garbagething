#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
struct Point {
	double x,y;
}p0,p1,p2,p3;

void setPixelSize(GLint x, GLint y, int size) {
	glEnable(GL_POINT_SMOOTH);
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void draw(void){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);

	double  u = 0;
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_STRIP);

	for(u = 0; u <= 1.0; u += 0.0005){
		double x =  (pow ((1-u), 3) * p0.x) 
				+ (3 * u * pow((1-u), 2) * p1.x) 
				+ (3 * pow(u, 2) *(1-u)*p2.x) 
				+ (pow(u, 3) * p3.x);	
		double y =  (pow ((1-u), 3) * p0.y) 
			    + (3 * u * pow((1-u), 2) * p1.y) 
			    + (3 * pow(u, 2) *(1-u)*p2.y) 
			    + (pow(u, 3) * p3.y);	
		glVertex2f(x,y);
				
	}
	glEnd();   
	glColor3f(0,0,0);
	setPixelSize(p0.x, p0.y, 6);
	setPixelSize(p1.x, p1.y, 6);
	setPixelSize(p2.x, p2.y, 6);
	setPixelSize(p3.x, p3.y, 6);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,25);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Green Window");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,500.0,0.0,500.0);

	/*printf("Enter Control Point P0(x1, y1):");
	scanf("%f %f", &p0.x, &p0.y);

	printf("Enter Control Point P1(x1, y1):");
	scanf("%f %f", &p1.x, &p1.y);

	printf("Enter Control Point P2(x1, y1):");
	scanf("%f %f", &p2.x, &p2.y);

	printf("Enter Control Point P3(x1, y1):");
	scanf("%f %f", &p3.x, &p3.y);*/
	p0.x = 50; p0.y = 100;
	p1.x = 100; p1.y = 200;
	//p2.x = 150; p2.y = 200;
	p2.x = 150; p2.y = 50;
	p3.x = 200; p3.y = 100;

	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
