#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int manacher(string s , int n){

	//we have to apply the algorithm for both odd and even
	//odd
	int * d1=new int[n]();
	
	int l=-1;int r=-1;
	for(int i=0;i<n;i++){
		if(i>r){
			d1[i]=1;
			while( (i-d1[i])>=0 && (i+d1[i])<n && s[i+d1[i]]==s[i-d1[i]] ){
				d1[i]++;
			}
			if(i+d1[i] > r){
				l=i;
				r=i+d1[i]-1;
			}
		}
		else{
			int k=(l-(i-l));
		//	cout<<endl<<"k"<<" "<<i<<" "<<k<<endl;
			if(d1[k] + i -1 < r){
				d1[i]=d1[k];
			}
			else{
				
				d1[i]=d1[k];
		//cout<<endl<<i<<" "<<d1[i]<<endl;

				while( (i-d1[i])>=0 && (i+d1[i])<n && s[i+d1[i]]==s[i-d1[i]] ){
				d1[i]++;
				}
		//cout<<endl<<i<<" "<<d1[i]<<endl;

				if(i+d1[i]-1 > r){
				l=i;
				r=i+d1[i]-1;
				}

			}
		}


	}

	l=-1;r=-1;
	int * d2=new int[n]();

	//even

	for(int i=0;i<n;i++){

		if(i>r){
			d2[i]=0;
			while( (i-d2[i]-1)>=0 && (i+d2[i])<n && s[i-d2[i]-1]==s[i+d2[i]] ){
				d2[i]++;
			}
			if(i+d2[i]-1 > r){
				l=i-d2[i];
				r=i+d2[i]-1;
			}
		}
		else{
			int k=l+(r-i)+1;
			if(d2[k] + i -1 < r){
				d2[i]=d2[k];
			}
			else{
				d2[i]=d2[k];
			}

			while( (i-d2[i]-1)>=0 && (i+d2[i])<n && s[i-d2[i]-1]==s[i+d2[i]] ){
				d2[i]++;
			}
			if(i+d2[i]-1 > r){
				l=i-d2[i];
				r=i+d2[i]-1;
			}
		}
	}

	int ans=0;
	for(int i=0;i<n;i++){
		ans=max( ans , max( 2*d1[i]-1 , 2*d2[i] ) );
	}
/*
	cout<<endl;
	cout<<"d1 is: "<<endl;
	for(int i=0;i<n;i++){cout<<d1[i]<<" ";}

	cout<<endl;
	cout<<"d2 is: "<<endl;
	for(int i=0;i<n;i++){cout<<d2[i]<<" ";}
	cout<<endl;
*/
	delete[] d1;delete[] d2;
	
	return ans;
}

int main(){

	string s;
	cin>>s;

	int n=s.size();

	int ans=manacher(s , n);

	cout<<ans<<endl;

	return 0;
}