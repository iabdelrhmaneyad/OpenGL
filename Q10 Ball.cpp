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
	glColor3f(0.0f, 0.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);


	glPushMatrix();
	glRotatef(60, 1.0f, 0.0f, 0.0f);

	GLfloat sin_theta, cos_theta;

	glBegin(GL_LINE_STRIP);
	r = 50.0f;
	angle = 0.0f;
	for (z = -r; z <r; z += 0.1f) {


		sin_theta = z / r;
		cos_theta = sqrt(1 - sin_theta*sin_theta);

		x = r*sin(angle)*cos_theta;
		y = r*cos(angle)*cos_theta;
		angle += 0.1f;
		glVertex3f(x, y, z);
	}
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
