#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;

int main(){

	int t;
	cin>>t;

	while(t--){

		ll a , b , c , x , y;
		cin>>a>>b>>c>>x>>y;

		x-=a;
		y-=b;
		if(x<0){x=0;}if(y<0){y=0;}

		if(c < (x+y)){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}

	}

	return 0;
}