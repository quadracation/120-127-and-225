#include <iostream>
#include <fstream>
#include "loan_application.h"
#include <cstdlib>
#include <cstring>

using namespace std;

application::application(): std::string name[], int edu[], int exp[], int amount[], int earning[];

application::~application(){
}

application::save_application(std::string applicant_full_name, int years_of_relevant_education, 
		int years_of_relevant_experience, int loan_amount, int* estimated_yearly_profits,int tracker){

	name[tracker]=applicant_full_name;
	edu[tracker]=years_of_relevant_education;
	exp[tracker]=years_of_relevant_experience;
	amount[tracker]=loan_amount;


}