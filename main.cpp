#include "Display.h"
#include "Application.h"
#include "Noise.h"
#include "Random_Maths.h"

int main()
{
	////On appelle la cr�ation de la fen�tre
	//Display::create("GrandmontCraft");
	////on cr�e une app
	//Application app;
	////lancement du programme
	//app.runMainGameLoop();
	Random::init();
	HeightMap::Noise noise;
	noise.draw();
	return 0;
}