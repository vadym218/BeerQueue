#include "Human.h"
#include <random>
#include <time.h>

using namespace std;

Human::Human(string name, string pronoun)
{
	this->name = name;
	this->pronoun = pronoun;
}

string Human::get_upper_name()
{
	string upper_name;
	for (int i = 0; i < name.length(); i++)
	{
		upper_name += toupper(name[i]);
	}
	return upper_name;
}

string Human::get_capitalized_pronoun() {
	string capitalized_pronoun;
	capitalized_pronoun += toupper(pronoun[0]);
	capitalized_pronoun += pronoun.substr(1, -1);
	return capitalized_pronoun;
}

string Human::introduce()
{
	return "My name is " + name;
}

string Human::drink()
{
	times_drank_today++;

	srand(time(0));
	if (times_drank_today >= rand() % 10)
		is_drunk = true;

	string message = name + " drinks...";
	if (is_drunk)
		message += ' ' + get_capitalized_pronoun() + " is drunk";
	
	return message;
}

bool Human::get_is_drunk()
{
	return is_drunk;
}
