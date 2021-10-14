//Maximum Frequency number

#include <iostream>
#include <unordered_map>
using namespace std;

int max_number(int arr[], int n){
	unordered_map<int,int> map;
	int result = arr[0];
	int count = 0;
	int max = 0;
	for(int i = 0; i < n; i++){
		if(map.count(arr[i]) > 0){
			count = map.at(arr[i]);
			count++;
			map[arr[i]] = count;
			if(count > max){
				max = count;
				result = arr[i];
			}
		}
		else{
			map[arr[i]]= 1;
		}
	}
	return result;
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[100];
	cout<<"Enter the elements: ";
	for(int i  = 0; i < n; i++){
		cin>>arr[i];
	}
	int result = max_number(arr,n);
	cout<<result;
	return 0;
}