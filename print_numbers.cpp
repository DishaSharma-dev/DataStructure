/* Print Numbers
Given is the code to print numbers from 1 to n in increasing order recursively.
But it contains few bugs that you need to rectify such that all the test cases pass.
Input: 6
Output: 1 2 3 4 5 6
*/
#include <iostream>
using namespace std;

int number(int n){
	if(n == 0){
		return 0;
	}
	else{
		number(n-1);
		cout<<n<<" ";
	}
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	number(n);
	return 0;
}
