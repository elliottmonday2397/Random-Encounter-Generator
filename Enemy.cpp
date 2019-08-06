#include "Enemy.h"

using namespace std;

Enemy::Enemy()
{
	name = "NULL";				//string
	challenge_rating = "NULL";	//string
	experience = NULL;			//int
	type = "NULL";				//string
	reference_book = "NULL";	//string
	reference_page = "NULL";	//string
}

Enemy::~Enemy()
{
	delete enemy;
}

string Enemy::getEnemyName()
{
	return name;
}
void Enemy::setEnemyName(string &n)
{
	name = n;
}

string Enemy::getChallengeRating()
{
	return challenge_rating;
}
void Enemy::setChallengeRating(string &cr)
{
	challenge_rating = cr;
}

int Enemy::getExperience()
{
	return experience;
}
void Enemy::setExperience(int &xp)
{
	experience = xp;
}

string Enemy::getType()
{
	return type;
}
void Enemy::setType(string &t)
{
	type = t;
}

string Enemy::getReferenceBook()
{
	return reference_book;
}
void Enemy::setReferenceBook(string &ref_book)
{
	reference_book = ref_book;
}

string Enemy::getReferencePage()
{
	return reference_page;
}
void Enemy::setReferencePage(string &ref_page)
{
	reference_page = ref_page;
}
