/*Number Pattern
           1    1
           12  21
           123321        */

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of rows to be display: ";
	cin>>n;
	int i,j,k,z;
    for(i=1;i<=n;i++){
    	z=i;
    	for(j=1;j<=2*n;j++){
    		k=j;
    		if(j<=n && j<=i){
    			cout<<k;
			}
			else if((i+j)>2*n){
			cout<<z;
			z--;	
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
		  