/*Triangle of numbers
           1
          232
         34543          */

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
			else if(j>=n && k>i){
				k--;
				cout<<k;
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
		  