#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;cin>>n;
		ll * arr=new ll[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr , arr+n);

		if(n==2){
			cout<<arr[0]<<" "<<arr[1]<<'\n';
		}
		else{
			ll mini=LLONG_MAX;int pos=-1;
			for(int i=1;i<n;i++){
				if(arr[i]-arr[i-1] < mini){pos=i;mini=arr[i]-arr[i-1];}
			}
			int k=pos-1;
			//mk , mk+2,mk+3.... mk+1
			cout<<arr[k]<<" ";
			for(int j=k+2;j<n;j++){cout<<arr[j]<<" ";}
			for(int j=0;j<k;j++){cout<<arr[j]<<" ";}
			cout<<arr[k+1]<<'\n';
		}

		delete[] arr;		

	}
	return 0;
}