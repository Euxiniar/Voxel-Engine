#include "Display.h"
#include "Application.h"

int main()
{
	//On appelle la cr�ation de la fen�tre
	Display::init();
	//on cr�e une app
	Application app;
	//lancement du programme
	app.runMainGameLoop();
	return 0;
}