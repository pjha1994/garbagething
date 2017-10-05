#include<GL/glut.h>
#include<GL/glu.h>

void init()
{
glClearColor(255.0,0.0,0.0,0.0);
glLoadIdentity();
glOrtho(0,500,0,500,-1,1);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	//glutDisplayFunc(display);
	glutMainLoop();
}
