#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Enemy
{
	private:
		Enemy* enemy;
		
		string name;
		string challenge_rating;
		int experience;
		string type;
		string reference_book;
		string reference_page;
		
	public:
		//Constructor
		Enemy();
		//Destructor
		~Enemy();
		
		/*
		Input: None.
		Output: String
		Result: Returns the Enemy object's name.
		*/
		string getEnemyName();
		/*
		Input: String.
		Output: None.
		Result: Sets the Enemy objects's name.
		*/
		void setEnemyName(string &n);
		
		/*
		Input: None.
		Output: Integer
		Result: Returns the Enemy object's challenge rating.
		*/
		string getChallengeRating();
		/*
		Input: Integer.
		Output: None.
		Result: Sets the Enemy object's challenge rating.
		*/
		void setChallengeRating(string &cr);
		
		/*
		Input: None.
		Output: Integer.
		Result: Returns the Enemy object's experience points value.
		*/
		int getExperience();
		/*
		Input: Integer.
		Output: None.
		Result: Sets the Enemy object's experience points value.
		*/
		void setExperience(int &xp);
		
		/*
		Input: None.
		Output: String.
		Result: Returns the Enemy object's type.
		*/
		string getType();
		/*
		Input: String.
		Output: None.
		Result: Sets the Enemy object's type.
		*/
		void setType(string &t);
		
		/*
		Input: None.
		Output: String.
		Result: Returns the Enemy object's reference book.
		*/
		string getReferenceBook();
		/*
		Input: String.
		Output: None.
		Result: Sets the Enemy object's reference book.
		*/
		void setReferenceBook(string &ref_book);
		
		/*
		Input: None.
		Output: String.
		Result: Returns the Enemy object's reference book page number.
		*/
		string getReferencePage();
		/*
		Input: String.
		Output: None.
		Result: Sets the Enemy object's reference book page number.
		*/
		void setReferencePage(string &ref_page);
};

#endif