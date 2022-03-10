/* Depth of Binary Tree
Input: nlnll
Output: 2
*/

#include <iostream>
#include <cstring>
using namespace std;

int i = 0;

int depth(string &str){
	if(str.length() <= i){
		return 0;
	}
	if(str[i] == 'l'){
		return 1;
	}
	i++;
	int dep1 = 1 + depth(str);
	i++;
	int dep2 = 1 + depth(str);
	return max(dep1, dep2);
}

int main(){
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	cout<<"Depth of the tree is: ";
	cout<<depth(str)-1;
	return 0;
}