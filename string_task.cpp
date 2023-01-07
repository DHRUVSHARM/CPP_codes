#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
int main(){

	string upper;
	cin>>upper;

	char lower=upper[0] + ('a'-'A');
	cout<<lower<<endl;

	return 0;
}
*/


int main(){

	string s;
	cin>>s;

	for(int i=0;i<s.size();i++){
		if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='Y' || s[i]=='y'  ){
			s[i]='$';
		}
		else{
			//consonant
			if(s[i]>='A' && s[i]<='Z'){
				//uppercase , to lowercase 
				s[i]=s[i]+('a'-'A');
			}
		}
	}

	string ans="";

	for(int i=0;i<s.size();i++){
		if(s[i]!='$'){
			ans=ans + '.' + s[i];
		}
	}

	cout<<ans<<endl;

	return 0;
}

