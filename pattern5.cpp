/*Number Pattern
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4   */

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of rows to be display: ";
	cin>>n;
	int size = 2*n-1;
	int initial=0;
	int final=size-1;
	int arr [size][size];
	int i,j;
	while(n != 0){
		for(i=initial;i<=final;i++){
			for(j=initial; j<=final;j++){
				if(i== initial || j== initial || i==final || j==final)
					arr[i][j] = n;
			}
		}
		++initial;
		--final;
		--n;
	}
	//Print the array
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}