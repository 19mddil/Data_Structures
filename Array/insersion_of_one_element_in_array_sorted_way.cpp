#include<iostream>
using namespace std;
int main(){
   int n,j,i;
   cout<<"size: ";
   cin>>n;
   cout<<endl;
   int arr[n];
   cout<<"enter elements:";
   for(i=0;i<n;i++){
      cin>>arr[i];
   }
   cout<<endl;
   int num;
   cout<<"num :";
   cin>>num;
   cout<<endl;
   for(i=0;i<n;i++){
      if(num<arr[i]){
          for (j = n -1;j>=i;j--){
             arr[j+1] = arr[j];
          }
          arr[i] = num;
          break;
      }
   }
   n += 1;
   for(i=0;i<n;i++){
      cout<<arr[i]<<' ';
   }
   cout<<endl;
}
