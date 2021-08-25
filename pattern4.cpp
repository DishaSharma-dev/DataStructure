/*Arrow Pattern
           *
            * *
             * * *
            * *
           *
                  */

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of rows to be display: ";
	cin>>n;
	int i,j,c,count=0;
	int temp= n;
    for(i=1;i<=n;i++){
    	 	c=temp;
    	for(j=1;j<=n;j++){
    	   if(i<=(n+1)/2){
    	   	if(j<i) cout<<" ";
    	   	else if(count!=i){
    	   		count++;
    	   		cout<<"* ";
			   }
		   }
		   else{
		   	if((i+j)<(n+1)) cout<<" ";
		   	else if(temp>0 && c>0){
			  cout<<"* ";
			  c--;
			}
		   }	
		}
		count=0;
		temp=temp-1;
		cout<<endl;
	}
	return 0;
}
		  