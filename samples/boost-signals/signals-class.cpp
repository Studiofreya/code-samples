#include <memory>				// std::shared_ptr
#include <stdio.h>				// std::cout
#include <boost/signals2.hpp>	// boost::signals2

class UtilityClass 
{
	public:
		explicit UtilityClass()
		{
		}

		virtual ~UtilityClass()
		{
		}

	public:

		void handleSignal( double value )
		{
			std::cout << "Within a class: " << value << std::endl;
		}

		void handleHalfValue( double value )
		{
			std::cout << "Half: " << value / 2.0 << std::endl;
		}

};

int main()
{
	// Shortcut typedefs
	typedef	boost::signals2::signal<void(double)>	registration_manager;
	typedef	registration_manager::slot_type			registration_request;

	// Define the signal handler
	registration_manager signalHandler;

	// Make a class instance. std::unique_ptr is not possible, because we have to 
	// 'share' the pointer in the bind expression below.
	typedef std::shared_ptr<UtilityClass>		UtilityClass_ptr;
	UtilityClass_ptr utils( new UtilityClass() );

	// Connect the class to this handle,
	// for this we're using boost::bind
	signalHandler.connect( boost::bind( &UtilityClass::handleSignal, utils, _1) );		// Defined above
	signalHandler.connect( boost::bind( &UtilityClass::handleHalfValue, utils, _1) );	// Defined above

	// Call the handlers
	signalHandler( 3.14 );

	// Output should be:
	// Within a class: 3.14
	// Half: 1.57

	return 0;
}
