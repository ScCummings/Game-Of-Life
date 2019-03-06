/*
a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 3 - Game of Life
*/
/*Summary:
Header file for the Simulation class. The Simulation class was created to easily keep track of the generations that
were being created and manipulated over the course of the program.
*/
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Grid.h"

#include <string>
#include <fstream>

using namespace std;
class Simulation
{
public:
	Simulation();
	Simulation(int height, int length);
	~Simulation();
	void playGame(int height, int length);
	void playGame(ofstream& outputStream, int height, int length);
	void populatePostgen(ifstream& streamName, int height, int length);
	void populatePostgen(double density, int height, int length);
	Grid& getPregen();
	Grid& getPostgen();
	void setPregen(Grid Pregen);
	void setPostgen(Grid Postgen);
	enum kOutputmode
	{
		PAUSED,
		ENTER,
		FILE
	};
	enum kGamemode
	{
		CLASSIC,
		MIRROR,
		DOUGHNUT
	};
	kGamemode getGamemode();
	void setGamemode(kGamemode someGamemode);
	kOutputmode getOutputmode();
	void setOutputmode(kOutputmode outputmode);
	void shadowPage(int height, int length);
	void calcNeighbors(int height, int length);
	int runMirrorMode(int i, int j);
	int runDoughnutMode(int i, int j);
	bool checkIsStable();
	void printGridToFile(ofstream& outputStream, int height, int length);
private:
	bool isStable;
	kGamemode gamemode;
	kOutputmode m_outputmode;
	Grid m_Pregen;
	Grid m_Postgen;
};
#endif
