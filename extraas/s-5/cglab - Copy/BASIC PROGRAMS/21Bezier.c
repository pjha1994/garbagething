#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
struct Point {
	double x,y;
}p[50];
int noPts;
void setPixelSize(GLint x, GLint y, int size) {
	glEnable(GL_POINT_SMOOTH);
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
double calcFact(int n) {
	double fact = 1, i;
 	for(i = 1; i <= n ; i++){
		fact *= i;
	}
	return fact;
}
double calcBC(int n, int i) {
	double binC = 0;
	binC = calcFact(n)/(calcFact(n-i) * calcFact(i));
	return binC;
}
void draw(void){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);

	double  u = 0;
	int i = 0;
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_STRIP);

	for(u = 0; u <= 1.0; u += 0.0005){
	   double x = 0;	
	   double y = 0;
	   for(i = 0; i < noPts; i++) {
		x += calcBC((noPts-1), i) * (pow ((1-u), ((noPts-1)-i)) * pow(u, i) * p[i].x);
				
		y += calcBC((noPts-1), i) * (pow ((1-u), ((noPts-1)-i)) * pow(u, i) * p[i].y);
		
	   }
	   glVertex2f(x,y);
				
	}
	glEnd();   
	glColor3f(0,0,0);
	for(i = 0; i < noPts; i++) {
		setPixelSize(p[i].x, p[i].y, 6);	
	}
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

	noPts = 4;
	/*printf("Enter Control Point P0(x1, y1):");
	scanf("%f %f", &p0.x, &p0.y);

	printf("Enter Control Point P1(x1, y1):");
	scanf("%f %f", &p1.x, &p1.y);

	printf("Enter Control Point P2(x1, y1):");
	scanf("%f %f", &p2.x, &p2.y);

	printf("Enter Control Point P3(x1, y1):");
	scanf("%f %f", &p3.x, &p3.y);*/
	p[0].x = 50; p[0].y = 100;
	p[1].x = 100; p[1].y = 200;
	//p2.x = 150; p2.y = 200;
	p[2].x = 150; p[2].y = 50;
	p[3].x = 200; p[3].y = 100;

	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
