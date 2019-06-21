#include "callbacks.h"
#include "drawing.h"

#define _LIB
#define FREEGLUT_LIB_PRAGMAS 0

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <cstdio>
#include "Dependencies\sdl\include\SDL.h"
#include <iostream>

void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 1, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawing();
	glutSwapBuffers();
}

void timer(int time)
{

	glutTimerFunc(1000 / 60, timer, 0);
}

void camera(int x, int y)
{
	glutSetCursor(GLUT_CURSOR_NONE);

	int middleX= 400, middleY =300;

	int deltaX = x - middleX;
	int deltaY = y - middleY;

	glutWarpPointer(middleX, middleY);

	glMatrixMode(GL_PROJECTION);
	glRotated(-deltaX * 0.25, 0, 1, 0);
	glRotated(-deltaY * 0.25, 1, 0, 0);
	glMatrixMode(GL_MODELVIEW);

	glutPostRedisplay();

}
