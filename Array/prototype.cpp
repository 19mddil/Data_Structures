#include<iostream>
#include<cctype>
#include<cstdlib>
using namespace std;
class stack{
   public:
       int size ;
       int top;
       char *ch;
       stack(int x=100){
          ch = new char[x];
          size = x;
          top = 0;
       }
       void push(char c){
           if(top>=size){
              cout<<"stack overflow"<<endl;
              exit(1);
           }
           ch[top] =c;
           top++;
       }
       char pop(){
           top--;
           if(top<0){
               cout<<"stack is empty"<<endl;
               exit(1);
           }
           return ch[top];
       }
};
int prec(char c){
    if(c == '+'|| c == '-'){
        return 1;
    }
    else if(c == '*'|| c == '/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }
    else{
      return -1;
    }
}
int main(){
   string p;
   int i = 0;
   int j = 0;
   getline(cin,p);
   stack obj(p.size());
   while(p[i] != '\0'){

   }
}
