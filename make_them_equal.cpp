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

	int n;char c;
	cin>>n>>c;

	string s;
	cin>>s;

	bool check=true;

	for(int i=0;i<s.size();i++){
		if(s[i]!=c){
			check=false;
			break;
		}
	}

	if(check){cout<<"0"<<'\n'; 
//no need to make any move
	return;
}

	//now we will check if the conversion can happen in 1 move
	//for all possible x: 1<=x<=n
//if for any x we see that all it's ,multiples are equal to c

	for(int i=1;i<=n;i++){
		bool one_move=true;
		for(int j=1;(i*j)<=n;j++){
			if(s[i*j - 1]!=c){
				one_move=false;
				break;
			}
		}
		if(one_move){cout<<"1"<<'\n'<<i<<'\n';return;}
	}

	//now we need to use 2 moves , which is guaranteed for the conversion
	cout<<"2"<<'\n';
	cout<<s.size()<<" "<<s.size()-1<<'\n';

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