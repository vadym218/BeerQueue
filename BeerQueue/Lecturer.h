#pragma once
#include "Human.h"

class Lecturer : public Human
{
	std::string subject;
	int days_drank_ago;
public:
	Lecturer(std::string name, std::string pronoun, std::string subject, int days_drank_ago);
	std::string introduce() override;
	std::string drink() override;
};
