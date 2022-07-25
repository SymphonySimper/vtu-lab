#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float angle;

void display() {
  glLoadIdentity();
  glRotatef(angle, 0, 0, 1);

  // draw triangle
  glBegin(GL_TRIANGLES);
  glColor3f(1, 0, 0);
  glVertex2f(-0.5, -0.5);
  glVertex2f(0.5, -0.5);
  glVertex2f(0, 0.5);
  glEnd();

  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  // glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // glOrtho(-2, 2, -2, 2, -10, 10);
  // glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  printf("Enter the angle: ");
  scanf("%f", &angle);
  glutCreateWindow("Triangle");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMainLoop();
}
