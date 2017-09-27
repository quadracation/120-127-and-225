#include <iostream>
#include <fstream>
#include "loan_application.h"
#include <cstdlib>
#include <cstring>

using namespace std;

application::application(){
	application::name= new string();
	application::educ= new int();
	application::expe= new int();
	application::amount= new int();
}

application::~application(){
}

application::save_application(string applicant_full_name, int years_of_relevant_education, 
		int years_of_relevant_experience, int loan_amount, int* estimated_yearly_profits,int tracker){

	


}