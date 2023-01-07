#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;

	int odd=0;int even=0;

	int * arr=new int[n+1]();

	for(int i=1;i<=n;i++){

		cin>>arr[i];
		if(arr[i]%2==0){even++;}else{odd++;}
	}

	bool check_even;

	if(even == 1){check_even=true;}else{check_even=false;}

	for(int i=1;i<=n;i++){
		if(check_even){
			if(arr[i]%2==0){cout<<i<<endl;break;}
		}
		else{
			if(arr[i]%2!=0){cout<<i<<endl;break;}
		}
	}
	delete[] arr;
	return 0;
}