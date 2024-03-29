/*Check permutation 
Two strings are said to be a permutation of each other when either of the string's characters can be rearranged 
so that it becomes identical to the other one.
str1 = string
str2 = trsgin (true)
*/

#include <iostream>
using namespace std;
int anagram(char str1[], char str2[])
{
    int i, flag = 0,  x[26] = {0}, y[26] = {0};
    for(i = 0; str1[i] != '\0'; i++)
        x[str1[i] - 'a']++;
    for(i = 0; str2[i] != '\0'; i++)
        y[str2[i] - 'a']++;
    for (i = 0; i < 26; i++)
    {
        if (x[i] != y[i])
            flag = 1; 
    }
    if (flag == 1)
        cout << "Entered strings are not anagrams.";
    else
        cout << "Entered strings are anagrams.";
}
 
int main ()
{
    char str1[50], str2[50];
    int flag;
    cout << "Enter string 1 : ";
    cin>>str1;
    cout << "Enter string 2 : ";
    cin>>str2;
    anagram(str1, str2);
    return 0;
}

//Second approach
/*
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char alpha[256] = {0};
	char str1[50];
	char str2[50];
	int flag = 0;
	cout<<"Enter the String1: ";
	cin>>str1;
	cout<<"Enter the String2: ";
	cin>>str2;
	if(strlen(str1) != strlen(str2)){
		cout<<"false";
	}
	else{
		for(int i=0;str1[i]!='\0';i++){
			int index = str1[i];
			alpha[index]++;
		}
		for(int i=0;str2[i]!='\0';i++){
			int index = str2[i];
			alpha[index]--;
		}
		for(int i=0;i<256;i++){
			if(alpha[i]!=0){
				flag = 1;
				break;
			}
		}
	}
	if(flag == 1) cout<<"false";
	else cout<<"true";
	return 0;
}
*/