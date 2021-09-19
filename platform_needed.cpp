/*
  Count the minimum number of platforms needed
  Train arrival and departure time is given
  complexity of this program is 0nlogn
  nlogn for sorting
  n for looping
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr1[100];
	int arr2[100];
	cout<<"Enter the elements in arrival array: ";
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	cout<<"Enter the elements in departure array: ";
	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}
	int max=1;
	int platform_needed=1;
	sort(arr1,arr1+n);
	sort(arr2,arr2+n);
	int i=1,j=0;
	while(i<n && j<n){
		if(arr1[i] <= arr2[j]){
			i++;
			max++;
			if(platform_needed < max){
				platform_needed++;
			}
		}
		else{
			j++;
			max--;
		}
	}
	cout<<platform_needed;
	return 0;
}