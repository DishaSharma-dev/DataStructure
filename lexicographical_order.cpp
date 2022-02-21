/* Lexicographical Order
Input: 20
Output: 1 10 11 12 13 14 15 16 17 18 19 2 20 3 4 5 6 7 8 9*/

#include <iostream>
using namespace std;

void lexicographicalOrder(int numberSoFar, int n){
	if(numberSoFar > n){
		return;
	}
	cout<<numberSoFar<<endl;
	for(int i = 0; i <=9; i++){
		lexicographicalOrder((numberSoFar * 10) + i, n);
	}
}

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	for(int i = 1; i <= 9; i++){
		lexicographicalOrder(i, n);
	}
}