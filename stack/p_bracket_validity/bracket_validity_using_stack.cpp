#include<iostream>
#include<string>
#include<cstdlib>
#define MAX 100
using namespace std;
class stack{
   public:
      char *ch;
      int size;
      int top;
      stack(int x=100){
         size = x;
         ch = new char[x];
         top = 0;
      }
      void push(char x){
          if(top >= size){
             cout<<"stack overflow"<<endl;
             exit(1);
          }
          ch[top] = x;
          top++;
       }
       char pop(){
          top --;
          if(top < 0){
             cout<<"stack is empty"<<endl;
             exit(1);
          }
          return ch[top];
       }
};

string bodmas_checker(string str);

int main(){
       string x;
       while(1){
         cout<<"Enter a equation: ";
         getline(cin,x);
         cout<<bodmas_checker(x)<<endl;
         cout<<endl;
       }
}
string bodmas_checker(string str){
    char temp;
    stack obj(str.size());
    //cout<<"in stack 1"<<' '<<obj.ch[0]<<endl;
    int flag = 1 ;
    int count = 0;
    int i = 0;
    for(i = 0;i<str.size();i++){
        if(str[i]=='(' ||  str[i]=='{' || str [i] == '[' ){
            if(i>0){///when stack is not empty
                temp=obj.pop();
                if(temp == '(' &&(str[i] == '{' || str[i] == '[')){
                     flag = 0;
                     break;
                }
                if(temp == '{' &&(str[i] == '[')){
                     flag = 0;
                     break;
                }
                obj.push(temp);
            }
            obj.push(str[i]);
        }
        if(str[i]==')'|| str[i]=='}'|| str [i] == ']' ){
            if(obj.top == 0){
               flag = 0;
            }
            else{
               temp = obj.pop();
               if(str[i] == ')' && (temp =='{' || temp == '[')){
                  flag = 0;
               }
               if(str[i] == '}' && (temp =='(' || temp == '[')){
                  flag = 0;
               }
               if(str[i] == ']' && (temp =='{' || temp == '(')){
                  flag = 0;
               }
            }
        }
    }
    if(obj.top!=0){
       flag = 0;
    }
    if(!flag){
           return "invalid";
    }
    else{
           return "valid";
    }
}

