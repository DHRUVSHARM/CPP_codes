#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){

	int n , k;
	cin>>n>>k;

	if(n%2 != 0){
		//odd
		cout<<(n/2)<<" "<<(n/2)<<" "<<"1"<<'\n';
	}
	else{
		//even
		if(n%4 == 0){
			cout<<(n/2)<<" "<<(n/4)<<" "<<(n/4)<<'\n';

		}
		else{
			cout<<(n/2)-1<<" "<<(n/2)-1<<" "<<"2"<<'\n';

		}
	}

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