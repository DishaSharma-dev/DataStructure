//Remove Duplicates from array -----0(n) using map data structure

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> remove_duplicates(int arr[] , int n){
	vector<int> output;
	unordered_map<int , bool> seen;
	for(int i = 0;i < n;i++){
		if(seen.count(arr[i]) > 0){
			continue;
		}
		seen[arr[i]] = true;
		output.push_back(arr[i]);
	}
	return output;
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[100];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	vector<int> output = remove_duplicates(arr,n);
	cout<<"Output is: ";
	for(int i=0; i<output.size(); i++){
		cout<<output[i]<<" ";
	}
	return 0;
}