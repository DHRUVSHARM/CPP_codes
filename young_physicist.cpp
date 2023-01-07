#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;

	int x_net=0;int y_net=0;int z_net=0;

	while(n--){
		int xi,yi,zi;
		cin>>xi>>yi>>zi;

		x_net+=xi;y_net+=yi;z_net+=zi;
	}

	if(!x_net && !y_net && !z_net){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

	return 0;
}