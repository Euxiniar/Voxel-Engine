#include "Display.h"
#include "Application.h"
#include "Noise.h"
#include "Random_Maths.h"

int main()
{
	//On appelle la cr�ation de la fen�tre
	Display::create("GrandmontCraft");
	//on cr�e une app
	Application app;
	//lancement du programme
	app.runMainGameLoop();
	
	/*HeightMap::Noise noise;
	noise.setBound(0, 0);
	noise.draw("truc.bmp");
	noise.setBound(1, 0);
	noise.draw("truc2.bmp");*/
	//system("PAUSE");
	return 0;
}