/* Geometric Sum
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
Input: 3
Output: 1.87500
*/
#include <iostream>
#include <math.h>
using namespace std;

double geometric_sum(int n){
	if(n == 0){
		return 1;
	}
	double a = geometric_sum(n-1);
	return a + (1/pow(2,n));
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
    cout<<"Geometric Sum is: ";
    double output = geometric_sum(n);
    cout<<output;
	return 0;
}
