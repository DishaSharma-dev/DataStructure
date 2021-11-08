/* Count number of zeros
Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
Input: 00010204
Output: 2
*/
#include <iostream>
using namespace std;

int no_of_zeros(int n){
	if(n == 0){
		return 0;
	}
	int ans = no_of_zeros(n/10);
	if(n%10 == 0)
		return ans + 1;
	else
		return ans;
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
    cout<<"Number of zeros are: ";
    cout<<no_of_zeros(n);
	return 0;
}
