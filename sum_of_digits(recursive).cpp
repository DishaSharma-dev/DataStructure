/* Sum of digits(recursive)
Write a recursive function that returns the sum of the digits of a given integer.
Input: 12345
Output: 15
*/
#include <iostream>
using namespace std;

int sum(int n){
	if(n == 0){
		return 0;
	}
	int ans = n%10 + sum(n/10);
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"Sum of digits is: ";
    cout<<sum(n);
	return 0;
}
