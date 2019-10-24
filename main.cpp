#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "Enemy.h"
#include "Encounter.h"
#include "util.h"

using namespace std;
using namespace utility;

void printMenu()
{
	cout << "Please choose one of the following options: " << endl;
	cout << "\t1. Create an Encounter" << endl;
	cout << "\t2. Search for an Enemy" << endl;
	cout << "\t3. Add an Enemy" << endl;
	cout << "\t4. Quit" << endl;
}

int menu(vector<Enemy*> &e, const char *file)
{
	char choice;
	bool quit = false;
	
	cout << "Welcome to Avgrovac's Random Encounter Generator" << endl;
	printMenu();
	
	while(quit == false)
	{
		cin >> choice;
		cout << endl;
		
		if(choice == '1')
		{
			makeEncounter(e);
		}
		else if(choice == '2')
		{
			cout << "This functionality is currently not in." << endl;
		}
		else if(choice == '3')
		{
			addEnemyToPool(file,e);
		}
		else if(choice == '4')
		{
			quit = true;
		}
		else
		{
			cout << "Invalid selection, please try again." << endl;
			cout << endl;
		}
	
		if(quit == false)
		{
			printMenu();
		}
	}
}

int main(int argc, const char *argv[])
{	
	vector<Enemy*> enemies;
	
	const char* file = argv[1];
	
	readEntries(enemies, file);
	
	menu(enemies, file);
	
	return 0;
}