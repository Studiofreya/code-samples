//==============================================================================
//
//	opengl.hpp:
//	
//
//		Bring in the OpenGL cannons here
//		
//
//==============================================================================

#if !defined(OPENGL_HPP_INCLUDED)
#	 define	 OPENGL_HPP_INCLUDED


//	System dependencies ...
	#include	<list>

//	Boost dependencies ...

//	GL dependencies ...
	#include	<GL/GLee.h>
	#include	<GL/glut.h>

//	Project dependencies ...
	#include	"drawables.hpp"



namespace Kamm
{
	class GL
	{
		typedef std::list<drawable*>			drawables;
		typedef drawables::const_iterator		drawables_iter;

		public:
			explicit GL();
			virtual ~GL();


			void add(drawable *d);
			void render();

		private:
			drawables	m_Drawables;
	};
}

#endif // OPENGL_HPP_INCLUDED


