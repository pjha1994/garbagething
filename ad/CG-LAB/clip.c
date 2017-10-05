#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
struct Point
{
    float x,y;
}w[4],oVer[4];
int Nout;   

void drawPoly(Point p[],int n)
{
    glBegin(GL_POLYGON);           
    for(int i=0;i<n;i++)
    glVertex2f(p[i].x,p[i].y);   
    glEnd();
}

bool insideVer(Point p)
{   
        if((p.x>=w[0].x)&&(p.x<=w[2].x))       
            if((p.y>=w[0].y)&&(p.y<=w[2].y))
                return true;               
        return false;       
}

void addVer(Point p)
{       
    oVer[Nout]=p;        
    Nout++;
}



void clipAndDraw(Point inVer[],int Nin)
{   Nout=0;int f=0;
    Point s,p,interSec;   
    for(int i=0;i<4;i++)
    { 
	s=inVer[i];
        if(s.x<20)
        {
		s.x=20;
        } 
        if(s.y<10)
        {
		s.y=10;
        }
        if(s.x>80)
        {
		s.x=80;
        }
        if(s.y>80)
        {
		s.y=80;
        }
     	addVer(s);
    }   
    drawPoly(oVer,4);
}

void init()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glMatrixMode(GL_PROJECTION);       
    glLoadIdentity();   
    glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
    glClear(GL_COLOR_BUFFER_BIT); 
    Nout=0;  
    w[0].x =20,w[0].y=10;
    w[1].x =20,w[1].y=80;
    w[2].x =80,w[2].y=80;
    w[3].x =80,w[3].y=10;
}
void display(void)
{   
    Point inVer[4];
    init();
    // As Window for Clipping
    glColor3f(1.0f,0.0f,0.0f);       
    drawPoly(w,4);
    // As Rect
    glColor3f(0.0f,1.0f,0.0f);
    inVer[0].x =10,inVer[0].y=5;
    inVer[1].x =10,inVer[1].y=90;
    inVer[2].x =90,inVer[2].y=90;
    inVer[3].x =90,inVer[3].y=5;
    drawPoly(inVer,4);
    // As Rect 
    glColor3f(0.0f,0.0f,1.0f);
    clipAndDraw(inVer,4);       
    // Print
    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Polygon Clipping!");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


