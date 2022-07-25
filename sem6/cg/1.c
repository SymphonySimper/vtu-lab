#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int xstart, xend, ystart, yend;
void sp(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void line() {
  double dx = fabs(xend - xstart), dy = fabs(yend - ystart);
  double p = 2 * dy - dx, ty = 2 * dy, txy = 2 * (dy - dx);
  int x, y;

  if (xstart > xend) {
    x = xend;
    y = yend;
    xend = xstart;
  } else {
    x = xstart;
    y = ystart;
  }

  sp(x, y);
  while (x < xend) {
    x++;
    if (p < 0) {
      p += ty;
    } else {
      y++;
      p += txy;
    }
    sp(x, y);
  }
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glLoadIdentity();
  gluOrtho2D(0, 100, 0, 100);
}

void display() {
  line();
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  printf("Enter four values: ");
  scanf("%d%d%d%d", &xstart, &xend, &ystart, &yend);
  glutCreateWindow("Line");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
}
