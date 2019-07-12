/***
 * Date: 3rd May Friday 2019
 * This code never face stack overflow
 ***/
#include<iostream>
using namespace std;
class stack{
	int data;
	int TOP;
	stack * next;
	stack * tos;
	stack * temp;
	public:
		void init(){
			tos = temp = NULL;
			TOP = -1;
		}
		void push(int d){
			temp = new stack;
			TOP++;
			temp->data = d;
			temp->next = tos;
			tos = temp;
		}
		int pop(){
			if(tos == NULL){
				cout<<"stack underflow"<<endl;
			}
			else{
				char x;
				x = tos->data;
				tos = tos -> next;
				TOP--;
				return x;
			}
		}
		int top(){
            return TOP;
		}
		int isempty(){
			if(TOP == -1){
				return 1;
			}
			else{
				return 0;
			}
		}
};
int main(){
    stack s1;
    s1.init();
	int stack_size;
	cin>>stack_size;
	int i;
	for(i=0;i<stack_size;i++){
        s1.push(i);
	}
    cout<<s1.top()<<endl;
	for(i=0;i<stack_size;i++){
        cout<<s1.pop()<<' ';
	}
	cout<<endl;
}
