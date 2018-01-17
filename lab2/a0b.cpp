#include "basic_int_stack.cpp"
#include <iostream>

using namespace std;

int main(){
	cout<<"Zhi Bin Cao"<<endl<<"zbcao"<<endl<<"301302662"<<endl;
	Basic_int_stack stack;
	int number;
	cin>>number;
	while(number>=0){
		stack.push(number);
		cin>>number;


	}
	int n=stack.size();
	cout<<stack.size()<<endl;
	int total=0;
	int arr[10];
	for (int i=0;i<n;i++){
		arr[i]=stack.pop();
		total=total+arr[i];
	}
	cout<<total<<endl;
	for (int k=0;k<n;k++){
		cout<<arr[k]<<endl;
	}
	cout<<"goodbye"<<endl;

}


