#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//seive for prime generation

/*	const int n=pow(10 , 5) + 7;
	bitset<n> seive;
	seive.set();

	seive[0]=0;seive[1]=0;

	for(int i=2;(i*i)<=n;i++){
		if(seive[i]){
			for(int j=(i*i);j<=n;j+=i){
				seive[j]=0;
			}
		}
	}
*/

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

void solve(){

	int n , k;
	cin>>n>>k;

	//k is the number of moves available to us

	string s;
	cin>>s;

	char mx='a'; //this represents the optimal value to reach from 
	//s[i] ,for best answer. initially the approach is to get the first letter
	//to be a. or exhaust k in the process

	char ch1='x';char ch2='x';
	//just filler values,  can be any value represents nothing as of now

	for(int i=0;i<n;i++){
		//go from left to right to make maximum difference lexicographically
		//we check if there is a requirement to make a move
		if( s[i]-mx  <=  0  ){
			//already converted or value is already mx
			s[i]='a';
			//this means that either this is already a or this has been converted
			//already because of a previous index with higher value was->a 
		}
		else{

		if(k>0){

			//only do something if move is possible
			int diff=s[i]-mx;

			if(k>=diff){
				//can go to a
				//max will change as further i only have to go to this value
				//to get to a 
				mx=max(mx , s[i]);
				s[i]='a';
				k-=diff;
			}
			else{
				//cannot fo to a , exhaust k here and set range
				ch2=s[i];
				s[i]-=k;
				ch1=s[i]; //new value which is not a, will have to deal separately
				//cannot be dealt with mx only as there is 2 variable range
				k=0; //exhausted
			}
		}
	}

		//cout<<"k is "<<" "<<k<<endl;
	}

	//deal with the cases where ch1 , ch2 were assigned
	for(int i=0;i<n;i++){
		if(s[i]>=ch1 && s[i]<=ch2){s[i]=ch1;}
	}

	cout<<s<<'\n';

	return;
}

int main(){

	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}