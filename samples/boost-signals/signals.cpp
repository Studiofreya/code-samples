#include <iostream>
#include <boost/signals2.hpp>

// Free function 1
void no_arguments()
{
	std::cout << "No arguments" << std::endl;
}

// Free function 2
void no_arguments_2()
{
	std::cout << "No arguments 2" << std::endl;
}

int test1_signals()
{
	// Shortcut typedefs
	typedef	boost::signals2::signal<void()>		registration_manager;
	typedef	registration_manager::slot_type		registration_request;

	// Define the signal handler
	registration_manager signalHandler;

	// Connect the above methods to this handler
	signalHandler.connect( &no_arguments );
	signalHandler.connect( &no_arguments_2 );

	// Call the handlers
	signalHandler();

	// Output should be:
	// No arguments
	// No arguments 2

	return 0;
}
