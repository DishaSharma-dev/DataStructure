/*Longest Consecutive Sequence
     Input => 7
              3 7 2 1 9 8 41
     Explanation => We have two array of same sequence [1 2 3] and [7 8 9] but we take 7 8 9 bcz 7 comes first in an array
	 Outpur => 7 9
*/ 

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[1000];
	int start =0;
	int count = 0;
	int max_length;
	unordered_map<int,int> ourmap;
	vector<int> output;
	cout<<"Enter the elements in an array: ";
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
		ourmap[arr[i]] = arr[i];
	}
	for(int i = 0; i < n; i++){
		int j=arr[i];
		while(ourmap.count(j) > 0){
			count++;
			j++;
		}
		if(count > max_length) {
			max_length = count;
			start = arr[i];
		}
		count = 0;
	}
	for(int i =0; i < max_length; i++){
		output.push_back(start);
		start++;
	}
	cout<<output[0]<<" "<<output[max_length-1];
	return 0;
}
