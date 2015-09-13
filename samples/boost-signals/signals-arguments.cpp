#include <iostream>
#include <boost/signals2.hpp>

// Free function 1
void argument(double value)
{
	std::cout << "Arguments " << value << std::endl;
}

// Free function 2
void argument_2(double value)
{
	std::cout << "Half argument " << value / 2.0 << std::endl;
}

int test2_arguments()
{
	// Shortcut typedefs
	typedef	boost::signals2::signal<void(double)>	registration_manager;
	typedef	registration_manager::slot_type			registration_request;

	// Define the signal handler
	registration_manager signalHandler;

	// Connect the above methods to this handler
	signalHandler.connect( &argument );		// Defined above
	signalHandler.connect( &argument_2 );	// Defined above

	// Call the handlers
	signalHandler( 3.14 );

	// Output should be:
	// Arguments 3.14
	// Half argument 1.57

	return 0;
}
