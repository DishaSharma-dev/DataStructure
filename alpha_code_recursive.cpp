/* Alpha Code
Similar to all code string
Input: 25114
Output: 6
*/

#include <iostream>
using namespace std;

int all_codes(int* arr, int size){
	if(size == 0){
		return 1;
	}
	if(size == 1){
		return 1;
	}
	int ans = all_codes(arr,size-1);
	if((arr[size-2]*10 + arr[size-1]) <=26){
		ans = ans + all_codes(arr,size-2);
	}
	return ans;
}

int main(){
	string s;
	cout<<"Enter the number: ";
	cin>>s;
	int size = s.length();
	int arr[50001];
	for(int i = 0; i < s.length(); i++){
		arr[i] = s[i] - 48;
	}
	
	int output = all_codes(arr, size);
	cout<<output;
	return 0;
}