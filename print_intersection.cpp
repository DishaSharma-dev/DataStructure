//Print Intersection

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n , m ,i;
	int input1[100];
	int input2[100];
	cout<<"Enter the size of array1: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(i=0;i<n;i++){
		cin>>input1[i];
	}
	cout<<"Enter the size of array2: ";
	cin>>m;
	cout<<"Enter the elements: ";
	for(i=0;i<m;i++){
		cin>>input2[i];
	}
	unordered_map<int,int> map;
	for(i=0;i<n;i++){
		map[input1[i]]++;
	}
	for(i=0;i<m;i++){
		if(map[input2[i]] > 0){
			map[input2[i]]--;
			cout<<input2[i]<<" ";
		}
	}
	return 0;
}