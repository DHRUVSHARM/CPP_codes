#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long double ld;

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		ld * a=new ld[n]();
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		bool possible=true;
		int steps=0;

		for(int i=n-2;i>=0;i--){

			while(a[i] >= a[i+1]){
				//make small
				if(a[i]==0){possible=false;break;}
				a[i]=floor(a[i]/2);
				steps++;
			}

			if(!possible){break;}
		}

		if(possible){cout<<steps<<endl;}
		else{cout<<"-1"<<endl;}
	}

	return 0;
}