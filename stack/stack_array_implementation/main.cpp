/***
 * Date: 3rd May ,Friday 2019
 * Fundemantal Stack Prototype for Reuse without STL
 ***/
#include<iostream>
using namespace std;
class stack{
	int Size;
	char *stck;
	int tos;
	public:
		stack(int s=0){
            this->Size = s;
			if(Size == 0){
				cout<<"stack is not stacked"<<endl;
			}
			else{
				stck = new char[Size];
			}
		}
		void init(){
			tos = -1;
		}
		void push(char ch);
		char pop();
		int top(){
			return tos;
		}
		void show_peek(){
            if(tos==-1){
                cout<<"nothings to peek, stacks empty"<<endl;
                return;
            }
            cout<<stck[tos]<<endl;
		}
};
void stack::push(char ch){
	if(tos == (Size-1)){
		cout<<"stack overflow"<<endl;
		return;
	}
	stck[++tos] = ch;
}
char stack::pop(){
	if(tos == -1){
		cout<<"stack underflow"<<endl;
		return 0;
	}
	return stck[tos--];
}
int main(){
	stack s1(3);
	int i;
	s1.init();
	for(i=0;i<10;i++){
        if(s1.top()==(3-1)){
            break;
        }
		s1.push((i+'0'));
	}
	for(i=0;i<10;i++){
        if(s1.top()== -1){
            break;
        }
		cout<<s1.pop()<<endl;
	}
	s1.push('x');
	s1.show_peek();
	cout<<s1.top()<<endl;
}
