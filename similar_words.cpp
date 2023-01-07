#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

void solve(){

	int n , m;
	cin>>n>>m;

	vector<string> s;

	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		s.push_back(x);
	}

	int diff=INT_MAX;

	for(int i=0;i<s.size()-1;i++){
		for(int j=i+1;j<s.size();j++){
			//all pairs
			int k=0;int curr_diff=0;
			while(k<m){
				curr_diff+=abs(s[i][k]-s[j][k]);
				k++;
			}
			diff=min(diff , curr_diff);
		}
	}

	cout<<diff<<'\n';

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