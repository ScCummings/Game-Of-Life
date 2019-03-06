/*
a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 3 - Game of Life
*/
/*Summary:
Implementation for the Grid class. Keeps track of the height and length of each generation's board. As well as a double
array of Cells (the board).
*/
#include "Grid.h"
#include "Cell.h"
#include "Simulation.h"
#include <iostream>

using namespace std;
/*
a. Grid
b. @return - NA (Constructor)
c. @param - NA (Constructor)
d. No exceptions thrown.
*/
Grid::Grid()
{
	board = new Cell*[1];
}
/*
a. Grid(int height, int length)
b. @return - NA(Constructor)
c. @param - int height: an int value that represents the user's desired height for the grid.
						int length: an int value that represents the user's desired length for the grid.
d. No exceptions thrown.
*/
Grid::Grid(int height, int length)
{
	m_height = height;
	m_length = length;
	board = new Cell*[height];
	for (int i = 0; i < height; ++i)
	{
		board[i] = new Cell[length];
	}
}
/*
a. ~Grid()
b. @return - NA(Destructor)
c. @param - NA(Destructor)
d. No exceptions thrown.
*/
Grid::~Grid()
{
	for (int i = 0; i < m_height; ++i)
	{
		delete[] board[i];
	}
	delete[] board;
}
/*
a. getBoard
b. @return - a Cell** that represents the board upon which the Game of Life is played.
c. @param - none
d. No exceptions thrown.
*/
Cell** Grid::getBoard()
{
	return board;
}
/*
a. displayGrid
b. @return - void
c. @param - none
d. No exceptions thrown.
*/
void Grid::displayGrid()
{
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_length; ++j)
		{

			board[i][j].getIsAlive() ? cout << "X" : cout << "-";
		}
		cout << "\n";
	}
}
/*
a. displayNumNeighbors - only existed for debugging
b. @return - void
c. @param - none
d. No exceptions thrown.
*/
void Grid::displayNumNeighbors()
{
	cout << m_height << endl;
	cout << m_length << endl;
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_length; ++j)
		{
			cout << board[i][j].getNumNeighbors();
		}
		cout << "\n";
	}
}
/*
a. cellIsOutOfBounds
b. @return - bool value representing whether or not the cell is out of bounds
c. @param - int i - the length index at which the cell is located.
						int j - the height index at which the cell is located.
d. No exceptions thrown.
*/
bool Grid::cellIsOutOfBounds(int i, int j)
{
	if (!(i < 0 || i >= m_height) && !(j < 0 || j >= m_length))
	{
		return false;
	}
	else
	{
		return true;
	}
}
/*
a. getHeight
b. @return - an int value that represents the height of the grid
c. @param - none
d. No exceptions thrown.
*/
int Grid::getHeight()
{
	return m_height;
}
/*
a. getLength
b. @return - an int value that represents the length of the grid
c. @param - none
d. No exceptions thrown.
*/
int Grid::getLength()
{
	return m_length;
}
/*
a. compare
b. @return - a boolean value that represents whether or not two compared grids are the same.
c. @param - Grid &someGrid - the Grid that we wish to compare to.
d. No exceptions thrown.
*/
bool Grid::compare(Grid &someGrid)
{
	bool isEqual = true;
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_length; ++j)
		{
			if (board[i][j].getIsAlive() != someGrid.getBoard()[i][j].getIsAlive())
			{
				isEqual = false;
			}
		}
	}
	return isEqual;
}
/*
a. setBoard
b. @return - void
c. @param - Cell** someBoard - a Cell** that represents the board that we wish to set out current board to.
d. No exceptions thrown.
*/
void Grid::setBoard(Cell** someBoard)
{
	board = someBoard;
}
