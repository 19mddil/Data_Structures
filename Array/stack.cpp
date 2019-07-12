#include<iostream>
using namespace std;
class stack{
    public:
       int top;
       int *a;
       int size;
       stack(int x=0){
          size = x;
          a = new int[size];
          top = 0;
       }
       void push(int x){
          if(top >= size){
             cout<<"stack overflow"<<endl;
             return;
          }
          a[top] = x;
          top ++;
       }
       int pop(){
           top --;
          if(top< 0){
             cout<<"stack is empty"<<endl;
             return 0;
          }

          return a[top];
       }
};
int main(){
    stack obj(3);
    int i = 0;
    int x;
    for(i=0;i<obj.size;i++){
      cout<<"enter "<<i+1<<"st element to push: ";
      cin>>x;
      obj.push(x);
      cout<<endl;
    }
    cout<<endl;
    for(i=0;i<obj.size;i++){
       cout<<obj.pop()<<' ';
    }
    cout<<endl;

}
