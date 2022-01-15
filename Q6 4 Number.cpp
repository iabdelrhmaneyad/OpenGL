// Points.c
// OpenGL SuperBible
// Demonstrates OpenGL Primative GL_POINTS
// Program by Richard S. Wright Jr.

#include <gl/glut.h>
#include <math.h>


void RenderScene(void)
{
	GLfloat x, y, angle;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	glLineWidth(10);

	glPushMatrix();


	glBegin(GL_LINES);

	glVertex2f(0, 0);
	glVertex2f(0, 60);

	glVertex2f(0, 30);
	glVertex2f(-30, 30);

	glVertex2f(-30, 30);
	glVertex2f(-30, 60);

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
