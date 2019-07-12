#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class queue{
	public:
	int data;
	queue *front;
	queue *rear;
	queue *next;
	queue *temp,*temp1;
	queue(){
		front = rear = NULL;
	}
	void enqueue(int x){
		if((front == NULL) && (rear == NULL)){
			temp1 = new queue();
			temp1->data = x;
			front = rear = temp1;
			temp1->next = NULL;

		}
		else{
			temp = new queue();
			temp->data = x;
			temp1->next  = temp;
			temp ->next = NULL;
			temp1 = temp;
			rear = temp;

		}
	}
	void dequeue(){
		if(front == NULL){
			cout<<"queue is empty"<<endl;
		}
		else{
            cout<<front->data<<' ';
			temp = front->next;
			delete front;
			front = temp;
			if(front == NULL){
				rear = NULL;
			}
		}
	}
};
int main(){
	queue q;
	int i;
	cout<<q.front<<endl;
	
	for(i=0;i<10;i++){
		q.enqueue(i);
		cout<<q.front<<endl;
	}
	for(i=0;i<10;i++){
		q.dequeue();
	}
	cout<<endl;
	cout<<q.front<<endl;
	cout<<q.rear<<endl;
	q.enqueue(12);
	q.dequeue();
	
}


