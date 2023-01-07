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


bool helper(vector<pair<ll,int>>& ans , int pos){
	ll acc=0;
	acc+=ans[pos].first;

	int j=0;
	for(;j<ans.size();j++){

		if(j==pos){continue;}
		if( acc < ans[j].first ){break;}
		acc+=ans[j].first;
	}

	if(j == ans.size()){
		return true;

	}
	else{
		return false;
	}
}

void solve(){
/*
	//binary search solution

	int n;
	cin>>n;

	vector<pair<ll,int>> a(n , {0,-1});
	for(int i=0;i<n;i++){
		ll ele;
		cin>>ele;
		a[i]={ele , i};
	}

	//fffftttt type bin search

	sort(a.begin() , a.end());
/*
	for(auto p:a){
		cout<<"ele"<<" "<<p.first<<" "<<"index"<<" "<<p.second<<'\n';
	}
*/
/*
	int  l=-1;
	int r=(n-1); //last element of sorted array will always win

	while( (l+1) < r ){
		int  mid=l + (r-l)/2;
		//cout<<"mid"<<" "<<mid<<endl;
		if(helper(a , mid)){
			r=mid;
		}
		else{
			l=mid;
		}
	}

	//cout<<r<<endl;

	vector<int> ans;

	for(int i=r;i<n;i++){
		ans.push_back(a[i].second + 1);
	}

	sort(ans.begin() , ans.end());

	cout<<ans.size()<<'\n';

	for(auto ele: ans){
		cout<<ele<<" ";
	}
	cout<<'\n';*/

	//linear solution

	int  n;
	cin>>n;

	vector<pair<ll,int>> a(n+1 , {0 , -1});
	vector<ll> prefix(n+1 , 0LL);
	for(int i=1;i<=n;i++){
		int ele;
		cin>>ele;

		a[i]={ele , i};
	//	prefix[i]=a[i].first + prefix[i-1];
	}

	sort(a.begin() , a.end());

	for(int i=1;i<=n;i++){
		prefix[i]=a[i].first + prefix[i-1];
	}
	int i=(n);
	for(;i>=1;i--){
		if(i==n){continue;}
		if(prefix[i] < a[i+1].first){break;}
	}
	i++;
	vector<int> ans;
	for(int j=i;j<=n;j++){
		ans.push_back(a[j].second);
	}

	sort(ans.begin() , ans.end());

	cout<<ans.size()<<'\n';
	for(auto ele : ans){
		cout<<ele<<" ";
	}
	cout<<'\n';

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