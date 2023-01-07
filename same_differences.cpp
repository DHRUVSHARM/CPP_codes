#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long double ld;
typedef long long ll;
int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		ll * arr=new ll[n]();
		map<ll, ll> occurence;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(occurence.find(arr[i]-i)==occurence.end()){
				//not in map
				occurence.insert({arr[i]-i , 1});
			}
			else{
				//already in map
				occurence[arr[i]-i]++;
			}
		}

		ll ans=0;
		map<ll , ll>::iterator it;
		for(it=occurence.begin();it!=occurence.end();it++){
			//cout<<it->first<<" "<<it->second<<endl;
			
			ll subans=((it->second)*(it->second - 1));
			subans/=2;
			ans+=subans;
		}

		delete[] arr;
		cout<<ans<<'\n';
	}

	return 0;
}