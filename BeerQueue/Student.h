#pragma once
#include "Human.h"

class Student : public Human
{
protected:
	int student_id_number;
	int days_student_id_expires;
public:
	Student(std::string name, std::string pronoun, int student_id_number, int days_student_id_expires);
	std::string introduce() override;
	std::string drink() override;
};

