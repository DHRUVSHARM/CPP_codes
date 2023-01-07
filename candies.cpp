#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

void solve(){

	int n;
	cin>>n;

	vector<int> a(n , 0);

	int mini=INT_MAX;

	for(int i=0;i<n;i++){
		cin>>a[i];
		mini=min(mini , a[i]);
	}

	int eat=0;

	for(int i=0;i<n;i++){
		eat=eat + (a[i]-mini);
	}

	cout<<eat<<'\n';

	return;
}

int main(){

	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}