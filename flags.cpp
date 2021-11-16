/* Flags
A flag can consists of only three different colors of stripes, White(W), Blue(B) and Red(R).
Given an integer N, find and return the number of ways to create such flags having N stripes 
consisting of these three color stripes only with the following constraints 
1. Stripes of the same color cannot be placed next to each other.
2. A blue stripe must always be placed between a white and a red or between a red and a white one. 
Hence blue stripe cannot be placed at starting or at ending.
3. Its not necessary to use all three colors.
Input: 3
Output: 4
Possible flags with 3 stripes are : WRW, WBR, RWR, RBW
*/

#include <iostream>
using namespace std;

int count = 0;
void ways(int n, char prev, char pprev){
	if(n == 1 && pprev == 'S'){
	    count = 2;
		return;
	}
	if(n == 1){
		count++;
		return;
	}
	if(pprev == 'S'){
		ways(n-1,'W','B');
		ways(n-1,'R','B');
	}
	else if(prev == 'B' && pprev == 'W'){
		ways(n-1,'R','B');
	}
	else if(prev == 'B' && pprev == 'R'){
		ways(n-1,'W','B');
	}
	else if(prev == 'W'){
		ways(n-1,'B','W');
		ways(n-1,'R','W');
	}
	else if(prev == 'R'){
		ways(n-1,'B','R');
		ways(n-1,'W','R');
	}
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"Possible ways are: ";
	ways(n,'B','S');
	cout<<count;
	return 0;
}