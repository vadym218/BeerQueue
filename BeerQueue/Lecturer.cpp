#include "Lecturer.h"
#include <random>
#include <time.h>
#include <iostream>

using namespace std;

string drinks[5]{
	"Absinthe",
	"Gin and tonic",
	"Vesper Martini",
	"Balm",
	"Whiskey"
};

Lecturer::Lecturer(string name, string pronoun, string subject, int days_drank_ago) : Human(name, pronoun)
{
	this->subject = subject;
	this->days_drank_ago = days_drank_ago;
}

string Lecturer::introduce() {
	string message = Human::introduce();

	if (days_drank_ago > 0) {
		message += " and I'm a Lecturer. I teach " + subject + ". I haven't drank for " + to_string(days_drank_ago) + " day(s)!";
	}
	else
	{
		message += ", but you should have already known me - I've drank ";
		if (times_drank_today > 1)
			message += to_string(times_drank_today) + " times ";
		message += "today...";
	}

	return message;
}

string Lecturer::drink() {
	srand(time(0));
	int drink_index = rand() % 5;
	string message = drinks[drink_index] + ", please!\n";

	if (drink_index == 2)
		message += "BARTENDER: Hm... Did you say your real name?\n";

	message += "* " + Human::drink();

	if (!is_drunk)
		message += ' ' +
		((days_drank_ago > 0) ?
			"However, " + pronoun + " doesn't feel satisfied" :
			pronoun + " is one step closer to the edge");

	days_drank_ago = 0;
	return message + " *";
}
