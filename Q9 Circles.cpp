// Points.c
// OpenGL SuperBible
// Demonstrates OpenGL Primative GL_POINTS
// Program by Richard S. Wright Jr.

#include <gl/glut.h>
#include <math.h>

#define GL_PI 3.1415f



void draw(void)
{
	GLfloat x, y, z, angle;
	GLfloat r;


	z = -20.0f;
	r = 5;
	for (int i = 0; i < 6; i++){
		glBegin(GL_LINE_STRIP);

		for (angle = 0.0f; angle <= (2.0f*GL_PI); angle += GL_PI / 50)
		{
			x = r*sin(angle);
			y = r*cos(angle);

			// Specify the point and move the Z value up a little	
			glVertex3f(x, y, z);
		}

		z += 5;
		r += 5;
		glEnd();
	}
	// Done drawing points

}

void RenderScene(void)
{
	GLfloat x, y, z, angle;
	GLfloat r;  // radius
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);


	glPushMatrix();
	glRotatef(30, 1.0f, 0.0f, 0.0f);

	glPushMatrix();
	glTranslatef(0, -50, 0);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	draw();
	glPopMatrix();


	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	draw();

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
