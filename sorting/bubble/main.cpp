/**No matter what case best to worst its always like you n2**/
#include<iostream>
using namespace std;
void bubble(int arr[],int size){
    int i,j;
    for(i = 0;i<size;i++){
        for(j = 1;j<(size -i);j++){
            if(arr[j]<arr[j-1]){
                    swap(arr[j-1],arr[j]);
            }
        }
    }
}
void show(int arr[],int size){
    int i;
    for(i = 0;i<size;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
int main(){
    int arr[]={5,2,3,1,2};
    int size = sizeof(arr)/sizeof(arr[1]);
    bubble(arr,size);
    show(arr,size);
    return 0;
}
