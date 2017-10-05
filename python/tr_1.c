#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int millis = 1;
float clr[9] ={ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
float temp = 0.0;

void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(millis, timer, 0);
}

void circlepara(int xc, int yc, int r, float c1, float c2, float c3){
	float x, y;
	int i;
	for (i = 0; i < 90; i++){
		x = r*cos(3.142*i / 180);
		y = r*sin(3.142*i / 180);
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(c1, c2, c3);
		glVertex2d(x + xc, y + yc);
		glVertex2d(x + xc, -y + yc);
		glVertex2d(-x + xc, y + yc);
		glVertex2d(-x + xc, -y + yc);
		glEnd();

	}

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-250, 250, -250, 250,-1,1);
	
	glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
	circlepara(-100, 0, 15, clr[0],clr[1],clr[2]);
	circlepara(-100, -50, 15, clr[3], clr[4], clr[5]);
	circlepara(-100, -100, 15, clr[6], clr[7], clr[8]);
	glFlush();
	glPopMatrix();
	glFlush();
	temp += 0.02f;
	if (temp <= 10.0f){
		clr[1] = 0.0;
		clr[2] = 0.0;
	}
	else
	if (temp <= 20.0f){
		clr[1] = 1.0;
		clr[2] = 1.0;
		clr[5] = 0.0;
	}
	else
	if (temp <= 30.0f){
		clr[5] = 1.0;
		clr[6] = 0.0;
		clr[8] = 0.0;
	}
	else{
		clr[6] = 1.0;
		clr[8] = 1.0;
		temp = 0.0f;
	}
}

void myinit(void){
	glClearColor(0.0, 0.0, 0.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("PROGRAM");
	myinit();
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}
