// Points.c
// OpenGL SuperBible
// Demonstrates OpenGL Primative GL_POINTS
// Program by Richard S. Wright Jr.

#include <gl/glut.h>
#include <math.h>

void RenderScene(void)
{
	GLfloat x, y, z, angle;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();

	glColor3f(0, 0, 0);

	glBegin(GL_TRIANGLES);

	//     Right Triangle
	glVertex2f(0, 0);
	glVertex2f(80, -50);
	glVertex2f(80, 50);

	//     Left Triangle
	glVertex2f(0, 0);
	glVertex2f(-80, -50);
	glVertex2f(-80, 50);

	//     Up Triangle
	glVertex2f(0, 0);
	glVertex2f(40, 50);
	glVertex2f(-40, 50);


	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(40, 50);
	glVertex2f(-40, 50);
	glVertex2f(-40, 90);
	glVertex2f(40, 90);
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
