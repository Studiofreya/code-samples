//==============================================================================
//
//	opengl.cpp:
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
	#include	"opengl.hpp"

namespace Kamm
{


	GL::GL()
	{

	}

	GL::~GL()
	{

	}

	void GL::add( drawable *d )
	{
		m_Drawables.push_back(d);
	}

	void GL::render()
	{
		for (drawables_iter di = m_Drawables.begin();
			di != m_Drawables.end();
			++di
			)
		{
			
			glPushMatrix();
			(*di)->drawColor();
			(*di)->draw();
			glPopMatrix();
		}

	}
}


