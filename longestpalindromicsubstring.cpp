#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int longpalindrome(string s , int n){

	int length=0;
	int l ,r;

	for(int i=0;i<n;i++){

		//odd
		l=i;r=i;
		while(l>=0 && r<n && s[l]==s[r]){
			length=max(length , (r-l+1));
			l--;r++;
		}

		//even
		l=i;r=i+1;
		while(l>=0 && r<n && s[l]==s[r]){
			length=max(length , (r-l+1));
			l--;r++;
		}
	}

	return length;
}

int main(){

	string s;
	cin>>s;

	int ans=longpalindrome(s , s.size());

	cout<<ans<<endl;

	return 0;
}