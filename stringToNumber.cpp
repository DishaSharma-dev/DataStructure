/* String to integer
Input (string, "1234"): 1234 
Output (integer): 1234
*/

#include <iostream>
#include <cstring>
using namespace std;

int stringToNumber(string str, int last){
	if(last == 0){
		return str[last] - '0';
	}
	int smallOutput = stringToNumber(str,last-1);
	int a = str[last]  - '0';
	return smallOutput*10 + a;
}

int main(){
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	cout<<"Corresponsing Integer is: ";
	int len = str.size();
	cout<<stringToNumber(str,len-1);
	return 0;
}