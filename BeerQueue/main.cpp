#include "Student.h"
#include "Lecturer.h"
#include <iostream>
#include <windows.h>
#include <random>
#include <time.h>

using namespace std;

string intro_strings[6] =
{
	"\n",
	"The party begins",
	".",
	".",
	".\n\n",
	"BARTENDER: Get in line and make your orders!\n\n"
};

const int ACTORS_NUMBER = 10;
Human* actors[ACTORS_NUMBER] =
{
	new Lecturer("Dariusz", "he", "OOP", 365),
	new Lecturer("Anthony", "he", "Artificial Intelligence", 1),
	new Lecturer("Claire", "she", "English", 14),
	new Lecturer("John", "he", "History", 25),
	new Lecturer("Margaret", "she", "Arts", 5),
	new Student("Vadym", "he", 155610, 218),
	new Student("Max", "she", 121640, 90),
	new Student("Max", "he", 041450, 0),
	new Student("Theodore", "he", 216599, 7),
	new Student("Olga", "she", 156424, 3)
};

string loss_strings[8] =
{
	"\n* Everyone is drunk. Even bartender decides to join them. All further drinks are free *\n\n",
	".",
	".",
	".\n\n",
	"### 06:00 ###\n",
	"### --:-- ###\n",
	"### 06:01 ###\n\n",
};

const int DRINK_COST = 4;
const int LOSS_MULTIPLIER = 8;

int main()
{
	cout
		<< "   *^^*^^*^^^*^^*\n"
		<< "  #################\n"
		<< " ###    * .  * .######\n"
		<< " ## . *          ##  ##\n"
		<< " ## BEER PLEASE  ##   ##\n"
		<< " ##   .      * . ##   ##\n"
		<< " ##      * .  .  ##   ##\n"
		<< " ##    .         ##  ##\n"
		<< " ###  .     .   #####\n"
		<< "  ###############\n\n";

	int drinks_number;
	cout
		<< "We have " + to_string(ACTORS_NUMBER) + " customers and you have 2 objectives:\n"
		<< " - earn as much as possible\n"
		<< " - try not to make them all drunk\n"
		<< "Our customers are capable of drinking from 1 to 10 drinks\n"
		<< "So... How many drinks should we serve this friday evening? ";
	cin >> drinks_number;

	for (int i = 0; i < 6; i++)
	{
		cout << intro_strings[i];
		Sleep(750);
	}

	int drunk_people_number{ 0 }, paid_drinks_number{ 0 };
	for (int i = 0; i < drinks_number; i++) {
		paid_drinks_number++;

		srand(time(0));
		int actor_index, random_number;
		do
		{
			random_number = rand();
			actor_index = random_number % ACTORS_NUMBER;
			srand(random_number);
		} while (actors[actor_index]->get_is_drunk());

		string upper_name = actors[actor_index]->get_upper_name();
		string introduce_message = actors[actor_index]->introduce();
		string drink_message = actors[actor_index]->drink();

		cin.get();
		cout << '[' + to_string(i + 1) + "] " + upper_name + ": " + introduce_message + ' ' + drink_message + "\n";

		if (i == 0)
			cout << "\n? use Enter serve next customer ?\n";

		Sleep(1500);

		if (actors[actor_index]->get_is_drunk())
			drunk_people_number++;

		if (drunk_people_number == ACTORS_NUMBER)
			break;
	}

	int money_earned = paid_drinks_number * DRINK_COST;
	if (drunk_people_number != ACTORS_NUMBER)
	{
		cout
			<< "\n* The pub is closed *\n\n"
			<< "YOU EARNED " + to_string(money_earned) + "$\n";
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			cout << loss_strings[i];
			Sleep(i == 0 ? 1500 : 750);
		}

		srand(time(0));
		float random_multiplier = static_cast<float>(rand() % 41 + 80) / 100; // 80-120%
		int money_lost = ACTORS_NUMBER * DRINK_COST * LOSS_MULTIPLIER * random_multiplier - money_earned;
		cout << "YOU LOST " + to_string(money_lost) + "$\n";
	}


	return 0;
}
