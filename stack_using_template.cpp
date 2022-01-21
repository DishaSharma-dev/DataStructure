/* Stack using template */

#include <iostream>
using namespace std;

template<typename T>
class stackUsingArray{
	private:
		T* data;
		int capacity;
		int nextIndex;
	public:
		stackUsingArray(){
			data = new T[4];
			capacity = 4;
			nextIndex = 0;
		}
		bool isEmpty(){
			if(nextIndex == 0){
				return true;
			}
			return false;
		}
		void push(T ele){
			if(nextIndex == capacity){
				T* newdata = new T[2*capacity];
				for(int i = 0; i < capacity; i++){
					newdata[i] = data[i];
				}
				delete []data;
				data = newdata;
			}
			data[nextIndex] = ele;
			nextIndex++;
		}
		T pop(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}	
			nextIndex--;
			return data[nextIndex];
		}
		T top(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			return data[nextIndex - 1];
		}
		T size(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			return nextIndex;	
		}
};

int main(){
	int ch;
	stackUsingArray<char> sa;
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