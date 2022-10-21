#include "Student.h"

using namespace std;

Student::Student(string name, string pronoun, int student_id_number, int days_student_id_expires) : Human(name, pronoun)
{
	this->student_id_number = student_id_number;
	this->days_student_id_expires = days_student_id_expires;
}

string Student::introduce()
{
	if (times_drank_today > 0)
	{
		return "Don't you remember me? I'm " + name + ". Give me the " + to_string(times_drank_today + 1) + " beer!";
	}

	return Human::introduce() + ", I am a fully grown Human with student id #" + to_string(student_id_number) + ". One beer, please!";
}

string Student::drink()
{
	string message = "\n* " + Human::drink();

	if (!is_drunk)
	{
		message += ' ';

		if (days_student_id_expires > 0)
		{
			message += "The student id ";
			if (days_student_id_expires > 14)
				message += "will be valid for";
			else
				message += "expires in";
			message += " " + to_string(days_student_id_expires) + " day(s), ";
			if (days_student_id_expires > 14)
				message += pronoun + " gets";
			else
				message += "but " + pronoun + " managed to get";
			message += " a 20% discount. " + get_capitalized_pronoun() + " is absolutely happy";
		}
		else
		{
			message += "But a coleague intervenes half the way! The student id is expired and " + pronoun + " can't afford a full cup without a student discount";
		}
	}

	return message + " *";
}
