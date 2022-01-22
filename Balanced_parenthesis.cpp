/* Balanced Parenthesis
For a given a string expression containing only round brackets or parentheses, 
check if they are balanced or not. 
Brackets are said to be balanced if the bracket which opens last, closes first.
Input: (()()())
Output: True
*/

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(){
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	stack<char> sa;
	int flag = 0; 
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '(' || str[i] == '{' || str[i] == '['){
			sa.push(str[i]);
		}
		else if(str[i] == '}'){
			char check = sa.top();
			if(check != '{'){
				cout<<"false";
				flag = 1;
				break;
			}
			sa.pop();
		}
		else if(str[i] == ']'){
			char check = sa.top();
			if(check != '['){
				cout<<"false";
				flag = 1;
				break;
			}
			sa.pop();
		}
		else if(str[i] == ')'){
			char check = sa.top();
			if(check != '('){
				cout<<"False";
				flag = 1;
				break;
			}
			sa.pop();
		}
	}
	if(flag == 0){
		if(sa.size() == 0){
			cout<<"True";
		}
		else{
			cout<<"False";
		}
	}
	return 0;
}