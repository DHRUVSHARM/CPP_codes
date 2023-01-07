#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
to get unique elements in sorted order
  sort(fun_values.begin(),fun_values.end());
    fun_values.erase(unique(fun_values.begin(),fun_values.end()),fun_values.end());
    for(ll&x:fun_values)
        cout<<x<<" "; 

*/

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
/*		int x;
	cin>>x;

	int n=floor(sqrt(x))+7;
	vector<int> seive(n , 1);
	
	seive[0]=0;seive[1]=0;


	for(int i=2;(i*i)<n;i++){
		cout<<i<<'\n';
		cout<<seive[i]<<'\n';
		if(seive[i]==1){
			for(int j=(i*i);j<n;j+=i){
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

	vector<ll> a(n , 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int k;
	cin>>k;

	vector<ll> b(k , 0);
	for(int i=0;i<k;i++){
		cin>>b[i];
	}	

	//we can use llround for pow precision issue

	vector<pair<ll,ll>> a_exp;
	vector<pair<ll,ll>> b_exp;

	//a
	for(int i=0;i<n;i++){
		ll count=1;ll curr=a[i];
		while(curr%m == 0){
			curr/=m;
			count*=m;
		}

		if(a_exp.empty() || a_exp.back().first != curr){
			a_exp.push_back({curr , count});
		}
		else{
			a_exp.back().second+=count;
		}
	}


	//b
	for(int i=0;i<k;i++){
		ll count=1;ll curr=b[i];
		while(curr%m == 0){
			curr/=m;
			count*=m;
		}

		if(b_exp.empty() || b_exp.back().first != curr){
			b_exp.push_back({curr , count});
		}
		else{
			b_exp.back().second+=count;
		}
	}	
/*
	for(auto p : a_exp){
		cout<<"("<<p.first<<" "<<p.second<<")"<<" ";
	}
	cout<<'\n';

	for(auto p : b_exp){
		cout<<"("<<p.first<<" "<<p.second<<")"<<" ";
	}
	cout<<'\n';*/
/*
	int i=0;int j=0;
	while(i < a_exp.size() && j < b_exp.size()){
		if(a_exp[i].first != b_exp[i].first  || a_exp[i].second != b_exp[i].second){
			cout<<"No"<<'\n';return;
		}
		i++;j++;
	}

	if(i != j){cout<<"No"<<'\n';return;}*/
	//cout<<"Yes"<<'\n';

	if(a_exp == b_exp){cout<<"Yes"<<'\n';}
	else{cout<<"No"<<'\n';}


	return;
}

int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}