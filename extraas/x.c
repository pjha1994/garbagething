#include <GL/glut.h>

void display()
{
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    glOrtho( 0, w, 0, h, -1, 1);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    // important
    glTranslatef( 0.5, 0.5, 0 );

    float offset = 40;
    glColor3ub( 255, 0, 0 );
    glBegin(GL_LINE_LOOP);
    glVertex2f( 0+offset, 0+offset );
    glVertex2f( 0+offset, h-offset );
    glVertex2f( w-offset, h-offset );
    glVertex2f( w-offset, 0+offset );
    glEnd();

    glutSwapBuffers();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 320,240 );
    glutCreateWindow( "Rect" );
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
