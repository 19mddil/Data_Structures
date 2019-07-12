#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>
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
          if(top == size-1){
             cout<<"your stack is full"<<endl;
             return;
          }
          ch[top++] = x;
       }
       char pop(){
          if(top == 0){
             cout<<"all are poped"<<endl;
             return 0;
          }
          return ch[--top];
       }
};
int getpriority(char ob);
void transforms(string source,string target);
int main(){
   string infix;
   getline(cin,infix);
   string postfix ="";
   transforms(infix,postfix);
   cout<<postfix<<endl;
}
int getpriority(char op){
   if(op == '/' || op == '*' || op == '%'){
         return 1;
   }
   else if(op == '+' || op == '-'){
         return 0;
   }
   else{
      return 0;
   }
}
void transforms(string source,string target){
     int i=0,j=0;
     char temp;
     source = "(" + source + ")";
     cout<<source<<endl;
     stack obj(source.size());
     target = "";
     while(source[i] != '\0'){

         if(source[i] == '('){
            obj.push(source[i]);
            i++;
         }

         else if(source[i] == ')'){
             if(obj.top == 0){
                cout<<"\nincorrect expression"<<endl;
                exit(1);
             }
             while(obj.top != 0 && obj.ch[obj.top] != '('){
                 target[j] = obj.pop();
                 j++;
             }
             temp = obj.pop();
             i++;
         }
         else if( isdigit(source[i]) || isalpha(source[i])){
             target[j] == source[i];
             j++;
             i++;
         }
         else if(source[i] =='+' || source[i] =='-'|| source[i] =='*'|| source[i] =='/'|| source[i] =='%'){
             while(obj.top != 0 && (obj.ch[obj.top] != '(' && (getpriority(obj.ch[obj.top])>getpriority(source[i])))){
                 target[j] = obj.pop();
                 j++;
             }
             obj.push(source[i]);
             i++;
         }
         else{
             cout<<"\n incorrect expression";
             exit(1);
         }

     }
     target[j] = '\0';
}















