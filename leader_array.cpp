/*
  Leaders in array
  find the largest element and the elements following the largest element must be small and equal to it.
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[100];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> v;
	int leader = arr[n-1];
	v.push_back(leader);
	for(int i=n-1;i>=0;i--){
		if(arr[i]>leader){
			v.push_back(arr[i]);
			leader = arr[i];
		}
	}
	cout<<"Output: ";
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i]<<" ";
	}
	return 0;
}