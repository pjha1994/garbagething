#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
struct Point {
	double x,y;
}ctlp[50];
int noCtrlPts,k, t[100];
void setPixelSize(GLint x, GLint y, int size) {
	glEnable(GL_POINT_SMOOTH);
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
double calc_knot_value() {
	int i = 0;
	// ti  (0 < i < (n+k)) are called knot values
	// ti = 0 if i < k
	// ti = i-k+1 if k <= i <= n
	// ti = n-k+2 if i > n

	for(i = 0; i < ((noCtrlPts-1) + k); i++) {
		if( i < k) {
			t[i] = 0;
		}else if(k <= i && i <= (noCtrlPts-1)) {
			t[i] = i - k + 1;
		}else if(i > (noCtrlPts-1)) {
			t[i] = (noCtrlPts-1) - k + 2;
		}
		//printf("%d \n", t[i]);
	}
}
double bsplineFun(int i, int k, double u) {
	double result = 0;
	if( k == 1) {
		if(t[i] <= u  && u <= t[i+1]) {
			return 1;
		}else {
			return 0;
		}
	}
	if( (t[i+k-1] - t[i]) != 0) {
		result += (double) (((u - t[i]) * bsplineFun(i, k - 1, u)) / (t[i+k-1] - t[i]));
	}
	if((t[i+k] - t[i+1]) != 0) {
		result += (double) (((t[i+k] - u) * bsplineFun(i+1, k - 1, u)) / (t[i+k] - t[i+1]));
	}
	
	//printf("%f \n", result);
	return result;
}
void draw(void){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);

	double u = 0, x, y;
	int i;

	calc_knot_value();
	// u < 0 < n - k +2 Where n = No of Contoll Points
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_STRIP);

	for(u = 0; u < ((noCtrlPts-1) - k + 2); u += 0.0005) {
		x = 0; y = 0;
		for(i = 0; i < noCtrlPts; i++) {
			x += ctlp[i].x * bsplineFun(i, k, u);
			y += ctlp[i].y * bsplineFun(i, k, u);
		}
		//printf("%f \t %f \n", x, y);	
		glVertex2f(x,y);	
	}
	glEnd(); 
	glColor3f(0,0,0);
	for(i = 0; i < noCtrlPts; i++) {
		setPixelSize(ctlp[i].x, ctlp[i].y, 6);	
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

	noCtrlPts = 7;
	k = 3;
	/*printf("Enter Control Point P0(x1, y1):");
	scanf("%f %f", &p0.x, &p0.y);

	printf("Enter Control Point P1(x1, y1):");
	scanf("%f %f", &p1.x, &p1.y);

	printf("Enter Control Point P2(x1, y1):");
	scanf("%f %f", &p2.x, &p2.y);

	printf("Enter Control Point P3(x1, y1):");
	scanf("%f %f", &p3.x, &p3.y);*/
	ctlp[0].x = 50; ctlp[0].y = 100;
	ctlp[1].x = 30; ctlp[1].y = 400;	
	ctlp[2].x = 150; ctlp[2].y = 450;
	ctlp[3].x = 250; ctlp[3].y = 450;
	ctlp[4].x = 200; ctlp[4].y = 75;
	ctlp[5].x = 280; ctlp[5].y = 50;
	ctlp[6].x = 350; ctlp[6].y = 300;

	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
