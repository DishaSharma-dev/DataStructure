/* Stock Span Time Complexity: 0(n)
Afzal has been working with an organization called 'Money Traders' for the past few years.
The organization is into the money trading business. His manager assigned him a task.
For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days
(starting from today and going backwards) for which the price of the stock was less than today's price.
Input: 8
60 70 80 100 90 75 80 120
Output: 1 2 3 4 1 1 2 8
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size: ";
	cin>>n;
	int arr[n];
	int output[n];
	cout<<"Enter the elements:";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	stack<int> s;
	output[0] = 1;
	s.push(0);
	for(int i = 1; i < n; i++){
		while(!s.empty() && arr[s.top()] < arr[i]){
			s.pop();
		}
		if(s.empty()){
			output[i] = i + 1;
		}
		else{
			output[i] = i - s.top();
		}
		s.push(i);
	}
	for(int i = 0; i < n; i++){
		cout<<output[i]<<" ";
	}
	return 0;
}