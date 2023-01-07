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

	int n;
	cin>>n;

	ll sum=0;

	vector<ll> a(n,  0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}

	
	ld k=(ld)sum/n;
	//cout<<"k"<<" "<<k<<endl;

	if(floor(k) != ceil(k) && ceil(k) - k != 0.5){cout<<"0"<<'\n';return;}

	ll target=floor(2*k);
	//cout<<"target"<<" "<<target<<endl;

	//to get those pairs which will sum to target

	int l=0;int r=n-1;int repl=l;int repr=r;
	ll pairs=0;

	sort(a.begin() , a.end());

	while(l<r){
		
		
		while( repl<n && a[l]==a[repl] ){repl++;}
		while( repr>=0 && a[r]==a[repr] ){repr--;}
		repl--;repr++;

		if(repr<repl){
			//we are in a continuos stream of numbers that are equal 
			//from l to r
			if(a[l] + a[r] == target){
				int len=r-l+1;
				pairs=pairs + (len*(len-1))/2;
			}
			l=repl+1;r=repr-1;
		}
		else{

			if(a[l] + a[r] == target){
				ll add=(repl-l+1)*(r-repr+1);
				pairs=pairs + add;
				l=repl+1;r=repr-1;
			}
			else if(a[l] + a[r] < target){
				l=repl+1;
			}
			else{
				r=repr-1;
			}

		}

		
		repl=l;repr=r;

	}

	cout<<pairs<<'\n';

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