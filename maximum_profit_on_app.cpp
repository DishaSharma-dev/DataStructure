/*  Maximum Profit on an App
You have made a smartphone app and want to set its subscription price such that the profit earned is maximised. 
There are certain users who will subscribe to your app only if their budget is greater than or equal to your price.
You will be provided with a list of size N having budgets of subscribers and you need to return the maximum profit 
that you can earn. Lets say you decide that price of your app is Rs. x and there are N number of subscribers.
So maximum profit you can earn is :
 m * x
 
 Input : 4
         30 20 53 14
 Output : 60
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int arr[100];
	int cost[100];
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(int i = 0; i < n ; i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i = 0 ; i < n; i++){
		cost[i] = arr[i]*(n-i);
	}
	int max=0;
	for(int i = 0; i < n; i++){
		if(cost[i] > max){
			max = cost[i];
		}
	}
	cout<<"Output is: "<<max;
	return 0;
}