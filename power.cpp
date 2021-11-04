/* Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
input: 3 4
output 81
*/

#include <iostream>
using namespace std;

int power(int x, int n){
	if(n == 0){
		return 1;
	}
	else{
		return x * power(x,n-1);
	}
}

int main(){
	int x,n;
	cout<<"Enter the number as well as power: ";
	cin>>x>>n;
	cout<<power(x,n)<<endl;
	return 0;
}