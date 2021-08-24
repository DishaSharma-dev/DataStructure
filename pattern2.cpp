/*Number Pattern
           1
          23
         345          */

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of rows to be display: ";
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++){
		k=i;
		for(j=1;j<2*n;j++){
			if((i+j)>n && j<=n){
				cout<<k;
				k++;
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}