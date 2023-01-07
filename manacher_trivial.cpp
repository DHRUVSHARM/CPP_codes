#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int trivial(string s){

	int n=s.size();

	int * d1=new int[n]();
	int * d2=new int[n]();

	int ans=0;

	for(int i=0;i<n;i++){
		//expand
		d1[i]=1;
		while( (i-d1[i])>=0 && (i+d1[i])<n && (s[i-d1[i]] == s[i+d1[i]]) ){
			d1[i]++;
		}
		ans=max(ans , (2*d1[i] - 1));
		//odd answer

		d2[i]=0;
		while( (i-d2[i]-1)>=0 && (i+d2[i])<n &&  (s[i-d2[i]-1]==s[i+d2[i]])  ){
			d2[i]++;
		}
		ans=max(ans  , 2*d2[i]);
		//even
	}

/*
	cout<<endl;
	cout<<"d1 is: "<<endl;
	for(int i=0;i<n;i++){cout<<d1[i]<<" ";}

	cout<<endl;
	cout<<"d2 is: "<<endl;
	for(int i=0;i<n;i++){cout<<d2[i]<<" ";}
*/
	delete[] d1;delete[] d2;

	return ans;
}

int main(){

	string s;
	cin>>s;

	int ans=trivial(s);
	cout<<ans;

	return 0;
}