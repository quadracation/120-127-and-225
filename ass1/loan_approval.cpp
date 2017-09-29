#include <iostream>
#include "loan_approval"
#include <fstream>
using namespace std;

void main(){
	ifstream myFile;
	myFile.open("commands.txt");
	string par_name; int par_edu; int par_expe; int par_amount; int* par_profits[30]; string str_throw;
	int app_number=0;
	while(myFile.isopen()){
		myFile>>par_name>>par_edu>>par_expe>>par_amount;
		int i=0;
		while(i<30 && getline(myFile,str_throw)){
			myFile>>par_profits[i];
			i++;
		}
		application::save_application(par_name,par_edu,par_expe,par_amount,par_profits[],app_number);
		app_number++;
	}
}