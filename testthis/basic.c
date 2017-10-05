//flood fill trial pastebin.com/vzCTdmUn

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define offset 250
typedef struct{
      GLfloat r,g,b;
}Color;
void setPixel1(int x, int y)
{
	glColor3f(255.0, 255.0, 255.0);
	glBegin(GL_POINTS);
	glVertex2i(offset + x, offset + y);
	glEnd();
	glFlush();
}
void draw_square1(){
     glColor3f(1.0,0.0,0.0);
     glLineWidth(10);
     glBegin(GL_LINE_STRIP);
     glVertex2i(20,20);
     glVertex2i(420,20);
     glVertex2i(420,20);
     glVertex2i(420,420);
     glVertex2i(420,420);
     glVertex2i(20,420);
     glVertex2i(20,420);
     glVertex2i(20,20);     
     glEnd();
}
void setaxes()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glEnd();
	glFlush();
}
void draw_circle(){
     Color col={0.0,1.0,0.0};
     int x,y, xc=200,yc=200,radius=100,i;
     for(i=0;i<360;i++){
       x=xc+radius*cos((22.0/7.0)*i/180.0);
       y=yc+radius*sin((22.0/7.0)*i/180.0);
       setPixel(x,y,col);
     }

}
void setPixel(int x,int y,Color color){
     glColor3f(color.r,color.g,color.b);
     glPointSize(10);
     glBegin(GL_POINTS);
     glVertex2i(x,y);
     glEnd();
     glFlush();
}
void floodfill(int x,int y,Color fill,Color old){
     Color current;
     glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,&current);
     if(current.r==old.r&&current.g==old.g&&current.b==old.b){
       setPixel(x,y,fill);
       floodfill(x+10,y,fill,old);
       floodfill(x-10,y,fill,old);
       floodfill(x,y+10,fill,old);
       floodfill(x,y-10,fill,old);
     } 
}
void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
void glCircle( float x, float y, float r, bool filled = true, unsigned int subdivs = 20 ) {
    if( filled ) {
        glBegin( GL_TRIANGLE_FAN );
        glVertex2f( x, y );
    } else {
        glBegin( GL_LINE_STRIP );
    }

    for( unsigned int i = 0; i <= subdivs; ++i ) {
        float angle = i * ((2.0f * 3.14159f) / subdivs);
        glVertex2f( x + r * cos(angle), y + r * sin(angle) );
    }

    glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//draw_square1();
        //draw_circle();
        //Color old,fill={0.0f,0.0f,1.0f};
        //glReadPixels(200,200,1.0f,1.0f,GL_RGB,GL_FLOAT,&old);
        //floodfill(200,200,fill,old);
	//floodfill()
        glCircle(23,34);
        glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}




