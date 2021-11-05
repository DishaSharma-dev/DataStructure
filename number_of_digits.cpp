/* Number of Digits
Given the code to find out and return the number of digits present in a number recursively.
Input: 625
Output: 3
*/
#include <iostream>
using namespace std;

int count(int n){
	if(n == 0){
		return 0;
	}
	else{
		int small = count(n/10);
		return small + 1;
	}
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"Number of digits are: ";
	cout<<count(n);
	return 0;
}
