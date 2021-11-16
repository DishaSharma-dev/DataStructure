/* Interleaving
Given two strings S (of length m) and T (of length n),
 you need to find and print out all the possible inter leavings that are possible of length (m + n).
Inter leaving means - all possible combination of characters from both strings such that 
it contain all characters from both strings and,
the respective ordering of characters of one string should remain same as in original.
Input: abc
       def
Output: abcdef
        abdcef
        abdecf
        abdefc
        adbcef
        adbecf
        adbefc
        adebcf
        adebfc
        adefbc
        dabcef
        dabecf
        dabefc
        daebcf
        daebfc
        daefbc
        deabcf
        deabfc
        deafbc
        defabc  */
        
#include <iostream>
#include <cstring>
using namespace std;

void Interleaving(char first[], char second[], string output){
	if(strlen(first) == 0 && strlen(second) == 0){
		cout<<output<<endl;
		return;
	}
	if(strlen(first) != 0){
		Interleaving(first+1,second,output+first[0]);	
	}
	if(strlen(second) != 0){
		Interleaving(first,second+1,output+second[0]);
	}
}

int main(){
	char first[100];
	char second[100];
	string output;
	cout<<"Enter the first string: ";
	cin>>first;
	cout<<"Enter the second string: ";
	cin>>second;
	cout<<"Combinations are: ";
	Interleaving(first,second,output);
}