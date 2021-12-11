/* Boredom
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" .
In this game there are N integers on a board. In one move,he can pick any integer x from the board and then all the integers 
with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven,
he wants to learn techniques to maximise the points to show off . 
Can you help Gary in finding out the maximum points he receive grab from the game ?
Input: 2
       1 2
Output : 2
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[1000];
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Output is: ";
	int freq[1002] = {0};
	int dp[1002];
	for(int i = 0; i < n; i++){
		freq[arr[i]]++;
	}
	dp[0] = 0;
	dp[1] = freq[1];
	for(int i = 2; i <= 1000; i++){
		dp[i] = max(dp[i-1],(dp[i-2] + i * freq[i]));
	}
	cout<<dp[1000];
	return 0;
}