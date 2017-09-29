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
	application::priority= new int();
	application::s_priority = new int();
	application::dname = new string();
	application::d_amount = new int();
	application::a_name = new string();
	application::a_amount = new int();
	application::tracker=0;

}

application::~application(){
}

void application::save_application(string applicant_full_name, int years_of_relevant_education, 
		int years_of_relevant_experience, int loan_amount, int* estimated_yearly_profits[30], int app_num){
	int num = 0;
	name[tracker]= applicant_full_name;
	educ[tracker]= years_of_relevant_education;
	expe[tracker]= years_of_relevant_experience;
	amount[tracker]= loan_amount;
	for (int i =0; i<30; i++ )
		if(estimated_yearly_profits[i] != 0)
			num = num + ((1/(i+1)) * *estimated_yearly_profits[i]);
	priority[app_num] = num;
	s_priority[app_num] = num;
	tracker++;



};

void application::make_decision(string decision_date, int budget)
{
	int temp;
	int j; 
	int k;
	for ( j = 1 ; j<5000 ; j++)
		temp = s_priority[j];
		for ( k = j-1; (k>=0) && (s_priority[k] < temp); k--)
			s_priority[k+1]= s_priority[k];
		s_priority[k+1]=temp;


	for (int i =0; i<5000; i++)
		if(educ[i]+expe[i] < 10)
			for (int k =0; k<=i ; k++)
				if (&dname[k]==0 and &d_amount[k]==0)
					dname[k] = name[i],
					d_amount[k] = amount[i];

	for (int i =0; i<5000; i++)
		for (int k=0; k<5000; k++)
			if (s_priority[i] == priority[k])
				for (int j =0; j<=k; j++)
					if (&a_name[j]==0 and &a_amount[j]==0)
						a_name[j] = name[k],
						a_amount[j] = amount[k];




}

void application::print(){
	int i=0;
	while(&a_name[i] and &a_amount[i]!=NULL){
		cout<<"approved"<<a_name[i]<<endl;
		i++;
	}
}
