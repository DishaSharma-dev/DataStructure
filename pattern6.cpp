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
	int i,j;
	int count=1;
	int start=1;
	int end = n;
	int temp=start;
	for(i=start ; i<=n; i++){
		for(j=1;j<=n;j++){
			cout<<count<<" ";
			count++;	
		}
		cout<<endl;
	}
	return 0;
}