/**
 * Circular Queue List Array implementation
 * date: 10th May Fri 11:55 am.
 * by Md.Dilshadul Islam
**/ 
#include<iostream>
using namespace std;
class queue{
	public:
		int *data;
		int MAX;
		int font,rear;
		queue(int x){
			MAX = x;
			data = new int[x];
			font = rear = -1;
		}
		void enqueue(int x){                       ///MAX = 3
			if(font == -1 && rear == -1){          ///rear = 0 ///false                     ///false                ///false
				font = rear = 0;                   ///font = 0
			}
			else if(((rear+1) % MAX) == font){                 /// (0+1) % 3 = 1 ,font = 0  ///(1+1)%3=2            ///(2+1)%3 = 0 true
				cout<<"overflow"<<endl;
				return;
			}
			else{
				rear = (rear + 1) % MAX;         ///rear = 0  /// rear = (0+1)%3 = 1       ///rear = (1+1)%3 = 2    ///false
			}
			data[rear] = x;
		}
		int dequeue(){
			if(font == rear && (font != (-1))){
				int i;
				i = data[font];
				font = rear = -1;
				return i;
			}
			else if((font == (-1))&&(rear ==(-1))){
				cout<<"unerflow"<<endl;
				exit(1);
			}
			else {
				int i;
				i = data[font];
				font = (font + 1)%MAX;
				return i;
			}
		}
};
int main(){
	
}

