#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

	int ribbons[3];
	int n;

	cin>>n>>ribbons[0]>>ribbons[1]>>ribbons[2];

	int * dp=new int[n+1]();
	for(int i=1;i<=n;i++){
		dp[i]=INT_MIN;
	}
	dp[0]=0;

	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if(i-ribbons[j] >= 0){
				dp[i]=max(dp[i] , dp[i-ribbons[j]] + 1);
			}
		}
	}

	cout<<dp[n]<<'\n';
	delete[] dp;

	return 0;
}