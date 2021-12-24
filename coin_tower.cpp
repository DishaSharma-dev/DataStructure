/* Coin Tower
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first.
In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game.
Can you find out who wins the game?
Input: 4 2 3
Output: Whis
*/

#include <iostream>
using namespace std;

int main(){
	int n,x,y;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"Enter the value of x: ";
	cin>>x;
	cout<<"Enter the value of y: ";
	cin>>y;
	int dp[n+1];
	dp[0] = 0;  
	dp[1] = 1; // If only one coin is there then Beerus will win
	for(int i = 2; i <= n; i++){
		if(n-1 >= 0 && dp[i-1] == 0)
			dp[i] = 1;
		else if(n-x >= 0 && dp[i-x] == 0)
			dp[i] = 1;
		else if(n-y >= 0 && dp[i-y] == 0)
			dp[i] = 1;
		else
			dp[i] = 0;
	}
	if(dp[n] == 0){
		cout<<"Whis";
	}
	else{
		cout<<"Beerus";
	}
	return 0;
}