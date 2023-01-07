#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;

	int count=0;

	while(n--){
		vector<int> a(3);
		cin>>a[0]>>a[1]>>a[2];
		int known=0;
		for(int i=0;i<3;i++){
			if(a[i]==1){known++;}
		}
		if(known>=2){count++;}
	}

	cout<<count<<endl;

	return 0;	
}