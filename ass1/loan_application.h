#include <iostream>
#include <cstring>


class application{
	std::string applicant_full_name;
	int years_of_relevant_education;
	int years_of_relevant_experience;
	int loan_amount;
	int* estimated_yearly_profits;
	string decision_date;
	int budget;
	int tracker;
public:
	application();
	~application();
	save_application(std::string applicant_full_name, int years_of_relevant_education, 
		int years_of_relevant_experience, int loan_amount, int* estimated_yearly_profits,int tracker);
	make_decision(std::string decision_date , int budget);	
	print();


}