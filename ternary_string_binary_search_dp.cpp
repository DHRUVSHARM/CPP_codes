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

bool helper(vector<vector<int>>& dp , int len , string s){
	//cout<<"len is:"<<" "<<len<<endl;
	for(int i=0;(i+len-1)<s.size();i++){
		if(dp[0][i+len]-dp[0][i] > 0  &&  dp[1][i+len]-dp[1][i] > 0  &&    dp[2][i+len]-dp[2][i] > 0  ){
			return true;
		}
	}
	return false;
}

void solve(){

	string s;
	cin>>s;

	//make a dp using prefix sums for all 3 1 , 2 , 3

	vector<vector<int>> dp(3 , vector<int>(s.size()+1 , 0));

	for(int i=0;i<s.size();i++){
		dp[0][i+1]= dp[0][i] + (s[i]=='1');
		dp[1][i+1]= dp[1][i] + (s[i]=='2');
		dp[2][i+1]= dp[2][i] + (s[i]=='3');

	}

	if( dp[0][s.size()]==0 || dp[1][s.size()]==0 || dp[2][s.size()]==0 ){
		cout<<"0"<<endl;return;
	}

	/*cout<<"dp is "<<endl;

	for(int i=0;i<dp.size();i++){
		for(int j=0;j<dp[i].size();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/

	int l=0;int r=s.size();
	while(r > (l+1)){
		
		//cout<<"l"<<" "<<l<<" "<<"r"<<" "<<r<<endl;
		int mid=l + (r-l)/2;
		if(helper(dp , mid , s)){
			r=mid;
			//true , posible substring length
		}
		else{
			l=mid;
		}
	}

	cout<<r<<endl;

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