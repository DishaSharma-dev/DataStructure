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
	int i,j;
	for(i=1;i<2*n;i++){
		for(j=1;j<2*n;j++){
			if(i<=n && j<=n){
				cout<<n;
			}
			else{
				cout<<"*";
			}
		}
		cout<<endl;
	}
	return 0;
}