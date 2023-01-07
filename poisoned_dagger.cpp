#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

ll helper(vector<int>& a , ll n , ll k){
	
	int i=0;ll hits=0;
	//cout<<k<<endl;
	while(i < n){
		
	
		
		if(i+1 >= n){
			
			hits+=k;
			break;
		}

		if(a[i] + k <= a[i+1]){

			hits+=k;
			

		}
		else{
			

			hits+=(a[i+1]-a[i]);
		}
		i++;

	}

	return hits;

}

void solve(){

	ll n , h;
	cin>>n>>h;

	vector<int> a(n , 0);
	for(int i=0;i<n;i++){cin>>a[i];}

	ll l=1;ll r=pow(10 , 18);

	ll ans=-1;

	while(l<=r){

		ll mid= l + (r-l)/2;

		if(helper(a , n , mid) >= h){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}

		
	}

	cout<<ans<<'\n';

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