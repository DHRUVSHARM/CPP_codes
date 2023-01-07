#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
	vector<int> primelist;
	for(int i=0;i<=x;i++){
		if(seive[i]==1){primelist.push_back(i);}
	}

	vector<int> factors;

	for(int i=0;primelist[i]*primelist[i]<=x && i<primelist.size();i++){
		if(x%primelist[i]==0){
			while(x%primelist[i]==0){
				x/=primelist[i];
				factors.push_back(primelist[i]);
			}
		}
	}
	if(x>1){
	factors.push_back(x);
}

	sort(factors.begin() , factors.end());
*/

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
//using the seive the time complexity becomes n(log(log(n)))  
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

	int n;
	cin>>n;

	vector<int> a(n , 0);
	for(int i=0;i<n;i++){cin>>a[i];}

	int m;
	cin>>m;

	vector<int> b(m , 0);
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
		int index=0;
	for(int j=0;j<m;j++){
		index=(index + b[j])%n;
	}

	cout<<a[index]<<'\n';

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