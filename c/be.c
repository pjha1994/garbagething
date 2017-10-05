//Flood-Fill Algorithm

#include<GL/glut.h>

#include<stdio.h>

#include<math.h>




struct pt
{
int x;
int y;
}p[50];

int nopts;


int calcfact(int n)
{
	int fact=1,i=0;
	for(i=1;i<=n;i++)
		fact*=i;
	return fact;
}

float calcBC(int n, int i)
{
	return calcfact(n)/(float)(calcfact(n-i)*calcfact(i));
}

void bez()
{	glColor3f(1.0,0.0,0.0);
	float u=0,x,y;
	int i=0;
	//glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_STRIP);
	for(u=0;u<=1.0;u+=0.0005)
	{x=0;y=0;
	for(i=0;i<nopts;i++)
	{x+=calcBC((nopts-1),i)*pow((1-u),(nopts-1)-i)*pow(u,i)*p[i].x;
	y+=calcBC((nopts-1),i)*pow((1-u),(nopts-1)-i)*pow(u,i)*p[i].y;
	}
        //glColor3f(1.0,0.0,.0);
	glVertex2i(x,y);
        glVertex2i(x-50,y-50);
        glEnd();
	}
	glFlush();
}

void setPixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
        glFlush();
}




void init()
{

	glClearColor(0.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	

	glLoadIdentity();

	glOrtho(-250, 250, -250, 250,-1,1);

}

void myMouse(int button,int state,int x,int y)
{	glColor3f(1.0,0.0,0.0);
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	//circle(300,300,50);
	//bez();
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	exit(0);
}



void display()
{

	

	//glFlush();
	glPointSize(3);
	glColor3f(1.0,0.0,0.0);
	bez();
glFlush();



}


void main(int argc, char** argv)
{	int q;
	printf("Enter no of Control Points :");
	scanf("%d",&nopts);
	
	for(q=0;q<(int)nopts;q++)
	{
		printf("Enter Control Point P%d(x1, y1):",q);
		scanf("%d %d", &p[q].x, &p[q].y);
	}
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(0, 0);

	glutCreateWindow(" ");

	init();
	//glutMouseFunc(myMouse);
	glutDisplayFunc(display);

	glutMainLoop();

	//return 0;

}

