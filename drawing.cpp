#define _LIB
#define FREEGLUT_LIB_PRAGMAS 0

#include "drawing.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <cstdio>
#include "Dependencies\sdl\include\SDL.h"

void drawing()
{
	glPushMatrix();
	glTranslated(0, 0, -2);
	glColor3f(0.5, 0.5, 2);
	glutSolidSphere(0.25, 16, 16);
	glPopMatrix();

}