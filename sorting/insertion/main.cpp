#include<iostream>
using namespace std;
void insertion(int arr[],int size){
    int key;
    int j ,i;
    for(j = 1;j<size;j++){///this line just helps to find the key
        key = arr[j];
        i=j;///we need this just not to override the j
        while(i >0 && key<arr[i - 1]){///in the best case while loop never executes
            swap(arr[i],arr[i-1]);
            i--;
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
    int arr[] = {1,2,3,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion(arr,size);
    show(arr,size);
    return 0;
}
