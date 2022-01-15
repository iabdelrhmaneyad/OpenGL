// Points.c
// OpenGL SuperBible
// Demonstrates OpenGL Primative GL_POINTS
// Program by Richard S. Wright Jr.

#include <gl/glut.h>
#include <math.h>

#define GL_PI 3.1415f

void RenderScene(void)
{
	GLfloat x, y, angle;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	glLineWidth(5);

	glPushMatrix();

	glBegin(GL_LINE_STRIP);


	for (angle = GL_PI; angle <= (2.0f*GL_PI); angle += GL_PI / 50)
	{
		x = 20.0f*cos(angle);
		y = 20.0f*sin(angle);

		// Specify the point and move the Z value up a little	
		glVertex2f(x, y);

	}

	// Done drawing points
	glEnd();

	glBegin(GL_LINE_STRIP);


	for (angle = GL_PI; angle <= (2.0f*GL_PI); angle += GL_PI / 50)
	{
		x = 40.0f*cos(angle);
		y = 40.0f*sin(angle);

		// Specify the point and move the Z value up a little	
		glVertex2f(x, y);

	}
	// Done drawing points
	glEnd();


	glBegin(GL_LINES);
	//     Left Line.
	glVertex2f(-20, 0);
	glVertex2f(-40, 0);
	glEnd();

	glBegin(GL_LINE_STRIP);

	glVertex2f(20, 0);
	glVertex2f(20, 60);

	glVertex2f(0, 60);
	glVertex2f(0, 80);

	glVertex2f(0, 80);
	glVertex2f(60, 80);

	glVertex2f(60, 60);
	glVertex2f(40, 60);

	glVertex2f(40, 0);

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
