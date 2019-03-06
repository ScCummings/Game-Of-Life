/*
a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 3 - Game of Life
*/
/*Summary:
The main function for the assignment. Dictates when and how the objects and functions from the other classes are
implemented. Switches and enums are used to keep track of the various modes that the game can be played in.
*/
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Simulation.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int getInt();
double getDensity();
bool fileExists(string filename);

int main()
{
	double density; // the density of the created grid
	int height; // the height of the created grid
	int length; // the length of the created grid
	string filename; // the filename of the input file name should the user wish to enter in a precreated grid
	string enteredValue; // a variable used to keep track of what option the user chooses to go for out of random or
	//file
	string modeName; // a variable used to keep track of the mode that the user would like to run in. (Classic,Mirror,Doughnut)
	string outputStyle; // a variable used to keep track of the way in which the user would like to recieve their output.
	string outputFileName; // a variable used to keep track of the name of the output file that the user wishes to print to
	Simulation *s1 = 0; // simulation variable that represents the entire playing of the Game of Life.

	while (true)
	{
		cout << "Randomly create grid(\"random\") or enter in file?(\"file\")" << endl;
		getline(cin, enteredValue);
		if (!enteredValue.compare("random"))
		{
			cout << "What would you like the density of your grid to be? ";
			density = getDensity();
			cout << "What would you like the height of your grid to be? ";
			height = getInt();
			cout << "What would you like the length of your grid to be? ";
			length = getInt();
			s1 = new Simulation(height, length);
			(*s1).populatePostgen(density, height, length);
			break;
		}
		else if (!enteredValue.compare("file"))
		{
			while (true)
			{
				cout << "What is the filename?" << endl;
				getline(cin, filename);
				if (fileExists(filename))
				{
					ifstream ifs(filename);
					ifs >> height;
					ifs >> length;
					if (ifs.fail())
					{
						cout << "Check the format of your file. The height or length was not able to be read." << endl;
					}
					else
					{
						s1 = new Simulation(height, length);
						(*s1).populatePostgen(ifs, height, length);
						goto End;
					}
				}
				else
				{
					cout << "Error. File not found." << endl;
				}
			}
		}
		else
		{
			cout << "Sorry, input not recognized." << endl;
		}
	}
End:
	while (true)
	{
		cout << "Would you like classic, doughnut, or mirror mode?";
		getline(cin, modeName);
		if (!modeName.compare("classic"))
		{
			s1->setGamemode(Simulation::CLASSIC);
			break;
		}
		else if (!modeName.compare("doughnut"))
		{
			s1->setGamemode(Simulation::DOUGHNUT);
			break;
		}
		else if (!modeName.compare("mirror"))
		{
			s1->setGamemode(Simulation::MIRROR);
			break;
		}
		else
		{
			cout << "Sorry. That input was not recognized." << endl;
		}
	}
	//output modes
	while (true)
	{

		cout << "Would you like to pause(\"pause\") between generations, press enter(\"enter\") between generations, or output to a file(\"file\")?";
		getline(cin, outputStyle);
		if (!outputStyle.compare("pause"))
		{
			s1->setOutputmode(Simulation::kOutputmode::PAUSED);
			break;
		}
		else if (!outputStyle.compare("enter"))
		{
			s1->setOutputmode(Simulation::kOutputmode::ENTER);
			break;
		}
		else if (!outputStyle.compare("file"))
		{
			s1->setOutputmode(Simulation::kOutputmode::FILE);
			break;
		}
		else
		{
			cout << "Sorry, input not recognized." << endl;
		}
	}
	int genNum = 0;
	switch (s1->getOutputmode())
	{
	case Simulation::PAUSED:
		while (!s1->checkIsStable())
		{
			int height = s1->getPregen().getHeight();
			int length = s1->getPregen().getLength();
			cout << genNum << endl;
			s1->playGame(height, length);
			++genNum;
			//wait for 1 second
			sleep_for(seconds(1));
		}
		break;
	case Simulation::ENTER:
		while (!s1->checkIsStable())
		{
			int height = s1->getPregen().getHeight();
			int length = s1->getPregen().getLength();
			cout << genNum << endl;
			s1->playGame(height, length);
			++genNum;
			//press enter
			cin.get();
		}
		break;
	case Simulation::FILE:

		cout << "What is the name of the file you would like to output to?";
		//print to file
		getline(cin, outputFileName);
		ofstream outputStream(outputFileName);
		while (!s1->checkIsStable())
		{
			int height = s1->getPregen().getHeight();
			int length = s1->getPregen().getLength();
			outputStream << genNum << '\n';
			s1->playGame(outputStream, height, length);
			++genNum;
		}

	}
	cout << "Thank you for playing the Game of Life!" << endl;
	return 0;
}
/*
a. getInt
b. @return - an int value that represents the checked int value passed in by the user.
c. @param - none
d. No exceptions thrown.
*/
int getInt()
{
	while (true)
	{
		int x;
		cin >> x;
		if (cin.fail() || x <= 0)
		{
			cout << "Please enter an integer value and be sure that it is greater than 0." << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			cin.ignore(32767, '\n');
			return x;
		}
	}
}
/*
a. getDensity
b. @return - a double value that represents the checked double value that the user passed in.
c. @param - none
d. No exceptions thrown.
*/
double getDensity()
{
	while (true)
	{
		double x;
		cin >> x;
		if (cin.fail() || x > 1)
		{
			cout << "Please enter a double value that is between 0 and 1." << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			cin.ignore(32767, '\n');
			return x;
		}
	}
}
/*
a. fileExists
b. @return - a boolean representing whether or not the file that the user passed in exists.
c. @param - a string value that represents the filename that the user passed in.
d. No exceptions thrown.
*/
bool fileExists(string filename)
{
	ifstream f(filename.c_str());
	return f.good();
}
