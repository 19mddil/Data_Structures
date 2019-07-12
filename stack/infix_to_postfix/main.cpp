#include<iostream>
#include<cctype>
#include<cstdlib>
using namespace std;
class stack{
	public:
	char data;
	int TOP;
	stack * next;
	stack * tos;
	stack * temp;
		void init(){
			tos = temp = NULL;
			TOP = -1;
		}
		void push(char d){
			temp = new stack;
			TOP++;
			temp->data = d;
			temp->next = tos;
			tos = temp;
		}
		char pop(){
			if(tos == NULL){
				cout<<"stack underflow"<<endl;
				exit(1);
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
		char xtop(){
            if(tos == NULL){
                return -1;
            }
            return tos->data;
		}
};
int prec(char x){
    switch(x){
        case '+': case '-':
        return 1;
        break;
        case '*':case '/':
        return 2;
        case '^':
        return 3;
        break;
    }
}
int main(){
    stack x;
    x.init();
    string y = "A*(B+C)/D";
    int i = 0;
    while(y[i] != '\0'){
        if(isalpha(y[i]) || isdigit(y[i])){
            cout<<y[i];
        }
        else{
            if((y[i] == '+' )||(y[i] == '-')|| (y[i] == '*' )|| (y[i] == '/') || (y[i] == '^') ){
                if((x.isempty())|| (x.xtop() == '(') || (prec(y[i])>prec(x.xtop()))){
                    x.push(y[i]);
                }
                else{
                    while((x.xtop() != '(')&&(prec(x.xtop()) >= prec(y[i]))){
                        cout<<x.pop();
                    }
                    x.push(y[i]);
                }
            }
        }
        if(y[i] == '('){
			x.push(y[i]);
		}
		if(y[i] == ')'){
			while(x.xtop() != '('){
				cout<<x.pop();
			}
			x.pop();
		}
		i++;
    }
    while(!(x.isempty())){
		cout<<x.pop();
	}
	cout<<endl;
}
