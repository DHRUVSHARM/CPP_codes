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
	vector<ll> primelist;
	for(ll i=2;i<=sqrt(n);i++){
		if(seive[i]==1){primelist.push_back(i);}
	}
/*
	for(auto ele : primelist){
	//	cout<<"inlist";
		cout<<ele<<" ";
	}
	cout<<endl;*/

/*	vector<ll> factors;

	for(ll i=0; i<primelist.size()  && primelist[i]*primelist[i]<=n ;i++){
		//cout<<"here"<<endl;
		if(n%primelist[i]==0){
			while(n%primelist[i]==0){
				n/=primelist[i];
				factors.push_back(primelist[i]);
			}
		}
	}

	if(n>1){
	factors.push_back(n);
}
	
	factors.push_back(1);
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
/*		int N=100000;
vector<int> seive(N , 1);
//preprocessing the primes	
void create_seive(){

seive[0]=0;seive[1]=0;

for(ll i=2;(i*i)<N;i++){
	//cout<<i<<'\n';
	//cout<<seive[i]<<'\n';
	if(seive[i]==1){
		for(ll j=(i*i);j<N;j+=i){
			seive[j]=0;
		}
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

/*
to prevent precision based issues in ld comparision:
diff>=0.000000000001
--> not equal
*/

int mod=1000000007;

typedef long long ll;
typedef long double ld;

void solve(){

	int n , k;
	cin >> n >> k;

	string s;
	cin>>s;

	vector<int> flips(s.size() , k);
	int steps = k;

	int i=0;
	while( i < s.size()  &&  steps > 0 ){

		if( k % 2 == 0 ){
			if(s[i] == '0'){
				steps--;
				flips[i]--;
			}
		}
		else{
			if(s[i] == '1'){
				steps--;
				flips[i]--;
			}
		}

		i++;
	}

	flips[s.size()-1] -= steps;
	//cout << flips[s.size()-1] <<endl;
	//cout << s[s.size()-1] <<endl;

//	int value = (s[s.size() - 1] - '0');
	
	for(int i=0;i<s.size();i++){
		s[i] = '0' +  ( (s[i] == '1') + flips[i]  )%2;
	}

//	s[s.size()-1] =  ('0' + (( (s[s.size()-1] == '1') + flips[s.size()-1] )%2)) ;



	cout << s <<'\n';
	for(int i=0;i<flips.size();i++){
		cout<< (flips[i] - k )*(-1) <<" ";
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
/*
111110
1 0 0 2 0 0 
111110
0 1 1 1 0 1 
000000
0 0 0 0 0 0 

100110
1 0 0 0 0 0 
111111
1 2 1 3 0 4 
111110
1 1 4 2 0 4
*/