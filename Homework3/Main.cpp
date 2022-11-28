#include<iostream>
#include<gl/glut.h>

using namespace std;

bool Rotate = false;
bool mode = false;
float Angle = 0.0;
float eye[] = { 0, 4, 6 };
float center[] = { 0, 0, 0 };
float fDistance = 0.2f;
int wHeight = 0;
int wWidth = 0;
void draw_part(int num);

void DrawTable();
void idle();
void key(unsigned char k, int x, int y);
void redraw();
void reshape(int width, int height);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	int windowHandle = glutCreateWindow("Homework 4");

	glutDisplayFunc(redraw);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}

void DrawTable()
{
	glPushMatrix();
	glTranslatef(0, 3.5, 0);
	glScalef(5, 1, 4);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 1.5, 1);
	glScalef(1, 3, 1);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 1.5, 1);
	glScalef(1, 3, 1);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 1.5, -1);
	glScalef(1, 3, 1);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 1.5, -1);
	glScalef(1, 3, 1);
	glutWireCube(1.0);
	glPopMatrix();
}

void idle()
{
	glutPostRedisplay();
}

void key(unsigned char k, int x, int y)
{
	switch (k){
	case 27:
	case 'q': {exit(0); break; }
	case 'a':
	{
		eye[0] += fDistance;
		center[0] += fDistance;
		break;
	}
	case 'd':
	{
		eye[0] -= fDistance;
		center[0] -= fDistance;
		break;
	}
	case 'w':
	{
		eye[1] -= fDistance;
		center[1] -= fDistance;
		break;
	}
	case 's':
	{
		eye[1] += fDistance;
		center[1] += fDistance;
		break;
	}
	case 'z':
	{
		eye[2] *= 0.95;
		break;
	}
	case 'c':
	{
		eye[2] *= 1.05;
		break;
	}
	case ' ':
	{
		Rotate = !Rotate;
		break;
	}
	case 'p': {
		mode = !mode;
		break;
	}
	default: break;
	}
}

void redraw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	GLfloat gray[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat light_pos[] = { 10, 10, 10, 1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gray);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, gray);
	glEnable(GL_LIGHT0);
	if (Rotate) Angle += 0.1f;

	
	//draw_part(0);
	draw_part(1);
	draw_part(2);
	draw_part(3);
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	if (height == 0) height = 1;
	wWidth = width;
	wHeight = height;
}


void draw_part(int num) {
	glPushMatrix();
	
	switch (num)
	{
	case 0:
		glViewport(0, 0, 400, 400);
		break;
	case 1:
		glViewport(0, 400, 400, 400);
		break;
	case 2:
		glViewport(400, 0, 400, 400);
		break;
	case 3:
		glViewport(400, 400, 400, 400);
		break;
	default:
		break;
	}
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if (mode) {
		switch (num)
		{
		case 0:
			glFrustum(-1, 0, -1, 0, 1, 1000);
			break;
		case 1:
			glFrustum(-1, 0, 0, 1, 1, 1000);
			break;
		case 2:
			glFrustum(0, 1, -1, 0, 1, 1000);
			break;
		case 3:
			glFrustum(0, 1, 0, 1, 1, 1000);
			break;
		default:
			break;
		}
	}
	else {
		glOrtho(-2, 2, -2, 2, -100, 100);
		switch (num)
		{
		case 0:
			glTranslatef(2, 2, 0);
			break;
		case 1:
			glTranslatef(2, -2, 0);
			break;
		case 2:
			glTranslatef(-2, 2, 0);
			break;
		case 3:
			glTranslatef(-2, -2, 0);
			break;
		default:
			break;
		}
	}
		
	gluLookAt(eye[0], eye[1], eye[2],
		center[0], center[1], center[2],
		0, 1, 0);
	

	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	
	glRotatef(Angle, 0, 1, 0);
	DrawTable();
	
	glPopMatrix();
}