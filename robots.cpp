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


	int n , m;
	cin>>n>>m;

	vector<string> a;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		a.push_back(s);
	}

	vector<pair<int,int>> indices;

	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]=='R'){
				indices.push_back({i,j});
			}
		}
	}

	//if you can get atleast one index where upper and left area has no robot
	//you can reach
	
	for(int i=0;i<indices.size();i++){
		for(int j=0;j<indices.size();j++){
			if(indices[i].first > indices[j].first || indices[i].second>indices[j].second){
				//not possible from here
				goto done;
				//this robot check is done here and terminated 
			}
		}
		//if here means robot is possible to reach 0,0

		cout<<"YES"<<'\n';return;

		done:;

	}

	cout<<"NO"<<'\n';


	return;
}

int main(){

	int t;
	cin>>t;

	while(t--){
		solve();
	}

cin.clear();
cin.get();
return 0;
}