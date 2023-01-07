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

	int n , m;
	cin>>n>>m;

	vector<int> a(n , 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	map<int,int> count;
	for(int i=0;i<n;i++){
		count[a[i]%m]++;
	}

	/*for(auto p: count){
		cout<<p.first<<" "<<p.second<<endl;
	}*/

	int ans=0; //counts the number of arrays

	for(auto &p:count){
		//visit each entry in the map
		if(p.first == 0){
			ans++;
			//only one array of all 0 modulo
		}
		else if(2*p.first==m){
			ans++;
			//central element =(m/2) for an even number, all put in one array
		}
		else if(2*p.first<m || count[m-p.first]==0){
			//if the pair is available then we cover all of them in the first half of the array, and if an element has no pair, then 
			//all occurrences of the element should be counted as separate array

			int x=count[p.first];int y=count[m-p.first];
			ans+=(1+max(0,abs(x-y)-1));

		}
	}

	cout<<ans<<'\n';

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