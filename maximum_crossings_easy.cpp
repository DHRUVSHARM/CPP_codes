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

	vector<int> a(n+1 , 0);

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	//brute force 

	ll crossings=0;

	for(int i=1;i<=(n-1);i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]<=a[i]){

				crossings++;
			}
		}
	}

	cout<<crossings<<'\n';

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