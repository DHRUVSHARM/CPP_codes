#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
typedef long double ld;

int mod=pow(10 , 9) + 7;

void solve(){
	//cout<<"here"<<endl;
	int n , k;
	cin>>n>>k;

	ll ans=1;

	for(int i=0;i<k;i++){
		ans=(ans * n)%mod;
	}

	cout<<ans<<endl;

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