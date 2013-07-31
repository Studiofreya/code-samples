//==============================================================================
//
//	app.cpp:
//	
//
//		
//		
//
//==============================================================================


//	System dependencies ...

//	Boost dependencies ...

//	Ogre dependencies ...

//	Project dependencies ...
	#include	"app.hpp"
	#include	"objects.hpp"


namespace Kamm
{


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
	}


	void renderScene()
	{
		App::px->calculate();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		gluLookAt(20.0f, 20.0f, 20.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f);

		drawCoords();

		App::gl->render();

		Sleep(10);
		glutSwapBuffers();

	}


	App::App()
	{
		// Make our root objects
		gl = new GL();
		px = new Physics();

		// Init positions
		float v1[3] = {0.0f,0.0f,0.0f};
		float v2[3] = {0.0f,0.0f,5.0f};
		float v3[3] = {5.0f,0.0f,0.0f};

		// Fill scene with objects
		Sphere *s1 = new Sphere( Vector3(v1), 2, 1.0f );
		Sphere *s2 = new Sphere( Vector3(v2), 2.5, 3.0f );
		Sphere *s3 = new Sphere( Vector3(v3), 3, 4.0f );

		s1->m_Color[0] = 1.0f;
		s2->m_Color[1] = 1.0f;
		s3->m_Color[2] = 1.0f;
 		
		gl->add(s1);
		gl->add(s2);
		gl->add(s3);

		// Physics
		px->add(s1);
		px->add(s2);
		px->add(s3);

		px->setDt(1.0 / 30.0); // 30 times a second


	}

	App::~App()
	{

	}

	void App::run()
	{
		// Kick the baby
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowSize(640,480);
		glutCreateWindow("Simple sphere-sphere collision!");

		glEnable(GL_DEPTH_TEST);
		glutIgnoreKeyRepeat(1);

		glutReshapeFunc(changeSize);
		glutDisplayFunc(renderScene);
		glutIdleFunc(renderScene);

		glutMainLoop();
	}


	GL * App::gl;
	Physics * App::px;

}

