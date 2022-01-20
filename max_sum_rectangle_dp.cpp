/*Maximum Sum Rectangle
Given a 2D array, find the maximum sum rectangle in it.
In other words find maximum sum over all rectangles in the matrix.
Input: 4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Output: 29*/

#include <iostream>
#include <vector>
using namespace std;

int kadane(vector<int> ans, int c){
	int curr_sum = 0;
	int max_sum = INT_MIN;
	for(int i = 0; i < c; i++){
		curr_sum += ans[i];
		if(curr_sum > max_sum){
			max_sum = curr_sum;
		}
		if(curr_sum < 0){
			curr_sum = 0;
		}
	}
	return max_sum;
}

int main(){
	int r, c;
	cout<<"Enter the number of rows: ";
	cin>>r;
	cout<<"Enter the number of columns: ";
	cin>>c;
	int arr[r][c];
	cout<<"Enter the values: ";
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin>>arr[i][j];
		}
	}
	int ma = INT_MIN;
	for(int i = 0; i < r; i++){
		vector<int> ans(c);
		for(int j = i; j < r; j++){
			for(int col = 0; col < c; col++){
				ans[col] += arr[j][col];
			}
			ma = max(ma, kadane(ans, c));
		}
	}
	cout<<"Output is: ";
	cout<<ma;
	return 0;
}