// Points.c
// OpenGL SuperBible
// Demonstrates OpenGL Primative GL_POINTS
// Program by Richard S. Wright Jr.

#include <gl/glut.h>
#include <math.h>

#define GL_PI 3.1415f


void RenderScene(void)
{
	GLfloat x, y, z, angle;
	GLfloat r;  // radius
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);


	glPushMatrix();
	glRotatef(-60, 1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 0.8f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0, 0, 20);

	for (angle = 0.0f; angle <= (2.0f*GL_PI); angle += GL_PI / 2)
	{
		x = 20 * sin(angle);
		y = 20 * cos(angle);

		// Specify the point and move the Z value up a little	
		glVertex3f(x, y, 0);
	}

	// Done drawing points
	glEnd();
	glColor3f(0.0f, 0.6f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0, 0, -20);

	for (angle = 0.0f; angle <= (2.0f*GL_PI); angle += GL_PI / 2)
	{
		x = 20 * sin(angle);
		y = 20 * cos(angle);

		// Specify the point and move the Z value up a little	
		glVertex3f(x, y, 0);
	}

	// Done drawing points
	glEnd();

	glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Points Example");
	glutDisplayFunc(RenderScene);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);

	glutMainLoop();

	return 0;
}
