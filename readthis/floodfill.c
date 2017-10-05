#include<GL/glut.h>
typedef struct {
      GLfloat r,g,b;
}Color;
void init(){
    glClearColor(0.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,500,0,500,-1,1);
    glMatrixMode(GL_MODELVIEW);
}
void draw_square(){
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
void display(){
     glClear(GL_COLOR_BUFFER_BIT);
     draw_square();
     Color old,fill={0.0f,0.0f,1.0f};
     glReadPixels(40,40,1.0f,1.0f,GL_RGB,GL_FLOAT,&old);
     floodfill(40,40,fill,old);
     glFlush();
}
void main(int argc,char** argv){
       glutInit(&argc,argv);
       glutInitWindowPosition(0,0);
       glutInitWindowSize(500,500);
       glutCreateWindow("hello");
       init();
       glutDisplayFunc(display);
       glutMainLoop();
}
