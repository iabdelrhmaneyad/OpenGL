// Points.c
// OpenGL SuperBible
// Demonstrates OpenGL Primative GL_POINTS
// Program by Richard S. Wright Jr.

#include <gl/glut.h>
#include <math.h>

int width, height;

void RenderScene(void)
{
	GLfloat x, y, z, angle;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();
	glColor3f(0, 0, 0);

	glViewport(0, 0, width, height / 2);

	glBegin(GL_QUADS);
	glVertex2f(-50, -50);
	glVertex2f(50, -50);
	glVertex2f(40, 40);
	glVertex2f(-40, 40);
	glEnd();


	glViewport(0, height / 2, width / 2, height / 2);

	glBegin(GL_TRIANGLES);
	glVertex2f(-50, -20);
	glVertex2f(50, -20);
	glVertex2f(0, 80);

	glEnd();



	glViewport(width / 2, height / 2, width / 2, height / 2);

	glBegin(GL_POLYGON);
	glVertex2f(-50, -20);
	glVertex2f(50, -20);
	glVertex2f(50, 20);

	glVertex2f(0, 40);

	glVertex2f(-50, 20);
	glEnd();





	glPopMatrix();

	glutSwapBuffers();
}
void ChangeSize(int w, int h)
{
	width = w;
	height = h;
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Points Example");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);

	glutMainLoop();

	return 0;
}
