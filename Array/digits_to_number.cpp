#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int num;
    cout<<"how many numbers of digit : "<<endl;
    cin>>num;
    int *arr =  new int[num];
    int i,j;
    for(i=0;i<num;i++){
       cin>>arr[i];
    }
    int num1=0;
    for(i = num-1,j = 0;i>=0&&j<num;i--,j++){
       num1 += arr[j] * pow(10,(i));
    }
    cout<<num1<<endl;
}
