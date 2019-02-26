#include "Cell.h"



Cell::Cell()
{
	m_numNeighbors = -1;
	m_isAlive = false;
}
short Cell::getNumNeighbors()
{
	return m_numNeighbors;
}
bool Cell::getIsAlive()
{
	return m_isAlive;
}
void Cell::setIsAlive(bool condition)
{
	m_isAlive = condition;
}
