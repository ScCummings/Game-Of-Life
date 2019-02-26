#ifndef GRID_H
#define GRID_H
#include "Cell.h"
class Grid
{
public:
	Grid();
	Grid(int height, int length);
	~Grid();
	void calcNeighbors();
	void displayGrid();
	Cell** getBoard();
private:
	Cell** board;
	int height;
	int length;
};
#endif
