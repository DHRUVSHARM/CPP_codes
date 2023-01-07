#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

int helper(vector<int>& p , int n , int target){

	int ans=-1;

	int l=0;int r=n-1;

	while(l<=r){
		int mid=l + (r-l)/2;
		if(p[mid]>=target){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}

	if(ans==-1){return -1;}
	else{
		return ans+1;
	}
}

void solve(){

	int n , q;
	cin>>n>>q;

	vector<int> a(n , 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	sort(a.begin() , a.end() , greater<int>());


	vector<int> p(n , 0);
	p[0]=a[0];
	for(int i=1;i<n;i++){
		p[i]=a[i]+p[i-1];
	}

	

	/*for(int i=0;i<n;i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;*/



	while(q--){

		int target;
		cin>>target;

		int ans=helper(p , n , target);

		cout<<ans<<'\n';
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