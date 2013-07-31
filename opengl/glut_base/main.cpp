

#include "app.hpp"


using namespace Kamm;

int main(int argc, char **argv)
{
	App *app = new App();
	
	glutInit(&argc, argv);
	app->run();

	return 0;
}