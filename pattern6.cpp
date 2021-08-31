/*Number Pattern
1 2 3 4 
9 10 11 12
13 14 15 16
5 6 7 8
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of rows to be display: ";
	cin>>n;
	int i,j,value=0;
	int even = 2;
	int odd;
	if(n%2 == 0)
		odd = n-1;
	else
		odd = n-2;
	for(i=1;i<=n;i++){
		if(i>1){
			if(even<n){
				value = even*n;
				even+=2;	
			}
			else{
				value = odd*n;
				odd-=2;
			}
		}
		for(j=1;j<=n;j++){
			cout<<++value<<" ";
		}
		cout<<endl;
	}
	return 0;
}