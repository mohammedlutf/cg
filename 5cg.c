#include <GL/glut.h>
#include<stdbool.h>

double xmin=50,ymin=50, xmax=100,ymax=100;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;

int RIGHT = 8;
int LEFT = 2;
int TOP = 4;
int BOTTOM = 1;

int ComputeOutCode (double x, double y)
{
     int code = 0;
     if (y > ymax) //above the clip window
        code |= TOP;
     else if (y < ymin) //below the clip window
        code |= BOTTOM;
     if (x > xmax) //to the right of clip window
        code |= RIGHT;
     else if (x < xmin) //to the left of clip window
        code |= LEFT;
     return code;
}


void LineClipAndDraw (double x0, double y0,double x1, double y1)
{

int outcode0, outcode1, outcodeOut;
bool accept = false, done = false;

outcode0 = ComputeOutCode (x0, y0);
outcode1 = ComputeOutCode (x1, y1);


do
{
	if (!(outcode0 | outcode1)) //completely inside
	{
		accept = true;
		done = true;
	}
	else if (outcode0 & outcode1) //logical and is not 0. Trivially reject and exit
		done = true;
	else
	{
			double x, y;
			outcodeOut = outcode0 ? outcode0: outcode1; // choose the outside end point  != 0

			// we know that one endpoint is outside but we don't know in which side
			if (outcodeOut & TOP)
			{
				x = x0 + (x1 - x0) * (ymax - y0)/(y1 - y0);
				y = ymax;
			}
			else if (outcodeOut & BOTTOM) //point is below the clip rectangle
			{
				x = x0 + (x1 - x0) * (ymin - y0)/(y1 - y0);
				y = ymin;
			}
			else if (outcodeOut & RIGHT) //point is to the right of clip rectangle
			{
				y = y0 + (y1 - y0) * (xmax - x0)/(x1 - x0);
				x = xmax;
			}
			else
			{
				y = y0 + (y1 - y0) * (xmin - x0)/(x1 - x0);
				x = xmin;
			}


			if(outcodeOut == outcode0)
			{
				x0 = x;
				y0 = y;
				outcode0 = ComputeOutCode(x0, y0);
			}
			else
			{
				x1 = x;
				y1 = y;
				outcode1 = ComputeOutCode(x1, y1);
			}
		}

} while (!done);


if (accept)
{ // Window to viewport mappings
double sx=(xvmax-xvmin)/(xmax-xmin); // Scale parameters
double sy=(yvmax-yvmin)/(ymax-ymin);
double vx0=xvmin+(x0-xmin)*sx;
double vy0=yvmin+(y0-ymin)*sy;
double vx1=xvmin+(x1-xmin)*sx;
double vy1=yvmin+(y1-ymin)*sy;
//draw a red colored viewport
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xvmin, yvmin);
glVertex2f(xvmax, yvmin);
glVertex2f(xvmax, yvmax);
glVertex2f(xvmin, yvmax);
glEnd();
glColor3f(0.0,0.0,1.0); // draw blue colored clipped line
glBegin(GL_LINES);
glVertex2d (vx0, vy0);
glVertex2d (vx1, vy1);
glEnd();
}
}







void display()
{
  double x0=60,y0=20,x1=80,y1=120;
glClear(GL_COLOR_BUFFER_BIT);
//draw the line with red color
glColor3f(1.0,0.0,0.0);
//bres(120,20,340,250);
glBegin(GL_LINES);
glVertex2d (x0, y0);
glVertex2d (x1, y1);
glEnd();
//draw a blue colored window
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xmin, ymin);
glVertex2f(xmax, ymin);
glVertex2f(xmax, ymax);
glVertex2f(xmin, ymax);
glEnd();
LineClipAndDraw(x0,y0,x1,y1);
glFlush();
}




void init()
{
glClearColor(1.0,1.0,1.0,1.0);
gluOrtho2D(0.0,499.0,0.0,499.0);
}
void main(int argc, char** argv)
{

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Cohen Suderland Line Clipping Algorithm");
glutDisplayFunc(display);
init();
glutMainLoop();
}
