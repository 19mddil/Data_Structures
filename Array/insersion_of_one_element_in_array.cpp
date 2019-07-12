#include<iostream>
using namespace std;
int main(){
   int n,pos,i;
   cout<<"size: ";
   cin>>n;
   cout<<endl;
   int arr[10];
   cout<<"enter elements:";
   for(i=0;i<n;i++){
      cin>>arr[i];
   }
   cout<<endl;
   int num;
   cout<<"num & pos:";
   cin>>num>>pos;
   cout<<endl;
   for(i=n-1;i>=(pos - 1);i--){
       arr[i+1] = arr[i];
   }
   arr[pos-1] = num;
   n += 1;
   for(i=0;i<n;i++){
      cout<<arr[i]<<' ';
   }
   cout<<endl;

}
