#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef unsigned long long int ll;
int main(){

	int n;
	cin>>n;

	ll * count=new ll[100000 + 7]();

	ll * arr=new ll[n]();
	for(int i=0;i<n;i++){
		cin>>arr[i];
		count[arr[i]]++;
	}

	sort(arr , arr + n);

	ll maxi=arr[n-1];

	ll * dp=new ll[maxi+1]();

	dp[0]=0;dp[1]=count[1];

	for(int i=2;i<=maxi;i++){
		dp[i]=max(dp[i-1] , count[i]*i + dp[i-2]);
	}

	cout<<dp[maxi]<<endl;

	delete[] dp;delete[] count;delete[] arr;

	return 0;
}
