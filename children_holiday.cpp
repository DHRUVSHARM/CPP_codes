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

/*
to prevent precision based issues in ld comparision:
diff>=0.000000000001
--> not equal
*/

int mod=1000000007;

typedef long long ll;
typedef long double ld;

int helper(vector< pair<pair<int,int>,int> >& a , int n , int m , int time){

	ll balon=0LL;

	for(int i=0;i<n;i++){
		int t=a[i].first.first;
		int z=a[i].first.second;
		int y=a[i].second;

		ll curr_balon=0LL;
		curr_balon+= (time / (z*t + y))*z;
		int rem=time%(z*t+y);
		curr_balon+=min( (rem/t) , z );

		balon+=curr_balon;
		//temp[i]=curr_balon;

	}

		/*for(auto ele : temp){
		cout<<ele<<" ";
	}
	cout<<endl;
*/
	return balon >= m;


}

void solve(){

	int m , n;
	cin>>m>>n;

	vector< pair<pair<int,int>,int> > a(n);

	int tmax=INT_MIN;
	int zmax=0;
	int ymax=0;

	for(int i=0;i<n;i++){
		int t , z , y;
		cin>>t>>z>>y;

		if(tmax < t){
			tmax=t;;
			zmax=z;
			ymax=y;
		}

		a[i]={{t , z} , y};
	}


	/*cout<<"workers"<<endl;
	for(auto p : a){
		int t=p.first.first;
		int z=p.first.second;
		int y=p.second;

		cout<<t<<" "<<z<<" "<<y<<endl;
	}*/

	int l=-1;
	int r= (m/zmax  +  1) * ( zmax*tmax + ymax ); 
	//int r=1000000000;

	while( l + 1 < r){
		
		int mid=l + (r-l)/2;
		if(helper(a ,n, m , mid)){
			r=mid;
		}
		else{
			l=mid;
		}

	}

	cout<<r<<'\n';
	/*
		for(int i=0;i<n;i++){
		cout<<work[i]<<" ";
	}
	cout<<'\n';
*/
	
	vector<int> work(n , 0);

		for(int i=0;i<n;i++){
		int t=a[i].first.first;
		int z=a[i].first.second;
		int y=a[i].second;

		ll curr_balon=0LL;
		curr_balon+= (r / (z*t + y))*z;
		int rem=r%(z*t+y);
		curr_balon+=min( (rem/t) , z );

		if(m >= curr_balon){
			work[i]=curr_balon;
			m-=curr_balon;
		}
		else{
			work[i]+=(m);
			m=0;
			break;
		}

		//temp[i]=curr_balon;

	}

	for(int i=0;i<n;i++){
		cout<<work[i]<<" ";
	}
	cout<<'\n';

	//cout<<"here"<<'\n';



	return;
}

int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//	int t;
//	cin>>t;

//	while(t--){
		solve();
//	}

	return 0;
}