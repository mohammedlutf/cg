#include<GL/glut.h>
GLfloat vertices[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-
1.0,1.0},
{1.0,-1.0,1.0},{1.0,1.0,1.0},{-
1.0,1.0,1.0}}; //VERTICES OF THE CUBE
GLfloat colors[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-
1.0,1.0},
{1.0,-1.0,1.0},{1.0,1.0,1.0},{-
1.0,1.0,1.0}}; //COLOR ASSOCIATED WITH EACH VERTEX
GLubyte
cubeIndices[]={0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,5,4,5,6,7,0,1,5,4
};
static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=2;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
	glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,cubeIndices);
	glutSwapBuffers();
	glFlush();
}



void spincube()
{
theta[axis]+=2.0;
if(theta[axis]>360.0)
{
theta[axis]-=360.0;
}
display();
}


void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)axis=0;
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)axis=1;
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)axis=2;
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}






void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(600,600);
	glutCreateWindow("Spin a colorcube");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(spincube);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,vertices);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3,GL_FLOAT,0,colors);
	glutMainLoop();
}
