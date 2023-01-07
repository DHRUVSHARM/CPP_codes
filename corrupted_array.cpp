#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//seive for prime generation

/*	const int n=pow(10 , 5) + 7;
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
*/

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

void solve(){

	int n;
	cin>>n;

	vector<ll> b(n+3 , 0);

	for(int i=1;i<=(n+2);i++){
		cin>>b[i];
	}

	sort(b.begin() , b.end());

	//we have to output a if it is possible

	//considering that x>=sum(a)
	ll sum_n=0;
	for(int i=1;i<=n;i++){sum_n+=b[i];}

	if(sum_n == b[n+1]){
		for(int i=1;i<=n;i++){
			cout<<b[i]<<" ";
		}
		cout<<'\n';
		return;
	}

	//now consider x<sum(a)
	sum_n+=b[n+1];
	//now find x
	for(int x=1;x<=(n+1);x++){
		if(sum_n-b[x] == b[n+2]){
			for(int i=1;i<x;i++){
				cout<<b[i]<<" ";
			}
			for(int i=x+1;i<=(n+1);i++){
				cout<<b[i]<<" ";
			}
			cout<<'\n';
			return;
		}
	}

	//not possible 
	cout<<"-1"<<'\n';

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