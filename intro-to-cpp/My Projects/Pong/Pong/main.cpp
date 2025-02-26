#include "Application.h"

int main()
{
	Application* app = new Application;

	int status = app->Run();

	delete app;

	return status;
}