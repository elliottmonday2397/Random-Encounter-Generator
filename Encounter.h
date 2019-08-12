#ifndef ENCOUNTERCALC_H
#define ENCOUNTERCALC_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Enemy.h"

class Encounter
{
	private:
		Encounter* encounter;
		vector<Enemy*> possible_enc_enemies; //List of all possible enemies to be fought based off certain conditions.
		vector<Enemy*> enc_enemies;
		
		int num_enemies;
		int total_xp;
		
		int encounter_easy[10]; //Array that holds the experience point value for encounters for levels 1 - 10 for easy encounters.
		int encounter_medium[10]; //Array for experience for medium encounters.
		int encounter_hard[10]; //Array for experience for hard encounters.
		int encounter_deadly[10]; //Array for experience for deadly encounters.
		
		/*
		Input: None.
		Output: None.
		Result: Adds enemies to the enc_enemies.
		*/
		void addNumEnemies();
		
		/*
		Input: None.
		Output: None.
		Result: Zeroes num_enemies.
		*/
		void resetNumEnemies();
		
		/*
		Input: Integer.
		Output: None.
		Result: Adds the amount for the creature to the total experience of the encounter.
		*/
		void addTotalXP(int x);
		
		/*
		Input: None.
		Output: None.
		Result: Zeroes total_xp.
		*/
		void resetXP();
		
		/*
		Input: None.
		Output: None.
		Result: Initializes the easy encounter array of experience point values.
		*/
		void createEncounterEasy();
		
		/*
		Input: None.
		Output: None.
		Result: Initializes the medium encounter array of experience point values.
		*/
		void createEncounterMedium();
		
		/*
		Input: None.
		Output: None.
		Result: Initializes the hard encounter array of experience point values.
		*/
		void createEncounterHard();
		
		/*
		Input: None.
		Output: None.
		Result: Initializes the deadly encounter array of experience point values.
		*/
		void createEncounterDeadly();
		
		/*
		Input: Enemy object.
		Output: None.
		Result: Adds an enemy to the list of possible enemies for the encounter.
		*/
		void addPossibleEnemy(Enemy* e);
		
	public:
		Encounter();
		~Encounter();
		
		/*
		Input: Enemy object.
		Output: None.
		Result: Gets the enemies experience value and sends that to private function addTotalXP().
		*/
		void addEncounterExperience(Enemy* e);
		
		/*
		Input: None.
		Output: Integer.
		Result: Returns the number of enemies in the encounter.
		*/
		int getNumEnemies();
		/*
		Input: None.
		Output: Integer.
		Result: Returns the total amount of experience for the encounter.
		*/
		int getTotalXP();
		
		/*
		Input: Integer for number of characters and an integer for the character levels.
		Output: Integer.
		Result: Returns the total amount of experience points for the combat.
		*/
		int getEncounterXP(int dif, int num_char, int index);
		
		/*
		Input: Integer for an index location.
		Output: Enemy object.
		Result: Returns and enemy from the list of possible enemies.
		*/
		Enemy* getPossibleEnemy(int x);
		
		/*
		Input: Enemy object.
		Output: None.
		Result: Adds an enemy to the actual encounter.
		*/
		void addEnemy(Enemy* e);
		
		/*
		Input: Integer for an index location.
		Output: Enemy object.
		Result: Returns an Enemy object from the actual encounter.
		*/
		Enemy* getEnemy(int x);
		
		/*
		Input: Vector of Enemy objects and an integer for the max experience points for an encounter.
		Output: None.
		Result: Goes through the full list of enemies to find enemies suitable for the encounter.
		*/
		void findAppropriateEnemies(vector<Enemy*> &e, int m_x_p);
		
		/*
		Input: None.
		Output: Integer
		Result: Returns the size of the vector of possible enemies.
		*/
		int sizeOfPossibleEnemies();
		
		/*
		Input: None.
		Output: None.
		Result: Clears the vector of enemies for reuse.
		*/
		void clearAllEnemies();
};

#endif