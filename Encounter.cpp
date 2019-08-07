#include "Encounter.h"

using namespace std;

Encounter::Encounter()
{
	num_enemies = NULL;
	total_xp = NULL;
	
	createEncounterEasy();
	createEncounterMedium();
	createEncounterHard();
	createEncounterDeadly();
}

Encounter::~Encounter()
{
	enc_enemies.clear();
	possible_enc_enemies.clear();
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

void Encounter::resetNumEnemies()
{
	num_enemies = 0;
}

void Encounter::addTotalXP(int x)
{
	total_xp += x;
}

int Encounter::getTotalXP()
{
	return total_xp;
}

void Encounter::resetXP()
{
	total_xp = 0;
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

void Encounter::createEncounterMedium()
{
	encounter_medium[0] = {50};
	encounter_medium[1] = {100};
	encounter_medium[2] = {150};
	encounter_medium[3] = {250};
	encounter_medium[4] = {500};
	encounter_medium[5] = {600};
	encounter_medium[6] = {700};
	encounter_medium[7] = {900};
	encounter_medium[8] = {1100};
	encounter_medium[9] = {1200};
}

void Encounter::createEncounterHard()
{
	encounter_hard[0] = {75};
	encounter_hard[1] = {150};
	encounter_hard[2] = {225};
	encounter_hard[3] = {375};
	encounter_hard[4] = {750};
	encounter_hard[5] = {900};
	encounter_hard[6] = {1050};
	encounter_hard[7] = {1350};
	encounter_hard[8] = {1650};
	encounter_hard[9] = {1800};
}

void Encounter::createEncounterDeadly()
{
	encounter_deadly[0] = {100};
	encounter_deadly[1] = {200};
	encounter_deadly[2] = {300};
	encounter_deadly[3] = {500};
	encounter_deadly[4] = {1000};
	encounter_deadly[5] = {1200};
	encounter_deadly[6] = {1400};
	encounter_deadly[7] = {1800};
	encounter_deadly[8] = {2200};
	encounter_deadly[9] = {2400};
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

int Encounter::getEncounterXP(int diff, int num_char, int index)
{
	int max_xp;
	int encounter_xp_person;
	
	if(diff == 0)
	{
		encounter_xp_person = encounter_easy[index];
	}
	else if(diff == 1)
	{
		encounter_xp_person = encounter_medium[index];
	}
	else if(diff == 2)
	{
		encounter_xp_person = encounter_hard[index];
	}
	else if(diff == 3)
	{
		encounter_xp_person = encounter_deadly[index];
	}
	
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

void Encounter::clearAllEnemies()
{
	enc_enemies.clear();
	possible_enc_enemies.clear();
	resetNumEnemies();
	resetXP();
}