/* Stack using Dynamic Array */

#include <iostream>
using namespace std;


class stackUsingArray{
	private:
		int* data;
		int capacity;
		int nextIndex;
	public:
		stackUsingArray(){
			data = new int[4];
			capacity = 4;
			nextIndex = 0;
		}
		bool isEmpty(){
			if(nextIndex == 0){
				return true;
			}
			return false;
		}
		void push(int ele){
			if(nextIndex == capacity){
				int* newdata = new int[2*capacity];
				for(int i = 0; i < capacity; i++){
					newdata[i] = data[i];
				}
				delete []data;
				data = newdata;
			}
			data[nextIndex] = ele;
			nextIndex++;
		}
		int pop(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}	
			nextIndex--;
			return data[nextIndex];
		}
		int top(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			return data[nextIndex - 1];
		}
		int size(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return INT_MIN;
			}
			return nextIndex;	
		}
};

int main(){
	int ch;
	stackUsingArray sa;
	while(1){
		cout<<"Enter your choice: \n";
		cout<<"1. Insert an element: \n";
		cout<<"2. Delete an element: \n";
		cout<<"3. Size of Stack: \n";
		cout<<"4. Top element: \n";
		cout<<"5. Check whether Empty Stack or not: \n";
		cout<<"6. Exit: \n";
		cin>>ch;
		switch(ch){
			case 1 : int ele;
			         cout<<"Enter the element: "<<endl;
			         cin>>ele;
			         sa.push(ele);
			         break;
			case 2 : cout<<sa.pop()<<endl;
			         break;
			case 3 : cout<<sa.size()<<endl;
			         break;
			case 4 : cout<<sa.top()<<endl;
			         break;
			case 5 : cout<<sa.isEmpty()<<endl;
			         break;
			case 6 : exit(0);
		}
	}
	return 0;
}