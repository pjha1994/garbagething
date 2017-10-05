#include<GL/glut.h>
typedef struct{
       GLfloat r,g,b;
}Color;
void init(){
     glClearColor(1.0,1.0,1.0,1.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(0,500,0,500,-1,1);
     glMatrixMode(GL_MODELVIEW);
}
void draw_square(){
     int x=100,y=100;
     glLineWidth(10);
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_LINE_STRIP);
     glVertex2i(x,y);
     glVertex2i(x+80,y);
     glVertex2i(x+80,y);
     glVertex2i(x+80,y+80);
     glVertex2i(x+80,y+80);
     glVertex2i(x,y+80);
     glVertex2i(x,y+80);
     glVertex2i(x,y);
     glEnd();
     glFlush();
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
     glReadPixels(x,y,10.0,10.0,GL_RGB,GL_FLOAT,&current);
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
     Color old,fill={1.0f,0.0f,0.0f};
     glReadPixels(150,150,10.0,10.0,GL_RGB,GL_FLOAT,&old);
     //floodfill(150,150,fill,old);
}
void main(int argc,char** argv){
     glutInit(&argc,argv);
     glutInitWindowSize(500,500);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowPosition(0,0);
     glutCreateWindow("hola");
     init();
     glutDisplayFunc(display);
     glutMainLoop();
}
