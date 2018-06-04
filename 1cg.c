
#include<GL/glut.h>

#define sign(x) ((x>0)?1:((x<0)?-1:0))

void setPixel(int x, int y) {
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}

void drawline(int x1, int y1, int x2, int y2)
{
int dx, dy, x, y, d, s1, s2, swap=0, temp,i;
dx = abs(x2 - x1);
dy = abs(y2 - y1);
s1 = sign(x2-x1);
s2 = sign(y2-y1);
x = x1;
y = y1;

if(dy > dx){temp = dx; dx = dy; dy = temp; swap = 1;}

d = 2 * dy - dx;


for(i = 1; i <= dx; i++)
{
      setPixel(x,y);
      while(d >= 0)
      {
              if(swap)
                  x = x + s1;
              else
              {
              y = y + s2;
              d = d - 2* dx;
              }
      }
      if(swap)
        y = y + s2;
      else
       x = x + s1;
      d = d + 2 * dy;
}

}


void draw(void)
{
glClear(GL_COLOR_BUFFER_BIT);
drawline(20,40,620,40);
drawline(620,40,620,440);
drawline(620,440,20,440);
drawline(20,440,20,40);
drawline(320,440,20,240);
drawline(20,240,320,40);
drawline(320,40,620,240);
drawline(620,240,320,440);
drawline(250,150,250,250);
drawline(300,150,300,250);
drawline(300,250,400,250);
drawline(400,250,400,150);
drawline(400,150,300,150);
glFlush();
}



int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(640, 480);
glutCreateWindow("Green Window");
glClearColor(0.0,0.0,0.0,0);
glutDisplayFunc(draw);
gluOrtho2D(0,640,0,480);
glutMainLoop();
return 0;
}
