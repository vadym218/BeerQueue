#pragma once
#include <string>

class Human
{
protected:
	std::string name;
	std::string pronoun;
	int times_drank_today{ 0 };
	bool is_drunk{ false };
public:
	Human(std::string name, std::string pronoun);
	std::string get_upper_name();
	std::string get_capitalized_pronoun();
	virtual std::string introduce();
	virtual std::string drink();
	bool get_is_drunk();
};

