/* Break words
   if word length is even and greater than equal to 4 then insert space after half character of word
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string str;
	cout<<"Enter the string: ";
	getline(cin , str);
	int count = 0;
	int start = 0;
	int len = str.length();
	for(int i = 0; i < len; i++){
		if(str[i] != ' ' && (i != (len-1))){
			count++;
		}
	    else{
	    	i == len-1 ? count = count + 1 : count = count;
	        if(count % 2 == 0 && count >= 4){
		    	int mid = count/2;
		        cout<<str.substr(start,mid)<<" ";
		        cout<<str.substr(start+mid , count-mid)<<" ";
	        }
	        else cout<<str.substr(start,count)<<" ";
	        start = i+1;
	        count = 0;
		}	
	}   
}