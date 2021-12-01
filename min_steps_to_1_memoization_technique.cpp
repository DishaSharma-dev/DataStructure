/* Min Step to 1(Memoization)
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1.
You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Input: 4
Output: 2
Explanation: 
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 */
            
#include <iostream>
using namespace std;

int minSteps(int n, int *arr){
	if(n == 1){
		return 0;
	}
	if(arr[n] != -1){
		return arr[n];
	}
	int res = minSteps(n-1,arr);
	if(n%2 == 0){
		res = min(res, minSteps(n/2,arr));
	}
	if(n%3 == 0){
		res = min(res, minSteps(n/3,arr));
	}
	arr[n] = 1+res;
	return arr[n];
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	int arr[n+1];
	for(int i = 0; i <=n; i++){
		arr[i] = -1;
	}
	int output = minSteps(n, arr);
	cout<<output;
	return 0;
}
