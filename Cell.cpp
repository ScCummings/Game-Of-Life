/*
a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 3 - Game of Life
*/
/*Summary:
Implementation for the cell class. Keeps track of the Cell's core data: if it is alive and how many neighbors it has.
*/
#include "Cell.h"
/*
a. Cell
b. @return - NA(Constructor)
c. @param - NA(Default Constructor)
d. No exceptions thrown.
*/
Cell::Cell()
{
	m_numNeighbors = -1;
	m_isAlive = false;
}
/*
a. getNumNeighbors
b. @return - a short value that represents the number of neighbors that the cell has
c. @param - none
d. No exceptions thrown.
*/
short Cell::getNumNeighbors()
{
	return m_numNeighbors;
}
/*
a. getIsAlive
b. @return - a boolean value that represents whether or not the cell is alive
c. @param - none
d. No exceptions thrown.
*/
bool Cell::getIsAlive()
{
	return m_isAlive;
}
/*
a. setIsAlive
b. @return - void
c. @param - a boolean condition that we wish to set out cell to
d. No exceptions thrown.
*/
void Cell::setIsAlive(bool condition)
{
	m_isAlive = condition;
}
/*
a. setNumNeighbors
b. @return - void
c. @param - an int value that represents the number of neighbors that we would like to give our cell
d. No exceptions thrown.
*/
void Cell::setNumNeighbors(int numNeighbors)
{
	m_numNeighbors = numNeighbors;
}
/*
a. nextGeneration
b. @return - void
c. @param - none
d. No exceptions thrown.
*/
void Cell::nextGeneration()
{
	switch (m_numNeighbors)
	{
	case 0:
	case 1:
		m_isAlive = false;
		break;
	case 2:
		break;
	case 3:
		m_isAlive = true;
		break;
	default:
		m_isAlive = false;
	}
}
