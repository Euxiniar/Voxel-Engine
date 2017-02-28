#include "Display.h"
#include "Application.h"

int main()
{
	//On appelle la création de la fenêtre
	Display::init();
	//on crée une app
	Application app;
	//lancement du programme
	app.runMainGameLoop();
	return 0;
}