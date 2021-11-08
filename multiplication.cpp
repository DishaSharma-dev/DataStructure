/* Sum of digits(recursive)
Given two integers M & N, calculate and return their multiplication using recursion. 
You can only use subtraction and addition for your calculation.No other operators are allowed.
Input: 3 
       5
Output: 15
*/
#include <iostream>
using namespace std;

int multiply(int n, int m){
	if(m == 0){
		return 0;
	}
	int ans = n + multiply(n , m-1);
}

int main(){
	int n,m;
	cout<<"Enter the number1: ";
	cin>>n;
	cout<<"Enter the number2: ";
	cin>>m;
	cout<<"Multiplication is: ";
    cout<<multiply(n,m);
	return 0;
}
