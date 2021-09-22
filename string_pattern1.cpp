/*                 A
                 B   B
                C     C     */
                
#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<2*n-1;j++){
			if((i+j)<n-1 || (i+j)>n-1+2*i)
			  cout<<" ";
			else if((i+j)== n-1 || (i+j)==(n-1)+i*2)
			  cout<<char(i+65);
			else
			 cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}