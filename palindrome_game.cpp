#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		string s;
		cin>>s;

		int zero_count=0;

		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){zero_count++;}
		}

		if(zero_count==1 || zero_count%2==0){cout<<"BOB"<<'\n';}
		else{cout<<"ALICE"<<'\n';}

	}

	return 0;
}