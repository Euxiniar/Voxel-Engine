#include "Display.h"
#include "Application.h"
#include "Noise.h"

int main()
{
	////On appelle la cr�ation de la fen�tre
	//Display::create("GrandmontCraft");
	////on cr�e une app
	//Application app;
	////lancement du programme
	//app.runMainGameLoop();
	HeightMap::Noise noise;
	noise.draw();
	return 0;
}