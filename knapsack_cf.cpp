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

/*	6
1 1
1
1 1
2
2 1
2 1
1 1
3
2 1
1 3*/
//	cout<<"case"<<'\n';
	int n;ld w;
	cin>>n>>w;
/*1
1
-1
1
2
-1
1
1
1
1*/

	/*1
1 
-1
1
2 
-1
1
1 
-1*/

	vector<int> ans;

	vector<pair<ll , int>> a;



	for(int i=0;i<n;i++){
		ll ele;
		cin>>ele;
	
		if(ele <= w){
			a.push_back({ele , i});
		}
	}

	for(auto p : a){
		if(p.first >= ceil(w/2.0)){
			cout<<"1"<<'\n';
			cout<<p.second + 1<<'\n';
			return;
		}
	}



	//if(a.size()==0){cout<<"-1"<<'\n';return;}

	ld curr_wt=0;





	for(int i=0;i<a.size();i++){
		curr_wt+=a[i].first;
		//cout<<"curr_wt"<<" "<<curr_wt<<'\n';
		ans.push_back(a[i].second + 1);
		if(curr_wt >= ceil(w/2.0)){
			
			break;
		}
	}

	if(curr_wt >= ceil(w/2.0) && curr_wt <= w){
		cout<<ans.size()<<'\n';
		for(auto ele: ans){
			cout<<ele<<" ";
		}
		cout<<'\n';
	}
	else{
		cout<<"-1"<<'\n';
	}

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