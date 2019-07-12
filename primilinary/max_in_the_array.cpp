#include<iostream>
using namespace std;
int main(){
    int loc,max,k;
    int data[10] = { 5,3,4,8,9,2,10,6,1,2};
    int N = sizeof(data)/sizeof(data[0]);
    loc = k = 0;
    max = data[0];
    while(k<N){
        if(data[k]>max){
            max = data[k];
            loc = k;
        }
        k++;
    }
    cout<<loc<<' '<<max<<endl;
}
