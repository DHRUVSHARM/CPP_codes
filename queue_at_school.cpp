#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

	int n , t;
	cin>>n>>t;

	string s;
	cin>>s;

	for(int i=0;i<t;i++){
		int j=n-1;
		while(j>=0){
			if(j-1 >= 0){
				if(s[j]=='G' & s[j-1]=='B'){
					char temp=s[j-1];
					s[j-1]=s[j];
					s[j]=temp;
					j-=2;
				}
				else{
					j--;
				}
			}
			else{
				j--;
			}
		}
	}

	cout<<s<<endl;

	return 0;
}