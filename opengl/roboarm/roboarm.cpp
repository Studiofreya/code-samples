
#include <Windows.h>

#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

class arm 
{
public:
	float length;
	float x, y, z;
	float speed;
	arm(){length=1.0f; y=1.0f; x=z=0; speed=1.0f;}
};

arm *arms;
float angle=0.0f;
int numarms = 20;
int i=0;

void drawCoords()
{
	///*
	glPushMatrix();
	glBegin(GL_LINES);
	// X in red...
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0); 
	glVertex3f(1, 0, 0);

	// Y in green
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, 0, 0); 
	glVertex3f(0, 1, 0);

	// Z in blue
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, 0); 
	glVertex3f(0, 0, 1);

	glColor3f(1.0f, 1.0f, 1.0f);

	/*
	// floor
	for (int xx=-50; xx<50; xx++)
	{
		glVertex3f(xx, 0, -50);
		glVertex3f(xx, 0, 50);
		glVertex3f(50, 0, xx);
		glVertex3f(-50, 0, xx);
	}
	glEnd();
	glPopMatrix();
	//*/
}

void drawRoboarm(int slices, float length)
{
	glPushMatrix();
	if (slices > 2)
	{
		for (int i=0; i<slices; i++)
		{
			glRotatef(360/slices,0 ,1, 0);
			glBegin(GL_LINE_STRIP);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.2f, length/5, 0.0f);
			glVertex3f(0.2f, length/5, 0.0f);
			glVertex3f(0.0f, length, 0.0f);
			glEnd();
		}

		glBegin(GL_LINES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, length, 0.0f);
		glEnd();
	}
	glPopMatrix();
}

void drawArms()
{
	srand(GetTickCount());

	glPushMatrix();
	if (i < numarms)
	{
		drawRoboarm(4, arms[i].length);

		glTranslatef(0.0f, arms[i].length, 0.0f);
		glRotatef(angle*arms[i].speed, arms[i].x, arms[i].y, arms[i].z);
		
		i++;

		drawArms();
	}
	glPopMatrix();
}

void draw()
{	
	angle += 1.0f;
	i=0;
	drawArms();
}

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(50.0f, 3.0f, 100.0f,
		0.0f, 2.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	
	drawCoords();
	
	draw();
	Sleep(10);
	glutSwapBuffers();
}

void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	//w = w1;
	//h = h1;
	GLdouble ratio = 1.0f * w / h;
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the clipping volume
	gluPerspective(45,ratio,0.1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

int main(int argc, char **argv)
{
	srand(GetTickCount()); 
	arms = new arm[numarms];
	
	for (int i=0; i<numarms; i++)
	{
		arms[i].length = (float)(rand() % 10000) / 1000;
		arms[i].x=rand();
		arms[i].y=rand();
		arms[i].z=rand();
		arms[i].speed=(float)(rand() % 1000) / 700 ;
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640,480);
	glutCreateWindow("Do the robo baby!");

	glEnable(GL_DEPTH_TEST);
	glutIgnoreKeyRepeat(1);
	
	glutReshapeFunc(changeSize);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);

	glutMainLoop();
}