/*
a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 3 - Game of Life
*/
/*Summary:
Implementation for the Simulation class. Contains the functions to generate and manipulate the pre and post generations.
It also contains the function playGame() which is the main logic for the Game of Life.
*/
#include <random>
#include <ctime>
#include "Simulation.h"
#include <fstream>
#include <iostream>
using namespace std;
/*
a. Simulation()
b. @return - NA(Constructor)
c. @param - NA(Default Constructor)
d. No exceptions thrown.
*/
Simulation::Simulation()
{

}
/*
a. Simulation(int height, int length)
b. @return - NA(Constructor)
c. @param - int height - an int value that represents the height that the user wishes for their grid
						int length - an int value that represents the length that the user wishes for their grid
d. No exceptions thrown.
*/
Simulation::Simulation(int height, int length) : m_Postgen(height, length), m_Pregen(height, length)
{
}
/*
a. ~Simulation()
b. @return - NA(Destructor)
c. @param - NA(Destructor)
d. No exceptions thrown.
*/
Simulation::~Simulation()
{

}
/*
a. playGame(int height, int length)
b. @return - void
c. @param - int height - an int value that represents the height of the grid.
						int length - an int value that represents the length of the grid.
d. No exceptions thrown.
*/
void Simulation::playGame(int height, int length)
{
	m_Postgen.displayGrid();
	shadowPage(height, length);
	calcNeighbors(height, length);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			if (m_Pregen.getBoard()[i][j].getIsAlive())
			{
				m_Postgen.getBoard()[i][j].setIsAlive(true);
			}
			else
			{
				m_Postgen.getBoard()[i][j].setIsAlive(false);
			}
		}
	}
	//createGeneration(height, length);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			m_Postgen.getBoard()[i][j].nextGeneration();
		}
	}
	//getPostgen().displayGrid();
}
/*
a. playGame(ofstream& outputStream, int height, int length)
b. @return - void
c. @param - ofstream& outputStream - a reference to the outputStream used to print to the file
						int height - an int value used to represent the height of the grid.
						int length - an int value used to represent the length of the grid.
d. No exceptions thrown.
*/
void Simulation::playGame(ofstream& outputStream, int height, int length)
{
	shadowPage(height, length);
	calcNeighbors(height, length);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			if (m_Pregen.getBoard()[i][j].getIsAlive())
			{
				m_Postgen.getBoard()[i][j].setIsAlive(true);
			}
			else
			{
				m_Postgen.getBoard()[i][j].setIsAlive(false);
			}
		}
	}
	//createGeneration(height, length);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			m_Postgen.getBoard()[i][j].nextGeneration();
		}
	}
	printGridToFile(outputStream, height, length);
}
/*
a. populatePostgen(ifstream& streamName,int height, int length)
b. @return - void
c. @param - ifstream& streamName - a reference to an ifstream that is necessarry for reading information from the
passed in file.
						int height - an int value that represents the height of the passed in grid.
						int length - an int value that represents the length of the passed in grid.
d. No exceptions thrown.
*/
void Simulation::populatePostgen(ifstream& streamName, int height, int length)
{
	string line;

	getline(streamName, line);
	for (int i = 0; i < height; ++i)
	{
		getline(streamName, line);
		for (int j = 0; j < length; ++j)
		{
			if (line[j] == 'X')
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
/*
a. populatePostgen(double density, int height, int length)
b. @return - void
c. @param - double density - a double value that represents the density passed in by the user
						int height - an int value passed in by the user that represents the height of the grid.
						int length - an int value passed in by the user that represents the length of the grid.
d. No exceptions thrown.
*/
void Simulation::populatePostgen(double density, int height, int length)
{
	srand(time(0));
	double random;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			random = (double)rand() / RAND_MAX;
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
/*
a. getPregen
b. @return - a reference to a grid that represents the pre-generation
c. @param - none
d. No exceptions thrown.
*/
Grid& Simulation::getPregen()
{
	return m_Pregen;
}
/*
a. getPostgen
b. @return - a reference to a grid that represents the post-generation
c. @param - none
d. No exceptions thrown.
*/
Grid& Simulation::getPostgen()
{
	return m_Postgen;
}
/*
a. setPregen
b. @return - void
c. @param - a Grid value that represents the grid that we would like to set out current Pregen to.
d. No exceptions thrown.
*/
void Simulation::setPregen(Grid Pregen)
{
	m_Pregen = Pregen;
}
/*
a. setPostgen
b. @return - void
c. @param - a Grid value that represents the grid that we would like to set out current Postgen to.
d. No exceptions thrown.
*/
void Simulation::setPostgen(Grid Postgen)
{
	m_Postgen = Postgen;
}
/*
a. setOutputmode
b. @return - void
c. @param - an enum value that represents the output mode that the user selected.
d. No exceptions thrown.
*/
void Simulation::setOutputmode(Simulation::kOutputmode outputmode)
{
	m_outputmode = outputmode;
}
/*
a. shadowPage
b. @return - void
c. @param - int height - an int value that represents the height of the grid that we are switching
						int length - an int value that represents the length of the grid that we are switching
d. No exceptions thrown.
*/
void Simulation::shadowPage(int height, int length)
{
	Cell **cup;
	cup = (m_Pregen.getBoard());
	//set pregen to postgen
	m_Pregen.setBoard(m_Postgen.getBoard());
	//call constructor on postgen
	m_Postgen.setBoard(cup);
	//Postgen lose reference for deep copy
}
/*
a. calcNeighbors
b. @return - void
c. @param - int height - an int value that represents the height of the grid that we are calculating neighbors for
						int length - an int value that represents the length of the grid that we are calculating neighbors for
d. No exceptions thrown.
*/
void Simulation::calcNeighbors(int height, int length)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			int numNeighbors = 0;
			if (m_Pregen.cellIsOutOfBounds(i - 1, j - 1))
			{
				switch (gamemode)
				{
				case CLASSIC:
					//nothing needs to happen here
					break;
				case MIRROR:
					numNeighbors += runMirrorMode(i - 1, j - 1);
					break;
				case DOUGHNUT:
					numNeighbors += runDoughnutMode(i - 1, j - 1);
					break;
				}
			}
			else
			{
				if (m_Pregen.getBoard()[i - 1][j - 1].getIsAlive())
				{
					numNeighbors++;
				}
			}
			//i,j-1
			if (m_Pregen.cellIsOutOfBounds(i, j - 1))
			{
				switch (gamemode)
				{
				case CLASSIC:
					//nothing needs to happen here
					break;
				case MIRROR:
					numNeighbors += runMirrorMode(i, j - 1);
					break;
				case DOUGHNUT:
					numNeighbors += runDoughnutMode(i, j - 1);
					break;
				}
			}
			else
			{
				if (m_Pregen.getBoard()[i][j - 1].getIsAlive())
				{
					numNeighbors++;
				}
			}
			//i+1,j-1
			if (m_Pregen.cellIsOutOfBounds(i + 1, j - 1))
			{
				switch (gamemode)
				{
				case CLASSIC:
					//nothing needs to happen here
					break;
				case MIRROR:
					numNeighbors += runMirrorMode(i + 1, j - 1);
					break;
				case DOUGHNUT:
					numNeighbors += runDoughnutMode(i + 1, j - 1);
					break;
				}
			}
			else
			{
				if (m_Pregen.getBoard()[i + 1][j - 1].getIsAlive())
				{
					numNeighbors++;
				}
			}
			//i-1,j
			if (m_Pregen.cellIsOutOfBounds(i - 1, j))
			{
				switch (gamemode)
				{
				case CLASSIC:
					//nothing needs to happen here
					break;
				case MIRROR:
					numNeighbors += runMirrorMode(i - 1, j);
					break;
				case DOUGHNUT:
					numNeighbors += runDoughnutMode(i - 1, j);
					break;
				}
			}
			else
			{
				if (m_Pregen.getBoard()[i - 1][j].getIsAlive())
				{
					numNeighbors++;
				}
			}
			//i+1,j-1
			if (m_Pregen.cellIsOutOfBounds(i + 1, j))
			{
				switch (gamemode)
				{
				case CLASSIC:
					//nothing needs to happen here
					break;
				case MIRROR:
					numNeighbors += runMirrorMode(i + 1, j);
					break;
				case DOUGHNUT:
					numNeighbors += runDoughnutMode(i + 1, j);
					break;
				}
			}
			else
			{
				if (m_Pregen.getBoard()[i + 1][j].getIsAlive())
				{
					numNeighbors++;
				}
			}
			//i-1,j
			if (m_Pregen.cellIsOutOfBounds(i - 1, j + 1))
			{
				switch (gamemode)
				{
				case CLASSIC:
					//nothing needs to happen here
					break;
				case MIRROR:
					numNeighbors += runMirrorMode(i - 1, j + 1);
					break;
				case DOUGHNUT:
					numNeighbors += runDoughnutMode(i - 1, j + 1);
					break;
				}
			}
			else
			{
				if (m_Pregen.getBoard()[i - 1][j + 1].getIsAlive())
				{
					numNeighbors++;
				}
			}
			//i,j+1
			if (m_Pregen.cellIsOutOfBounds(i, j + 1))
			{
				switch (gamemode)
				{
				case CLASSIC:
					//nothing needs to happen here
					break;
				case MIRROR:
					numNeighbors += runMirrorMode(i, j + 1);
					break;
				case DOUGHNUT:
					numNeighbors += runDoughnutMode(i, j + 1);
					break;
				}
			}
			else
			{
				if (m_Pregen.getBoard()[i][j + 1].getIsAlive())
				{
					numNeighbors++;
				}
			}
			//i+1,j+1
			if (m_Pregen.cellIsOutOfBounds(i + 1, j + 1))
			{
				switch (gamemode)
				{
				case CLASSIC:
					//nothing needs to happen here
					break;
				case MIRROR:
					numNeighbors += runMirrorMode(i + 1, j + 1);
					break;
				case DOUGHNUT:
					numNeighbors += runDoughnutMode(i + 1, j + 1);
					break;
				}
			}
			else
			{
				if (m_Pregen.getBoard()[i + 1][j + 1].getIsAlive())
				{
					numNeighbors++;
				}
			}
			m_Postgen.getBoard()[i][j].setNumNeighbors(numNeighbors);
		}
	}
}
/*
a. runMirrorMode
b. @return - an int value that represents an added neighbor in the mirror mode
c. @param - int height - an int value that represents the height of the grid that we are running mirror mode on
						int length - an int value that represents the length of the grid that we are running mirror mode on
d. No exceptions thrown.
*/
int Simulation::runMirrorMode(int i, int j)
{
	if (i < 0)
	{
		if (j < 0)
		{
			if (m_Pregen.getBoard()[i + 1][j + 1].getIsAlive())
			{
				return 1;
			}
		}
		else if (i >= m_Pregen.getHeight())
		{
			if (m_Pregen.getBoard()[i + 1][j - 1].getIsAlive())
			{
				return 1;
			}
		}
		else
		{
			if (m_Pregen.getBoard()[i + 1][j].getIsAlive())
			{
				return 1;
			}
		}
	}
	else if (j >= m_Pregen.getLength())
	{
		if (j < 0)
		{
			if (m_Pregen.getBoard()[i - 1][j + 1].getIsAlive())
			{
				return 1;
			}
		}
		else if (i >= m_Pregen.getHeight())
		{
			if (m_Pregen.getBoard()[i - 1][j - 1].getIsAlive())
			{
				return 1;
			}
		}
		else
		{
			if (m_Pregen.getBoard()[i - 1][j].getIsAlive())
			{
				return 1;
			}
		}
	}
	else if (j < 0)
	{
		if (m_Pregen.getBoard()[i][j + 1].getIsAlive())
		{
			return 1;
		}
	}
	else if (i >= m_Pregen.getHeight())
	{
		if (m_Pregen.getBoard()[i][j - 1].getIsAlive())
		{
			return 1;
		}
	}
	return 0;
}
/*
a. runDoughnutMode
b. @return - an int value that represents the added neighbors in doughnut mode.
c. @param - int height - an int value that represents the height of the grid that we are running doughnut mode on
						int length - an int value that represents the length of the grid that we are running doughnut mode on
d. No exceptions thrown.
*/
int Simulation::runDoughnutMode(int i, int j)
{
	if (i < 0)
	{
		i += m_Pregen.getHeight();
	}
	else if (i >= m_Pregen.getHeight())
	{
		i -= m_Pregen.getHeight();
	}
	if (j < 0)
	{
		j += m_Pregen.getLength();
	}
	else if (j >= m_Pregen.getLength())
	{
		j -= m_Pregen.getLength();
	}
	if (m_Pregen.getBoard()[i][j].getIsAlive())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*
a. getGamemode
b. @return - kGamemode - an enum value that represents the selected gamemode
c. @param - none
d. No exceptions thrown.
*/
Simulation::kGamemode Simulation::getGamemode()
{
	return gamemode;
}
/*
a. setGamemode
b. @return - void
c. @param - a kGamemode enum value that represents the gamemode that we wish to switch to
d. No exceptions thrown.
*/
void Simulation::setGamemode(Simulation::kGamemode someGamemode)
{
	gamemode = someGamemode;
}
/*
a. checkIsStable
b. @return - a boolean value that represents whether or not a simulation is stable
c. @param - none
d. No exceptions thrown.
*/
bool Simulation::checkIsStable()
{
	if (m_Pregen.compare(m_Postgen))
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
a. getOutputmode
b. @return - kOutputmode - an enum value that represents the selected output mode
c. @param - none
d. No exceptions thrown.
*/
Simulation::kOutputmode Simulation::getOutputmode()
{
	return m_outputmode;
}
/*
a. printGridToFile
b. @return - void
c. @param - ofstream& outputStream - a reference to an ofstream that is necessary to printing to a file.
d. No exceptions thrown.
*/
void Simulation::printGridToFile(ofstream& outputStream, int height, int length)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			m_Pregen.getBoard()[i][j].getIsAlive() ? outputStream << "X" : outputStream << "-";
		}
		outputStream << "\n";
	}
}
