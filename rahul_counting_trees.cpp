/* Rahul Counting Trees
You are given a Binary tree T and an integer K. Input binary Trees T is consisting of N nodes rooted at node
1 and each node has a number written on it, where the number written on the ith node is A[i].
Now, Rahul needs to find the number of unordered triplets (i,j,k), such that node i is an ancestor of 
node j as well as node k, and A[i]+A[j]+A[k]>=KA node x is considered an ancestor of another node y,
if x is parent of y or x is an ancestor of parent of y.
Help Rahul for the same.

Input: 5 6
1 2 3 4 5
  1 2 2 1
Output: 7
*/

#include <iostream>
using namespace std;

int main(){
	int n,k;
	cout<<"Enter the values of n and k: ";
	cin>>n;
	cin>>k;
	int arr[n+1];
	int p[n+1];
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	for(int i = 2; i<= n; i++){
		cin>>p[i];
	}
	bool anc[n+1][n+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			anc[i][j] = false;
		}
	}
	int root = 1;
	for(int i = 2; i <= n; i++){
		int x = i;
		while(x != root){
			x = p[x];
			anc[x][i] = true;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(i != j && j!= k && i != k && anc[i][j] && anc[i][k] && (arr[i] + arr[j] + arr[k]) >= k){
					ans++;
				}
			}
		}
	}
	cout<<"Answer is: "<<ans/2;
	return 0;
}