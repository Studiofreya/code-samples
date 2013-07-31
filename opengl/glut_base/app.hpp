//==============================================================================
//
//	app.hpp:
//	
//
//		App stuff here
//		
//
//==============================================================================

#if !defined(APP_HPP_INCLUDED)
#	 define	 APP_HPP_INCLUDED


//	System dependencies ...

//	Boost dependencies ...

//	Ogre dependencies ...

//	Project dependencies ...
	#include	"opengl.hpp"
	#include	"physics.hpp"


namespace Kamm
{

	class App
	{
		public:
			explicit App();
			virtual ~App();

			void run();


		public:
			static GL *gl;		// Instance of GL
			static Physics *px;
	};

}

#endif // APP_HPP_INCLUDED


