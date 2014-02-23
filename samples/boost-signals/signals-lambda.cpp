#include <stdio.h>				// std::cout
#include <boost/signals2.hpp>	// boost::signals2


int main()
{
	// Shortcut typedefs
	typedef	boost::signals2::signal<void(double)>	registration_manager;
	typedef	registration_manager::slot_type			registration_request;

	// Define the signal handler
	registration_manager signalHandler;

	// Make a named lambda
	auto namedLambda = [&]( double value )
	{
		std::cout << "Lambda input value: " << value << std::endl;
	};

	// Connect the class to this handle,
	// for this we're using boost::bind
	signalHandler.connect( namedLambda );		// Named lambda defined above

	// Connect to inline lambda
	signalHandler.connect( [&]( double value )
	{
		std::cout << "Inline lambda input value: " << value << std::endl;
	});	// Defined here

	// Call the handlers
	signalHandler( 3.14 );

	// Output should be:
	// Lambda input value: 3.14
	// Inline lambda input value: 3.14

	return 0;
}
