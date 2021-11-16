/*Minimum Count
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
Output will be 1, as 1 is the minimum count of numbers required.
Input: 12
Output: 3
*/

#include <iostream>
#include <cmath>
using namespace std;

int minimumCount(int n){
	int count = n;
	if(n <= 1){
		return n;
	}
	for(int i = 1; i <=n; i++){
		if(i*i > n){
			break;
		}
		else{
			count = min(count, 1+ minimumCount(n - i*i));
		}
	}
	return count;
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"Minimum Count is: ";
	cout<<minimumCount(n);
	return 0;
}