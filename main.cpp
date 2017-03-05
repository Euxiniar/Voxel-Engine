#include "Display.h"
#include "Application.h"
#include "Noise.h"

int main()
{
	////On appelle la création de la fenêtre
	//Display::create("GrandmontCraft");
	////on crée une app
	//Application app;
	////lancement du programme
	//app.runMainGameLoop();
	HeightMap::Noise noise;
	noise.draw();
	return 0;
}