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

bool compare(pair<int,int>& f , pair<int,int>& s){
	return f.first > s.first;
}

void solve(){
/*
	set<int> a={1 , 10 , 25 , 3 , 5};
	int ele=*a.find(10);
	a.erase(a.find(10));
	ele=0;
	a.insert(ele);
	for(auto ele:a){
		cout<<ele<<" ";
	}
	cout<<'\n';*/

	/*
	auto cmp = [](int a, int b) { return ... };
	std::set<int, decltype(cmp)> s(cmp);
	*/

	int n;
	cin>>n;

	
	set<pair<int,int> , greater<pair<int,int>>> top;

	vector<int> a(n+1 , 0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		top.insert({a[i] , i});
	}
/*
	for(auto p:top){
		cout<<p.first<<" "<<p.second<<'\n';
	}*/

	vector<pair<int,int>> ans;

	while(!top.empty()){
		auto first_top=*top.begin();
		top.erase(top.begin());
		auto second_top=*top.begin();
		top.erase(top.begin());

		if( (first_top.first == 0)  || (second_top.first == 0) ){
			break;
		}

	  //cout<<first_top.second<<" "<<second_top.second<<'\n';
	  ans.push_back({first_top.second , second_top.second});

	  first_top.first--;second_top.first--;
	  top.insert(first_top);top.insert(second_top);
	}

	cout<<ans.size()<<'\n';
	for(auto p : ans){
		cout<<p.first<<" "<<p.second<<'\n';
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