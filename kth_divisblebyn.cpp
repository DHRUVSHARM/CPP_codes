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

	ll n , k;
	cin>>n>>k;
	//kth num not divisible by n

	ll l=1;ll r=2*pow(10 , 9);

	while(l<=r){
    //cout<<l<<" "<<r<<'\n';
		ll mid= l + (r-l)/2;
		//first we will find how many values not divisible by n 
		//are till mid
		ll curr_k=mid - floor(mid/n);
		//cout<<"curr k is"<<" "<<curr_k<<endl;
    if(curr_k == k){
    	if(mid%n!=0){
    		cout<<mid<<'\n';return;
    	}
    	r=mid-1;
    }
    else if(curr_k < k){
    	l=mid+1;
    }
    else{
    	r=mid-1;
    }
	}

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