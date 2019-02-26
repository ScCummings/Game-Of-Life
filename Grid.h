#ifndef GRID_H
#define GRID_H
class Grid
{
public:
	Grid();
	Grid(int height, int length);
	~Grid();
	void calcNeighbors();
	void displayGrid();
private:
	int ** board;
	int height;
	int length;
};
#endif
