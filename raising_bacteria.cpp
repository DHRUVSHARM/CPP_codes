#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	
	int x;
	cin>>x;

	int num=0;

	while(x>0){
		//cout<<x<<endl;
		int b=x&1;

		if(b==1){
			num++;
		}

		x=x>>1;
	}

	cout<<num;

	return 0;
}