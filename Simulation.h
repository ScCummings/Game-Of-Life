#ifndef SIMULATION_H
#define SIMULATION_H

#include "Grid.h"
#include <string>

using namespace std;
class Simulation : Grid
{
public:
	Simulation();
	~Simulation();
	enum kGamemode
	{
		classic,
		mirror,
		doughnut
	};
	void playGame();
	Grid generateGrid(string filename);
	void populatePostgen(double density, int height, int length);
	bool getIsPaused();
	Grid getPregen();
	Grid getPostgen();
	kGamemode getGameMode();
	Grid generatePostGen();
	void setIsPaused(bool condition);
	void setPregen(Grid Pregen);
	void setPostgen(Grid Postgen);
	void setGameMode(kGamemode someGamemode);
private:
	bool m_isPaused;
	Grid m_Pregen;
	Grid m_Postgen;
	kGamemode gamemode;
};
#endif
