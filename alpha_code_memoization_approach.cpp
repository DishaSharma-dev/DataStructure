/* Alpha Code (Memoization Approach)
Similar to all code string
Input: 25114
Output: 6
*/

#include <iostream>
using namespace std;

int all_codes(int* arr, int size, int* output){
	if(size == 0){
		return 1;
	}
	if(size == 1){
		return 1;
	}
	if(output[size] != 0){
		return output[size];
	}
	int ans = all_codes(arr,size-1,output);
	if((arr[size-2]*10 + arr[size-1]) <=26){
		ans = ans + all_codes(arr,size-2,output);
	}
	output[size] = ans;
	return output[size];
}

int main(){
	string s;
	cout<<"Enter the number: ";
	cin>>s;
	int size = s.length();
	int output[size + 1] = {0};
	int arr[50001];
	for(int i = 0; i < s.length(); i++){
		arr[i] = s[i] - 48;
	}
	
	int ans = all_codes(arr, size , output);
	cout<<ans;
	return 0;
}