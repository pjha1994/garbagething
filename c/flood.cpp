#include<GL/glut.h>
#include<math.h>
void init(){
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500,-1,1);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(GLfloat x, GLfloat y, GLfloat color[]){
	glColor3fv(color);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
        glFlush();

}
void paramCircle(){
	GLfloat xc =250,x,y;
	GLfloat yc = 250,radius=100;
	GLfloat color[3] = { 1.0, 1.0, 0.0 };
	for (GLfloat i = 0; i < 360; i++){
		x = xc + radius*cos((22.0 / 7.0)*i / 180.0);
		y = yc + radius*sin((22.0 / 7.0)*i / 180.0);
                glPointSize(10);
		setPixel(x, y, color);
	}
}
void floodfill(GLfloat x, GLfloat y, GLfloat fill[], GLfloat old[]){
	GLfloat current[3];
	glReadPixels(x, y, 10.0, 10.0, GL_RGB, GL_FLOAT, current);
	if (current[0] == old[0] && current[1] == old[1] && current[2] == old[2]){
                glPointSize(10);
		setPixel(x, y, fill);
                floodfill(x - 10, y, fill, old);
		floodfill(x + 10, y, fill, old);
                floodfill(x, y+10, fill, old);
		floodfill(x, y-10, fill, old);
	}
}
void display(){
        glClear(GL_COLOR_BUFFER_BIT);
	paramCircle();
	GLfloat old[3];
	GLfloat fill[3] = { 0.0, 0.0, 1.0 };
	glReadPixels(250, 250, 10.0, 10.0, GL_RGB, GL_FLOAT, old);
	floodfill(250, 250, fill, old);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("hola");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
