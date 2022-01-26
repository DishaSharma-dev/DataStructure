/* Minimum Bracket Traversal
For a given expression in the form of a string, find the minimum number of brackets that can be reversed
in order to make the expression balanced.The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Input: }{
Output: 2
*/

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(){
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	int index = 0;
	stack<char> s;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '{'){
			s.push(str[i]);
		}
        else{
        	if(s.empty()){
                s.push('{');
            	index++;
            }
            else{
            	char ch = s.top();
            	if(ch == '{' || s.empty()){
                	s.pop();
                }
                else{
                	s.push('{');
            		index++;	
				}
			}  
        }
	}
	if(s.size() % 2 != 0){
		cout<<"-1";
	}
	else{
		cout<<(s.size() / 2)+index;
	}
	return 0;
}