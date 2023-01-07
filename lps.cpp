#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int * getlps(string pattern){

	if(pattern.size()<=1){return NULL;}

	int n=pattern.size();

	int * lps=new int[n]();

	lps[0]=0;

	int i=1;int j=0;

	while(i<n){

		if(pattern[i]==pattern[j]){
			lps[i]=j+1;
			i++;j++;
		}
		else{
			//not equal
			if(j!=0){
				j--;
				j=lps[j];
			}
			else{
				lps[i]=0;i++;
			}
		}
	}

	return lps;
}

int main(){

	string pattern;
	cin>>pattern;

	int * lps=getlps(pattern);

	cout<<endl;for(int i=0;i<lps.size();i++){cout<<lps[i]<<" ";}cout<<endl;

	return 0;
}