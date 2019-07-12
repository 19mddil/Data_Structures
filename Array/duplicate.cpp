#include<iostream>
#include<vector>
using namespace std;
int main(){
   vector<int> v;
   int k,l;
   int flag = 0;
   int arr[10] = {1,2,3,1,2,7,7,1,10,1};
   int i,j;
   for( i = 0 ; i<10 ; i++ ){
      for(j = i+1 ; j<10 ; j++ ){
          if( arr[i] == arr[j] && i != j){
             flag = 1;
             cout<<i<<" "<<j<<endl;
          }
      }
   }

   if(!flag){
      cout<<"no duplicate found"<<endl;
   }
}
