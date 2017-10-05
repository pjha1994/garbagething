/*#include<iostream>
#include<GL/glut.h>
#include<math.h>
float trans = 0.0f;
//int xc, yc, r;
int millis = 30;
void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(millis, timer, 0);
}

void parametric(int xc, int yc, int r){
	float x, y;
	for (int i = 0; i < 90; i++){
		x = r*cos(3.142*i / 180);
		y = r*sin(3.142*i / 180);
		glBegin(GL_POINTS);
		glVertex2d(x + xc, y + yc);
		glVertex2d(x + xc, -y + yc);
		glVertex2d(-x + xc, y + yc);
		glVertex2d(-x + xc, -y + yc);
		glEnd();
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glPushMatrix();
	parametric(10, 10, 10);
	parametric(50, 10, 10);
	//poly();
	glTranslatef(trans, 0.0f, 0.0f);
	
	
	//glPopMatrix();
	glFlush();
	trans += -0.005f;

	//

}
void init(){
	glClearColor(0.0, 0.0, 0.0, 0);
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CAR");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}*/
/*
#include<iostream>
#include<GL/glut.h>
#include<math.h>
float trans = 0.0f;
float retrans = 0.0f;
//int xc, yc, r;
int millis = 30;
void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(millis, timer, 0);
}

void parametric(int xc, int yc, int r){
	float x, y;
	for (int i = 0; i < 90; i++){
		x = r*cos(3.142*i / 180);
		y = r*sin(3.142*i / 180);
		glBegin(GL_POINTS);
		glVertex2d(x + xc, y + yc);
		glVertex2d(x + xc, -y + yc);
		glVertex2d(-x + xc, y + yc);
		glVertex2d(-x + xc, -y + yc);
		glEnd();
	}
}

void display(){
	x:
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(trans, 0.0f, 0.0f);
	parametric(10, 10+10+40, 10+10);
	parametric(50+10, 10+10+40, 10+10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-trans, 0.0f, 0.0f);
	parametric(450, 400-40, 10+10);
	parametric(450+50, 400-40, 10+10);
	//poly();
	glFlush();
	
	glPopMatrix();
	if (trans >= 0.8)
		
	//std::cout << trans << "\n";
	trans += 0.005f;
	//retrans += -0.005f;

}
void init(){
	glClearColor(0.0, 1.0, 0.0, 0);
	glColor3f(0.0, 1.0, 1.0);
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CAR");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}
*/
#include<iostream>
#include<GL/glut.h>
#include<math.h>
float trans = 0.0f;
float val = 0.005f;
//int xc, yc, r;
int millis = 30;
void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(millis, timer, 0);
}

void parametric(int xc, int yc, int r){
	float x, y;
	for (int i = 0; i < 90; i++){
		x = r*cos(3.142*i / 180);
		y = r*sin(3.142*i / 180);
		glBegin(GL_POINTS);
		glVertex2d(x + xc, y + yc);
		glVertex2d(x + xc, -y + yc);
		glVertex2d(-x + xc, y + yc);
		glVertex2d(-x + xc, -y + yc);
		glEnd();
	}
}
void poly1(){
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, 20);
	glVertex2i(60, 20);
	glVertex2i(30, 40);
	glEnd();

}
void poly2(){
	glBegin(GL_LINE_LOOP);
	glVertex2i(440, 410);
	glVertex2i(500, 410);
	glVertex2i(470, 430);
	glEnd();

}
int re = 0;
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
		
		glPushMatrix();
		glRotatef(re, 0.0f, 1.0f, 0.0f);
		glTranslatef(trans, trans, 0.0f);
		parametric(10, 10, 10);
		parametric(50, 10, 10);
		poly1();
		
		glFlush();
		glPopMatrix();
		glPushMatrix();
		glRotatef(re, 0.0f, 1.0f, 0.0f);
		glTranslatef(-trans, -trans, 0.0);

		parametric(450, 400, 10);
		parametric(490, 400, 10);
		poly2();
		glFlush();
		//glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		trans += val;
		re += 3;
	
}
void init(){
	glClearColor(0.0, 1.0, 1.0, 0);
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(0, 500, 0, 500);
}
void mykey(unsigned char key, int x, int y){
	if (key == 'b'){ val = 0.0f; re = 0; }
	if (key == 's'){ val = 0.005f; }
	if (key == 'e'){ exit(0); }

}
int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CAR");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(mykey);
	glutMainLoop();
	return 0;
}
