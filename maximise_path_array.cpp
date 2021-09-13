/*Maximise the sum
1 5 10 15 20 25
2 4 5 9  15
=>81
*/

#include <iostream>
using namespace std;

int maxpathsum(int arr1[], int n1, int arr2[], int n2){
	int sum1=0,sum2=0,result=0;
	int i,j=0;
	while(i<n1 && j<n2){
		if(arr1[i]<arr2[j]){
			sum1=sum1 + arr1[i];
			i++;
		}
		else if(arr1[i]>arr2[j]){
			sum2=sum2 + arr2[j];
			j++;
		}
		else{
			result=result+arr1[i];
			sum1 > sum2 ? result += sum1 : result += sum2;
			i++;
			j++;
			sum1=0;
			sum2=0;
		}
	}
	while(i<n1){
		result = result + arr1[i];
		i++;
	}
	while(i<n2){
		result = result + arr2[j];
		j++;
	}
	return result;
}

int main(){
	int n1,n2;
	cout<<"Enter the size of array1: ";
	cin>>n1;
	int arr1[1000];
	int arr2[1000];
	cout<<"Enter the elements in array1: ";
	for(int i=0;i<n1;i++){
		cin>>arr1[i];
	}
	cout<<"Enter the size of array2: ";
	cin>>n2;
	cout<<"Enter the elements in array2: ";
	for(int i=0;i<n2;i++){
		cin>>arr2[i];
	}
	int result = maxpathsum(arr1,n1,arr2,n2);
	cout<<result;
}