#ifndef CELL_H
#define CELL_H

class Cell
{
public:
	Cell();
	short getNumNeighbors();
	bool getIsAlive();
	void setIsAlive(bool condition);
private:
	short m_numNeighbors;
	bool m_isAlive;
};
#endif
