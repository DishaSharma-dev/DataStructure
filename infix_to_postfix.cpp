/* Infix to Postfix
Input: 3 + 4
Output: 3 4 +
        7
*/

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int priority(char c){
	if(c == '*' || c == '/'){
		return 2;
	}
	else if(c == '+' || c == '-'){
		return 1;
	}
	else{
		return -1;
	}
}

int evaluate(int op1, int op2, char operate){
	switch(operate){
		case '*' : return op1*op2;
		case '/' : return op1/op2;
		case '+' : return op1+op2;
		case '-' : return op1-op2;
		default  : return 0;
	}
}

void postfixExpression(char* str){
	stack<char> s;
	char output[1000];
	int index = 0;
	for(int i = 0; i < strlen(str); i++){
		if(str[i] >= '0' && str[i] <= '9'){
			output[index++] = str[i];
		}
		else if(str[i] == '('){
			s.push(str[i]);
		}
		else if(str[i] == ')'){
			while(!s.empty() && s.top() != '('){
				char c = s.top();
				s.pop();
				output[index++] = c;
			}
			if(s.top() == '('){
				char c = s.top();
				s.pop();
			}
		}
		else{
			while(!s.empty() && priority(str[i]) <= priority(s.top())){
				char c = s.top();
				s.pop();
				output[index++] = c;
			}
			s.push(str[i]);
		}
	}
	while(!s.empty()){
		char c = s.top();
		s.pop();
		output[index++] = c;
	}
	output[index] = '\0';
	cout<<output<<endl;
	int i = 0;
	while(i < strlen(output)){
		str[i] = output[i];
		i++;
	}
	str[i] = '\0';
}

void evaluation(char* str){
	stack<int> st;
	int val;
	for(int i = 0; i < strlen(str); i++){
		if(str[i] >= '0' && str[i] <= '9'){
			char ch = str[i];
			st.push(ch - '0');
		}
		else{
			int op1 = st.top();
			st.pop();
			int op2 = st.top();
			st.pop();
			val = evaluate(op1, op2, str[i]);
			st.push(val);
		}
	}
	cout<<val<<endl;
}


int main(){
	char str[1000];
	cout<<"Enter the expression: ";
	cin>> str;
	cout<<"Postfix Expression is\n";
	postfixExpression(str);
	cout<<"Result of input expression after evaluation\n";
	evaluation(str);
	return 0;
}