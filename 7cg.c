#include <stdlib.h>
#include <stdio.h>
#include<GL/glut.h>

typedef float point[3];
point v[]={{0.0, 0.0, 1.0},{0.0, 0.9, -0.3}, {-0.8, -0.5, -0.3}, {0.8, -0.5, -0.3}};
int n;



void triangle( point a, point b, point c)
{
glBegin(GL_POLYGON);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}


void divide_triangle(point a, point b, point c, int n)
{
// triangle subdivision using vertex numbers right hand rule applied to create outward pointing faces
point v1, v2, v3;
int j;
if(n>0)
{
    for(j=0; j<3; j++) {
        v1[j]=(a[j]+b[j])/2;
        v2[j]=(a[j]+c[j])/2;
        v3[j]=(b[j]+c[j])/2;
    }
    divide_triangle(a, v1, v2, n-1);
    divide_triangle(c, v2, v3, n-1);
    divide_triangle(b, v3, v1, n-1);
}
else triangle(a,b,c); // draw triangle at end of recursion
}


void tetrahedron( int n)
{
/* Apply triangle subdivision to faces of tetrahedron */
glColor3f(1.0,0.0,0.0);
divide_triangle(v[0], v[1], v[2], n);

glColor3f(0.0,0.0,0.0);
divide_triangle(v[3], v[2], v[1], n);

glColor3f(0.0,0.0,1.0);
divide_triangle(v[0], v[3], v[1], n);

glColor3f(0.0,1.0,0.0);
divide_triangle(v[0], v[2], v[3], n);
}


void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
tetrahedron(n);
glFlush();
}


void myReshape(int w, int h)
{
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w <= h)
      glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
  else
      glOrtho(-2.0,2.0,-2.0, 2.0,-10.0,10.0);
glMatrixMode(GL_MODELVIEW);
display();
}



int main(int argc, char **argv)
{
printf(" No. of Divisions ? "); scanf("%d",&n);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(500, 500);
glutCreateWindow("3D Gasket");
glClearColor (1.0, 1.0, 1.0, 1.0);
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 1;
}
