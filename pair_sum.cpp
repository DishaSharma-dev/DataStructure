//Pair Sum to 0

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	unordered_map<int,int> map;
	int n,i;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int pair=0;
	int arr[100];
	cout<<"Enter the elements: ";
	for(i=0;i<n;i++){
		cin>>arr[i];
		map[arr[i]]++;
	}
	for(i=0;i<n;i++){
		if(map.count(-arr[i]) > 0){
			pair= pair + map[arr[i]]*map[-arr[i]];
			map[arr[i]] = 0;
			map[-arr[i]] = 0;
		}	
	}
	cout<<pair;
	return 0;
}