#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;
/*
void solve(){

	return;
}
*/
int main(){

/*	int t;
	cin>>t;

	while(t--){
		solve();
	}
*/	

/*	bitset<4> seive;*/
/*	seive[3]=1;*/
//	cout<<seive<<'\n';

	const int n=8;
	

	bitset<n> seive;
	seive.set();

	seive[0]=0;seive[1]=0;

	for(int i=2;(i*i)<=n;i++){
		if(seive[i]){
			for(int j=(i*i);j<=n;j+=i){
				seive[j]=0;
			}
		}
	}

	if(seive[7]){cout<<"prime";}else{cout<<"false";}

	return 0;
}