//Program to detect whether a number has cube root if yes then print otherwise output the nearest small cube root

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	int result,flag=0;
	for(int i=1;i<n;i++){
		if(i*i*i == n){
			cout<<i;
			flag=1;
			break;
		}
		else if((i*i*i)<n){
			result = i;
		}
	}
	if(flag == 0){
		cout<<result;
	}
	return 0;
}