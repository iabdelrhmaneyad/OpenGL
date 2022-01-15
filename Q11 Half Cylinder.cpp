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
	glColor3f(0.0f, 1.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);


	glPushMatrix();
	glRotatef(-30, 0.0f, 1.0f, 0.0f);
	glRotatef(120, 1.0f, 0.0f, 0.0f);

	glColor3f(0.8f, 0.8f, 0.8f);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0, 30);
	for (angle = 0.0f; angle <= (GL_PI); angle += GL_PI / 50)
	{
		x = 30 * sin(angle);
		y = 30 * cos(angle);

		glVertex3f(x, y, 30);
	}

	glEnd();	


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0, -30);
	for (angle = 0.0f; angle <= (GL_PI); angle += GL_PI / 50)
	{
		x = 30 * sin(angle);
		y = 30 * cos(angle);

		glVertex3f(x, y, -30);
	}

	glEnd();


	glColor3f(0.6f, 0.6f, 0.6f);

	glBegin(GL_QUAD_STRIP);
	glVertex3f(0, 0, -30);
	for (angle = 0.0f; angle <= (GL_PI); angle += GL_PI / 50)
	{
		x = 30 * sin(angle);
		y = 30 * cos(angle);

		glVertex3f(x, y, 30);
		glVertex3f(x, y, -30);
	}

	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(30 * sin(0.0f), 30 * cos(0.0f), 30);
	glVertex3f(30 * sin(0.0f), 30 * cos(0.0f), -30);
	glVertex3f(30 * sin(GL_PI), 30 * cos(GL_PI), -30);
	glVertex3f(30 * sin(GL_PI), 30 * cos(GL_PI), 30);
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
