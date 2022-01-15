// Points.c
// OpenGL SuperBible
// Demonstrates OpenGL Primative GL_POINTS
// Program by Richard S. Wright Jr.

#include <gl/glut.h>
#include <math.h>

#define GL_PI 3.1415f


GLfloat a[] = { -20, -20, -20 },
b[] = { 20, -20, -20 },
c[] = { 20, 20, -20 },
d[] = { -20, 20, -20 },
e[] = { -20, -20, 20 },
f[] = { 20, -20, 20 },
g[] = { 20, 20, 20 },
h[] = { -20, 20, 20 };


void draw(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);

	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3fv(e);
	glVertex3fv(f);
	glVertex3fv(g);
	glVertex3fv(h);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(f);
	glVertex3fv(e);


	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(g);
	glVertex3fv(f);

	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex3fv(a);
	glVertex3fv(d);
	glVertex3fv(h);
	glVertex3fv(e);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3fv(c);
	glVertex3fv(d);
	glVertex3fv(h);
	glVertex3fv(g);


	glEnd();

}



void RenderScene(void)
{
	GLfloat x, y, z, angle;
	GLfloat r;  // radius
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);

	GLfloat translateValue = 35;
	glPushMatrix();

	glTranslatef(0, -50, 0);

	glRotatef(30, 1.0f, 1.0f, 0.0f);

	for (int i = 0; i <= 15; i++){
		//translateValue = translateValue *0.75;
		glTranslatef(0, translateValue, 0);
		glScalef(0.75, 0.75, 0.75);
		draw();
	}


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
	glOrtho(-150.0f, 150.0f, -150.0f, 150.0f, -150.0f, 150.0f);

	glutMainLoop();

	return 0;
}
