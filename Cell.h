/*
a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 3 - Game of Life
*/
/*Summary:
Header file for the Cell class. The cell class was created so that the core logic of the Game of Life could be better
implemented through functions such as getIsAlive and getNumNeighbors.
*/
#ifndef CELL_H
#define CELL_H

class Cell
{
public:
	Cell();
	short getNumNeighbors();
	bool getIsAlive();
	void setIsAlive(bool condition);
	void setNumNeighbors(int numNeighbors);
	void nextGeneration();
private:
	short m_numNeighbors;
	bool m_isAlive;
};
#endif
