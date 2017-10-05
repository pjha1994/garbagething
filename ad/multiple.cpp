#include<GL/glut.h>
#include<iostream>
int time = 33.7;
GLfloat angle = 0.0, angle1 = -50.0, angle2 = 10.0;
void init(GLfloat x=0.0,GLfloat y=0.3,GLfloat z=0.3){
	glClearColor(x, y, z, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
}
void circle(){
	GLfloat x , y;
	glColor3f(1.0, 1.0, 0.0);
	int h = 45, k = 45;
	for (GLfloat i = 0; i < 360; i++){
		x = h+100*cos(3.14*i / 180.0);
		y = k+100*sin(3.14*i / 180.0);
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
	}
	glFlush();
}
void square(GLfloat x,GLfloat y,GLfloat z){
	glColor3f(x, y, z);
	glLineWidth(20);
	glBegin(GL_LINE_LOOP);
	glVertex2i(100, 100);
	glVertex2i(200, 100);
	glVertex2i(200, 200);
	glVertex2i(100, 200);
	glEnd();
	glFlush();
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);
	square(1.0, 0.0, 0.0);
	circle();
	glPopMatrix();
	angle += 5.0;
}
void display1(){
	//glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	display();
	glRotatef(angle1, 0.0, 0.0, 1.0);
	square(1.0,0.0,0.0);
	glPopMatrix();
	angle1 -= 0.34;
}
void display2(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	display();
	display1();
	glRotatef(angle2, 0.0, 0.0, 1.0);
	square(1.0,0.0,0.0);
	glPopMatrix();
	angle2 -= 5.0;
}
void keyboard(unsigned char c, int x, int y){
	exit(0);
}
void mouse(int a,int b, int x, int y){
	std::cout << a<<"  " << b<<"  " << x<<"  " << y << "\n";
}
void one(){
	glutInitWindowPosition(0, 0);
	glutCreateWindow("hola");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
}
void second(){
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hola1");
	init(0.0, 1.0, 0.0);
	glutDisplayFunc(display1);
	glutMouseFunc(mouse);
}
void third(){
	glutInitWindowPosition(200, 200);
	glutCreateWindow("hola2");
	init(0.0, 0.0, 1.0);
	glutDisplayFunc(display2);
	glutMouseFunc(mouse);
}
void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(time, timer, 0);
}
int main(int argc, char**argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutKeyboardFunc(keyboard);
	one();
	second();
	third();
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}