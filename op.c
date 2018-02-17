#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>

void init() {
  glClearColor(0,0,0,0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,500,0,400);
}


void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,1,1);
  glBegin(GL_LINE_STRIP);
//  glVertex2i(100,50);
//  glVertex2i(150,100);
///  glVertex2i(200,70);
//  glVertex2i(300,100);
//  glVertex2i(300,50);
//  glVertex2i(150,50);
 glVertex2i(50,50);
  glVertex2i(50,300);
  glVertex2i(50,50);
  glVertex2i(300,50);


  glEnd();
  glFlush();


}


void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(600,600);
	glutCreateWindow("Spin a colorcube");
	init();
	glutDisplayFunc(display);

	glutMainLoop();
}
