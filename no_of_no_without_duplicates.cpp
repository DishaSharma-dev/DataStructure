/* Number of numbers with duplicates
Input: 122
Output: 2
*/

#include <iostream>
using namespace std;

int num(int* input, int n, int* fact, int* freq){
	if(n == 0 || n == 1){
		return 0;
	}
	int ans = 0;
	int count = 0;
	for(int i = input[0] + 1; i < 10; i++){
		if(freq[i] > 0){
			count = fact[n-1]/fact[freq[i] - 1];
			for(int j = 0; j < 10; j++){
				if(i == j){
					continue;
				} 
				count = count/fact[freq[j]];
			}
			ans += count;
		}	
	}
	freq[input[0]]--;
	ans += num(input + 1, n - 1, fact, freq);
	return ans;
}

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	int* input = new int[n];
	int* fact = new int[n+1];
	fact[0] = 1;
	int freq[10] = {};
	for(int i = 0; i < n; i++){
		cin>>input[i];
		freq[input[i]]++;
		fact[i+1] = (i+1) * fact[i];
	}
	cout<<num(input, n, fact, freq)<<endl;
	return 0;
}