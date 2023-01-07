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

typedef long long ll;
typedef long double ld;
int mod=pow(10 , 9) + 7;
ll mx=pow(10 , 7) * 1.5 + 3;



int gcd(int a  , int b){
//complexity O(log(min(a , b)))
	while(b){
		a%=b;
		swap(a,  b);
	}
	return a;
}

void solve(){

	int n;
	cin>>n;

//cout<<n<<endl;


	vector<int> a(n , 0);
	int g=0;
	for(int i=0;i<n;i++){

		cin>>a[i];
		g=__gcd(g  , a[i]);

	//	cout<<a[i]<<" "<<i<<endl;;
		
	}

	/*int g=__gcd(a[0] , a[1]);
	//cout<<g<<endl;
	//minimum n is 2
	for(int i=2;i<n;i++){
		
		
		g=__gcd(g  , a[i]);
		
	}*/
	//cout<<g<<endl;

	//for(auto ele: a){cout<<ele<<endl;}


	//cout<<"initial gcd is"<<" "<<g<<endl;

	bool enlarge_possible=false;
	for(int i=0;i<n;i++){
		a[i]/=g;
		if(a[i]!=1){enlarge_possible=true;}
	}
	if(!enlarge_possible){cout<<"-1"<<endl;return;}



vector<int> seive(mx , 1);
vector<int> pf(mx ,  0);
vector<int> cnt(mx , 0);
	
	//for(ll i=0;i<mx;i++){seive[i]=1;}
	seive[0]=0;seive[1]=0;



	
	
	for(int i=2;i<mx;i++){
		if(seive[i]==1){
			pf[i]=i;
			if(i>10000)continue;
			for(int j=(i*i);j<mx;j+=i){
				seive[j]=0;
				pf[j]=i;
			}
		}
	}

	
	


	//for(int i=0;i<size;i++){if(seive[i]==1){primelist.push_back(i);}}

	//map<int , int> prime_factor_count;
	//this will store the number of a[i] where a prime factor occurs
//cout<<endl;
for(int k=0;k<n;k++){
	//cout<<a[k]<<endl;
	int prev=1;
	while(a[k]>1){
		//cout<<"pf"<<" "<<pf[a[k]]<<endl;
		if(pf[a[k]]!=prev){
		cnt[pf[a[k]]]++;}
		prev=pf[a[k]];
		a[k]/=pf[a[k]];
	}
//	cout<<'\n';

	

}



//int ans=0;

int ans=*max_element(cnt.begin(), cnt.end());

cout<<n-ans<<endl;

	return;
}

int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//	int t;
	//cin>>t;

	//while(t--){
		solve();
//	}

	return 0;
}