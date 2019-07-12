#include<iostream>
using namespace std;
int main(){
   int arr[10] = {10,9,8,7,6,5,4,3,2,1};
   int min,min1,i;
   min = arr[0];
   for(i = 0;i<10;i++){
       if(arr[i]<min){
          min = arr[i];
       }
   }
   cout<<min<<endl;
   min1 = arr[1];
   for(i = 0;i<10;i++){
      if(arr[i] != min){
         if(arr[i]<min1){
            min1 = arr[i];
         }
      }
   }
   cout<<min1<<endl;
}
