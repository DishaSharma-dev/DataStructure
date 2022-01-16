/* 0 1 Knapsack (Recursion Approach)
A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and ith item weighs wi and is of value vi.
Considering the constraints of maximum weight that knapsack can carry,
you have to find and return the maximum value that thief can generate by stealing items.
Input: 4
1 2 4 5
5 4 8 6
5
Output: 13*/

#include <iostream>
using namespace std;

int knapsack(int* weight, int* values, int n, int max_weight){
	if(n == 0 || max_weight == 0){
		return 0;
	}
	if(weight[n-1] > max_weight){
		return knapsack(weight, values, n-1, max_weight);
	}
	else{
		return max(values[n-1] + knapsack(weight, values, n-1, max_weight - weight[n-1]), 
		knapsack(weight, values, n-1, max_weight));
	}
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int max_weight;
	int weight[n];
	int values[n];
	cout<<"Enter the values of weight: ";
	for(int i = 0; i < n; i++){
		cin>>weight[i];
	}
	cout<<"Enter the values of val: ";
	for(int i = 0; i < n; i++){
		cin>>values[i];
	}
	cout<<"Enter the maximum weight: ";
	cin>>max_weight;
	cout<<"Output is: ";
	cout<<knapsack(weight, values, n, max_weight);
	return 0;
}