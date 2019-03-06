/*
a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 3 - Game of Life
*/
/*Summary:
The header file for the Grid class. A grid is essentially the double array of cells that is used to represent the playing
space.
*/
#ifndef GRID_H
#define GRID_H
#include "Cell.h"
class Grid
{
public:
	Grid();
	Grid(int height, int length);
	~Grid();
	void displayGrid();
	Cell** getBoard();
	bool cellIsOutOfBounds(int height, int length);
	int getHeight();
	int getLength();
	void displayNumNeighbors(); //- only existed for debugging
	bool compare(Grid& someGrid);
	void setBoard(Cell** someBoard);
private:
	Cell * * board;
	int m_height;
	int m_length;
};
#endif
