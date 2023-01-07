#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long double ld;
typedef long long ll;

int main(){

	int n;
	ld k , x;
	cin>>n>>k>>x;

	ll * arr=new ll[n]();
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	sort(arr , arr+n);

	ld stable_groups=0;
	stable_groups++;//first element added
	vector<ld> diff;

	for(int i=1;i<n;i++){
		if(arr[i]-arr[i-1]<=x){
			//can be added

		}
		else{
			//cannot
			diff.push_back(arr[i]-arr[i-1]);
			stable_groups++;
		}
	}
	sort(diff.begin() , diff.end());
	//cout<<stable_groups<<endl;
	//for(int i=0;i<diff.size();i++){cout<<diff[i]<<" ";}cout<<endl;

	for(int i=0;i<diff.size();i++){
		if(ceil(diff[i]/x)-1 <= k){stable_groups--;k-=(ceil(diff[i]/x)-1);}
	//	cout<<k<<endl;
	}

	delete[] arr;cout<<stable_groups<<'\n';

	return 0;
}