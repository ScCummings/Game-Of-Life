#include "Grid.h"
#include "Cell.h"
Grid::Grid()
{

	board = new Cell*[1];
}
Grid::Grid(int height, int length)
{
	board = new Cell*[height];
	for (int i = 0; i < height; ++i)
	{
		board[i] = new Cell[length];
	}
}
Grid::~Grid()
{
	for (int i = 0; i < height; ++i)
	{
		delete[] board[i];
	}
	delete[] board;
}
Cell** Grid::getBoard()
{
	return board;
}
