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

	int n;
	cin>>n;

	vector<long> a;
	int negative=0;int positive=0;int zeroes=0;
	map<long , bool> exist;

	for(int i=0;i<n;i++){
		long ele;cin>>ele;
		exist[ele]=true;
		if(ele == 0){
			zeroes++;
			if(zeroes < 3){a.push_back(ele);}
			continue;
		}

		a.push_back(ele);
		if(ele < 0){negative++;}
		else if(ele > 0){positive++;}
	}

	if(negative > 2  || positive > 2){cout<<"NO"<<'\n';return;}

	//zeroes=0;
	//vector<ll> temp;
	//no need for more thann three zeroes if they exist 

//	unordered_map<ll , bool> exist;

	/*for(auto ele : a){
		if(ele == 0){
			if(zeroes < 3){
				temp.push_back(ele);
				exist[ele]=true;
				zeroes++;
			}
		}
		else{
			temp.push_back(ele);
			exist[ele]=true;
		}
	}*/

	//for(auto ele : a){cout<<ele<<" ";}cout<<'\n';
	n=a.size();
	for(int i=0;i<(n-2);i++){
		for(int j=i+1;j<(n-1);j++){
			for(int k=(j+1);k<n;k++){
				long curr=a[i] + a[j] + a[k];
				//cout<<i<<" "<<j<<" "<<k<<endl;
				if(!exist[curr]){cout<<"NO"<<'\n';return;}
			}
		}
	}

	cout<<"YES"<<'\n';

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