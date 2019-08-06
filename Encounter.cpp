#include "Encounter.h"

using namespace std;

Encounter::Encounter()
{
	num_enemies = NULL;
	total_xp = NULL;
	
	createEncounterEasy();
}

Encounter::~Encounter()
{
	delete encounter;
}

void Encounter::addNumEnemies()
{
	num_enemies += 1;
}

int Encounter::getNumEnemies()
{
	return num_enemies;
}

void Encounter::addTotalXP(int x)
{
	total_xp += x;
}

int Encounter::getTotalXP()
{
	return total_xp;
}

void Encounter::createEncounterEasy()
{
	encounter_easy[0] = {25};
	encounter_easy[1] = {50};
	encounter_easy[2] = {75};
	encounter_easy[3] = {125};
	encounter_easy[4] = {250};
	encounter_easy[5] = {300};
	encounter_easy[6] = {350};
	encounter_easy[7] = {450};
	encounter_easy[8] = {550};
	encounter_easy[9] = {600};
}

void Encounter::addPossibleEnemy(Enemy* e)
{
	possible_enc_enemies.push_back(e);
}

Enemy* Encounter::getPossibleEnemy(int x)
{
	return possible_enc_enemies[x];
}

void Encounter::addEnemy(Enemy* e)
{
	addNumEnemies();
	addEncounterExperience(e);
	enc_enemies.push_back(e);
}

Enemy* Encounter::getEnemy(int x)
{
	return enc_enemies[x];
}

void Encounter::addEncounterExperience(Enemy* e)
{
	int xp = e->getExperience();
	addTotalXP(xp);
}

int Encounter::getEncounterEasy(int num_char, int index)
{
	int max_xp;
	int encounter_xp_person = encounter_easy[index];
	max_xp = num_char * encounter_xp_person;
	
	return max_xp;
}

void Encounter::findAppropriateEnemies(vector<Enemy*> &e, int m_x_p)
{
	for(size_t i = 0; i < e.size(); i++)
	{
		int temp_x_p = e[i]->getExperience();
		
		if(temp_x_p <= m_x_p)
		{
			addPossibleEnemy(e[i]);
		}
	}
}

int Encounter::sizeOfPossibleEnemies()
	{
		return possible_enc_enemies.size();
	}