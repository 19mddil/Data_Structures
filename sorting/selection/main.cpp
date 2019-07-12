#include<iostream>
using namespace std;
void selection(int arr[],int n){
    int i;
    int j;
    int k;
    int key;
    int min;
    for(i = 0;i<n;i++){
        j = i+1;
        min = arr[j];

            while(j<n&&arr[j]<=min){
               min = arr[j];
               j++;
            }


        cout<<i<<' '<<j-1<<endl;
        swap(arr[i],arr[j]);
    }
}
void show(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
int main(){
    int arr[] = {5,4,1,2,3};
    selection(arr,5);
    show(arr,5);
}
