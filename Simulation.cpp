#include <random>
#include <ctime>
#include "Simulation.h"
using namespace std;
Simulation::Simulation()
{
}
Simulation::~Simulation()
{
}
void Simulation::playGame()
{

}
/*Grid Simulation::generateGrid(string filename)
{

}*/
void Simulation::populatePostgen(double density, int height, int length)
{
	srand(time(0));
	double random = rand();
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			if (random <= density)
			{
				m_Postgen.getBoard()[i][j].setIsAlive(true);
			}
			else
			{
				m_Postgen.getBoard()[i][j].setIsAlive(false);
			}
		}
	}
}
bool Simulation::getIsPaused()
{
	return m_isPaused;
}
Grid Simulation::getPregen()
{
	return m_Pregen;
}
Grid Simulation::getPostgen()
{
	return m_Postgen;
}
Simulation::kGamemode Simulation::getGameMode()
{
	return gamemode;
}
/*Grid Simulation::generatePostGen()
{

}*/
void Simulation::setIsPaused(bool condition)
{
	m_isPaused = condition;
}
void Simulation::setPregen(Grid Pregen)
{
	m_Pregen = Pregen;
}
void Simulation::setPostgen(Grid Postgen)
{
	m_Postgen = Postgen;
}
void Simulation::setGameMode(Simulation::kGamemode someGamemode)
{
	gamemode = someGamemode;
}
