#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
int gcd(int a  , int b){
//complexity O(log(min(a , b)))
	while(b){
		a%=b;
		swap(a,  b);    
	}
	return a;
}
*/

//move on board
//from up clockwise all 8 directions
/*
int xdif[8]={-1,-1,0,1,1,1,0,-1};
int ydif[8]={0,1,1,1,0,-1,-1,-1};
*/

/*convert integer to string
can convert all data types to string 
string s=to_string(element);*/

/*  stringstream ss;
	string s="3.123";
	//extract the string to ss
	//then it can be put to convert type

	ss<<s;
	float converted_element;
	ss>>converted_element;

	cout<<converted_element;
*/

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

/*
//binary search
  
  //in a sorted array (inc:a[i]<=a[i+1]) 2 options
  //max(i): , a[i]<=x  , from left bound (lower bound)
  //min(i): , a[i]>=x , from right bound(upper bound)

  int l=-1;int r=n;
  while(r>l+1){
	int mid=l+(r-l)/2;

// left case : invariant a[l]<=x , a[r]>x
	if(a[mid]<=x){
		l=mid;
	}
	else{
	    r=mid;
	}

// right case: invariant a[l]<x , a[r]>=x
	if(a[mid]>=x){
		r=mid;
	}
	else{
		l=mid;
	}


  }

*/

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

void solve(){

	int count[2]={0 , 0};
	cin>>count[0]>>count[1];

	string s;
	cin>>s;

	for(int i=0;i<s.size();i++){
		if(s[i]!='?'){
			if(s[s.size()-i-1]=='?'){
				
				s[s.size()-i-1]=s[i];
			}
		 else if(s[s.size()-i-1]!=s[i]){
				cout<<"-1"<<'\n';return;
			}
		}
	}
//cout<<s<<endl;

//only question marks will be left
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){count[0]--;}
		if(s[i]=='1'){count[1]--;}
	}

	//cout<<count[0]<<" "<<count[1]<<endl;

	if(s.size()%2!=0){
		//the middle element question mark check
		int mid=(s.size()/2);
		if(s[mid]=='?'){
			if(count[0]%2!=0){s[mid]='0';count[0]--;}
			else if(count[1]%2!=0){s[mid]='1';count[1]--;}
			else{cout<<"-1"<<'\n';return;}
		}
	}

	for(int i=0;i<s.size();i++){
		if(s[i]=='?'){
			if(count[0]>=2){count[0]-=2;s[i]='0';s[s.size()-i-1]='0';}
			else if(count[1]>=2){count[1]-=2;s[i]='1';s[s.size()-i-1]='1';}
			else{
				cout<<"-1"<<'\n';return;
			}

		}
	}
	if(count[0]==0 && count[1]==0)
	{cout<<s<<'\n';}
else{cout<<"-1"<<'\n';}

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