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


	//first we need to find the prime factors uptill root(n)

	int size=floor(sqrt(n))+7;
	vector<int> seive(size , 1);
	
	seive[0]=0;seive[1]=0;


	for(int i=2;(i*i)<size;i++){
		if(seive[i]==1){
			for(int j=(i*i);j<size;j+=i){
				seive[j]=0;
			}
		}
	}

	vector<int> primelist;
	for(int i=0;i<size;i++){
		if(seive[i]==1){primelist.push_back(i);}
	}



	vector<int> factors;

	for(int i=0;primelist[i]*primelist[i]<=n && i<primelist.size();i++){
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

	sort(factors.begin() , factors.end());
	
/*	cout<<'\n';
	for(auto x: factors){
		cout<<x<<" ";
	}
	cout<<'\n';*/

	map<int , int> factor_power;

	for(auto x:factors){
		factor_power[x]++;
	}

	int max_power=-1;

	for(auto p:factor_power){
		max_power=max(max_power , p.second);
	}

	int b=0;int power_2=1;
	while(power_2 < max_power){
		power_2*=2;
		b++;
	}

	//cout<<"b"<<" "<<b<<endl;

	int steps=b; //at least these many sqrt(operations required)
	int min_answer=1;

	bool multiply=false;
	for(auto p:factor_power){
		min_answer*=p.first;
		if(p.second != (1<<b)){multiply=true;}
	}



	if(multiply){steps++;}

	cout<<min_answer<<" "<<steps<<'\n';

	return;
}

int main(){

	//int t;
	//cin>>t;

	//while(t--){
		solve();
	//}

	return 0;
}