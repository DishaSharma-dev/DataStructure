/* Alpha Code (Dynamic Programming Approach)
Similar to all code string
Input: 25114
Output: 6
*/

#include <iostream>
#define mod 1000000007
using namespace std;

int main(){
	string s;
	int x;
	cout<<"Enter the number: ";
	cin>>s;
	int arr[50001] = {0};
	arr[0] = 1;
	int n = s.length();
	for(int i = 1; i < n; i++){
		x = (s[i-1] - '0')*10 + s[i] - '0';
		if(s[i] != '0')
			arr[i] = arr[i-1];
		if(x >= 10 && x <= 26 && i>1)
			arr[i]+=arr[i-2];
		else if(x >= 10 && x <= 26)
			arr[i]++;
		arr[i] = arr[i] % mod;
	}
	cout<<arr[n-1];
	return 0;
}