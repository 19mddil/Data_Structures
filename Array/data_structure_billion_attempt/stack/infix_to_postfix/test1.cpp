#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>
using namespace std;
int main(){
	string x = "i eat rice";
	string y = " 3nd i have a cat";
	cout<<x.length()<<endl;
	x = x + y[0]+y[1] ;
	x[12] = '\0';
	cout<<x.length()<<endl;
	cout<<x<<endl;
	cout<<boolalpha<<(isdigit(y[1]))<<endl;
}
