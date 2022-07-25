#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void object(float x, float y, float z, float sx, float sy, float sz) {
  glRotatef(50, 0, 1, 0);
  glRotatef(10, -1, 0, 0);
  glRotatef(12, 0, 0, -1);
  glTranslatef(x, y, z);
  glScalef(sx, sy, sz);
  glutSolidCube(1);
  glLoadIdentity();
}

void display() {
  glLoadIdentity();
  glViewport(0, 0, 500, 500);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
  // // three walls
  // object(0, 0, 0.5, 1, 1, 0.05);
  // object(0, -0.5, 0, 1, 0.05, 1);
  // object(-0.5, 0, 0, 0.05, 1, 1);
	
  // four legs of table
  object(0, -0.3, 0, 0.02, 0.2, 0.02);
  object(0, -0.3, -0.4, 0.02, 0.2, 0.02);
  object(0.4, -0.3, 0, 0.02, 0.2, 0.02);
  object(0.4, -0.3, -0.4, 0.02, 0.2, 0.02);

  // table top
  object(0.2, -0.2, -0.2, 0.6, 0.02, 0.6);
  glRotatef(50, 0, 1, 0);
  glRotatef(10, -1, 0, 0);
  glRotatef(12, 0, 0, -1);
  glTranslatef(0.3, -0.1, -0.3);
  glutSolidTeapot(0.1);
  glFlush();
}

int main(int argc, char **argv) {
  float ambient[] = {1, 1, 1, 1};
  float light_pos[] = {27, 80, 2, 3};
  glutInit(&argc, argv);
  glutCreateWindow("Teapot on table");
  glutDisplayFunc(display);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  glutMainLoop();
  return 0;
}
