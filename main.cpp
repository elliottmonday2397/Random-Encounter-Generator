#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "Enemy.h"
#include "Encounter.h"

using namespace std;

/*
Input: Const char.
Output: Integer.
Result: Converts const char to integer.
*/
int stoi(const char *item)
{
	return static_cast<int>(atof(item));   
}

/*
Input: Vector of Enemy objects and const char for filename.
Output: None.
Result: Reads in data for Enemy object creation, creates the Enemy objects, and places them on the vector.
*/
void readEntries(vector<Enemy*> &e, const char *filename)
{
	fstream inFile(filename);
	string buffer;
	
	getline(inFile, buffer);
	
	while(!inFile.eof())
	{
		Enemy *enemy = new Enemy();
	
		enemy->setEnemyName(buffer);
		
		getline(inFile, buffer);
		enemy->setChallengeRating(buffer);
		
		getline(inFile, buffer);
		string exp = buffer;
		int xp = stoi(exp.c_str());
		enemy->setExperience(xp);
		
		getline(inFile, buffer);
		enemy->setType(buffer);
		
		getline(inFile, buffer);
		enemy->setReferenceBook(buffer);
		
		getline(inFile, buffer);
		enemy->setReferencePage(buffer);
		
		e.push_back(enemy);
		
		getline(inFile, buffer);
	}
}

int main(int argc, const char *argv[])
{	
	vector<Enemy*> enemies;
	
	readEntries(enemies, argv[1]);
	
	/* for(size_t i = 0; i < enemies.size(); i++)
	{		

		Enemy* enemy = enemies[i];
		
		string entered_name = enemy->getEnemyName();
		string entered_cr = enemy->getChallengeRating();
		int entered_xp = enemy->getExperience();
		string entered_type = enemy->getType();
		string entered_ref_book = enemy->getReferenceBook();
		string entered_ref_page = enemy->getReferencePage();
		
		cout << entered_name << " " << entered_cr << " " << entered_xp << " " << entered_ref_book << endl;
	} */
	
	Encounter* encounter = new Encounter();
	
	bool make_another_encounter = true;
	while(make_another_encounter == true)
	{
		int num_party_members;
		int character_level;
		char difficulty;
		int encounter_max_xp;
	
		cout << "Enter number of party members: ";
		cin >> num_party_members;
		cout << endl;
		
		cout << "Enter the level of the party (1-10): ";
		cin >> character_level;
		cout << endl;
		
		bool accepted = false;
		while(accepted == false)
		{
			cout << "Enter the difficulty of the encounter, (E)asy, (M)edium, (H)ard, (D)eadly: ";
			cin >> difficulty;
			cout << endl;
			
			if((difficulty == 'e') || (difficulty == 'E'))
			{
				encounter_max_xp = encounter->getEncounterXP(0, num_party_members, character_level - 1);
				accepted = true;
			}
			else if((difficulty == 'm') || (difficulty == 'M'))
			{
				encounter_max_xp = encounter->getEncounterXP(1, num_party_members, character_level - 1);
				accepted = true;
			}
			else if((difficulty == 'h') || (difficulty == 'H'))
			{
				encounter_max_xp = encounter->getEncounterXP(2, num_party_members, character_level - 1);
				accepted = true;
			}
			else if((difficulty == 'd') || (difficulty == 'D'))
			{
				encounter_max_xp = encounter->getEncounterXP(3, num_party_members, character_level - 1);
				accepted = true;
			}
			else
			{
				cout << "Invalid selection. Try again." << endl;
			}
		}
		
		encounter->findAppropriateEnemies(enemies, encounter_max_xp);
		
		int size_of_possible = encounter->sizeOfPossibleEnemies();
		
		srand(time(NULL));
		
		for(size_t i = 0; i < size_of_possible; i++) //the larger the pool the more times it runs, currently is limited, to thoroughly test increase to a insanely large number to show it will cut off when it is supposed to.
		{
			int random_num = rand() % size_of_possible;
			Enemy* e = encounter->getPossibleEnemy(random_num);
			
			int temp_xp = e->getExperience();
			
			if(encounter_max_xp < temp_xp)
				break;
			
			encounter->addEnemy(e);
			encounter_max_xp -= temp_xp;
		}
		
		cout << "Enemies for the encounter: " << endl;
		
		for(size_t i = 0; i < encounter->getNumEnemies(); i++)
		{
			Enemy* enc_test = encounter->getEnemy(i);
			
			string enc_entered_name = enc_test->getEnemyName();
			
			cout << enc_entered_name << endl;
		}
		
		int enc_total_xp = encounter->getTotalXP();
		int enc_num_enemies = encounter->getNumEnemies();
		cout << endl << "Encounter total xp: " << enc_total_xp << endl << "Total number of enemies: " << enc_num_enemies << endl;
		
		char cont;
		cout << "Would you like to make another encounter? (Y)es or (N)o: " << endl;
		cin >> cont;
		
		if((cont == 'y') || (cont == 'Y'))
		{
			make_another_encounter = true;
			encounter->clearAllEnemies();
		}
		else if((cont == 'n') || (cont == 'N'))
		{
			make_another_encounter = false;
		}
		else
		{
			cout << "Invalid input. Try again." << endl;
		}
	}
	
	return 0;
}