#include <iostream>
#include <cstring>



class application{
	std::string applicant_full_name;
	int years_of_relevant_education;
	int years_of_relevant_experience;
	int loan_amount;
	int* estimated_yearly_profits;
	std::string decision_date;
	int budget;
	std::string* name;
	int* educ;
	int* expe;
	int* amount;
	int* priority;
	int* s_priority;
	std::string* dname;
	std::string* a_name;
	int* d_amount;
	int* a_amount;
	int tracker;

	
public:
	application();
	~application();
	void save_application(const std::string applicant_full_name, int years_of_relevant_education, 
		int years_of_relevant_experience, int loan_amount, int* estimated_yearly_profits[30], int app_num);
	void make_decision(const std::string decision_date , int budget);	
	void print();
	bool operator==(const application & rhs);
};