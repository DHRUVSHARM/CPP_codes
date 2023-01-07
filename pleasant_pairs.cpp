#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;cin>>n;

		map<ll , int> index;

		long int pairs=0;

		ll * arr=new ll[n+1]();
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			index.insert({arr[i] , i});
		}

		for(int i=1;i<=n;i++){
			int x=arr[i];
			for(int j=1;j<=(2*n-1)/x;j++){
				int y=j;
				if(index.find(y)!=index.end() && index[y]!=-1 && y!=x){
					if(i+index[y] == x*y){pairs++;}
				}
			}
			index[arr[i]]=-1;
		}

		cout<<pairs<<'\n';

		delete[] arr;
	}

	return 0;
}