#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;

	int x=0;

	while(n--){

		string s;
		cin>>s;

		for(int i=0;i<s.size();i++){
			if(s[i]=='+'){
				++x;

				break;
			}
			if(s[i]=='-'){
				--x;
				break;
			}
		}
	}

	cout<<x<<endl;

	return 0;
}