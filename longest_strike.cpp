#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

void solve(){

	int n , k;
	cin>>n>>k;

	vector<int> a(n , 0);
	map<int , int> frequency;
	vector<int> good;

	for(int i=0;i<n;i++){
		cin>>a[i];
		if(frequency.find(a[i])!=frequency.end()){
			//already exists
			frequency[a[i]]++;
			
		}
		else{
			//dne
			frequency.insert({a[i] , 1});
		}

		//cout<<frequency[a[i]]<<endl;

		if(frequency[a[i]] == k ){
				good.push_back(a[i]);
		}
	}
	sort(good.begin() , good.end());
	//cout<<endl;for(int i=0;i<good.size();i++){cout<<good[i]<<" ";}cout<<endl;

	if(good.size() == 0){cout<<"-1"<<'\n';return;}
	//sort(good.begin() , good.end());

	//possible answer , break it into parts

	int ans=0;
	int lans=good[0];int rans=good[0];
	int l=good[0];

	for(int i=1;i<good.size();i++){
		if(good[i] - good[i-1] == 1){
			//increase range
			if(good[i] - l > ans){
				ans=good[i]-l;
				lans=l;
				rans=good[i];
			}
		}
		else{
			//break and restart
			l=good[i];
		}
	}

	cout<<lans<<" "<<rans<<'\n';

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