#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(string s , int start , int end){

	bool ispalindrome=true;
	int i=start;int j=end;

	while(i <= j){

		if(s[i] == s[j]){
			i++;j--;
		}
		else{
			//not palindrome
			ispalindrome=false;
			break;
		}
	}

	if(ispalindrome){return (end-start+1);}
	else{return 0;}
}

int lpalindrome(string s , int n){

	int ans=0;

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			//i..j is a substring
			int length=solve(s , i , j);
			ans=max(ans , length);
		}
	}

	return ans;
}

int main(){

	string s;
	cin>>s;

	int ans=lpalindrome(s , s.size());

	cout<<ans<<endl;

	return 0;
}