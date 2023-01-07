#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
typedef long double ld;

int solve(string s){

	int ans=9;int count0=0;int count1=0;double rem0=0;double rem1=0;
	//even win
	for(int i=0;i<s.size();i++){
		if(i%2==0){
			if(s[i]=='1' || s[i]=='?'){
				count0++;
			}
		}
		else{
			if(s[i]=='1'){count1++;}
		}

		rem0=(9-i)/2;rem1=(10-i)/2;

		if( (count1>count0+rem0) || (count0>count1+rem1) ){
			ans=min(ans , i);
		}
	}

	//odd win
	count0=0;count1=0;rem0=0;rem1=0;
	//even win
	for(int i=0;i<s.size();i++){
		if(i%2!=0){
			if(s[i]=='1' || s[i]=='?'){
				count1++;
			}
		}
		else{
			if(s[i]=='1'){count0++;}
		}

		rem0=(9-i)/2;rem1=(10-i)/2;

		if( (count1>count0+rem0) || (count0>count1+rem1) ){
			ans=min(ans , i);
		}
	}

	return ans+1;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		string s;
		cin>>s;

		int ans=solve(s);

		cout<<ans<<'\n';
	}

	return 0;
}