#include <iostream>
using namespace std;


int rec(unsigned long long x){
	cout<<x<<endl;
	x=rec(x*2);
}


int main(){
	rec(2);
	return 0;
}
