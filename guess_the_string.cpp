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

char ask1(int index){
	char x;
	cout<<"?"<<" "<<"1"<<" "<<index<<endl;
	cin>>x;
	return x;
}

int ask2(int l , int  r){
	int x;
	cout<<"?"<<" "<<"2"<<" "<<l<<" "<<r<<endl;
	cin>>x;
	return x;
}

void solve(){

	
	int n;
	cin>>n;
	string s="";
/*
? 1 i — for a query of the first type (1≤i≤n);
? 2 l r — for a query of the second type (1≤l≤r≤n).*/

	vector<vector<int>> dp(n+1);

	for(int i=0;i<n;i++){

		if(i==0){
			//query the character
			/*cout<<"?"<<" "<<"1"<<" "<<"1"<<endl;
			char ch;
			cin>>ch;
			if(ch == 0){return;}*/
			//s+=ch;
			s+=ask1(1);
		}
		else{
			
/*			cout<<"?"<<" "<<"2"<<" "<<"1"<<" "<<i+1<<endl;
			int ans;
			cin>>ans;
			if(ans == 0){return;}
*/
			if(ask2(1,  i+1) > dp[i][1]){
				/*char ch;
				cout<<"?"<<" "<<"1"<<" "<<i+1<<endl;
				cin>>ch;*/
				//s+=ch;
				s+=ask1(i+1);
			}
			else{

			map<char , int> last;
			for(int j=0;j<s.size();j++){
				last[s[j]]=j;
			}
			vector<int> lasts;
			for(auto p:last){
				lasts.push_back(p.second);
			}
			sort(lasts.begin() , lasts.end());
			//binary search  on the previous occurences
			ll l=0;ll r=lasts.size();
			while(l+1 < r){
				ll mid= l + (r-l)/2;
				//query using mid
	/*			cout<<"?"<<" "<<"2"<<" "<<lasts[mid]+1<<" "<<i+1<<endl;
				int x;
				cin>>x;
				if(x == 0){return;}
*/
				if( ask2(lasts[mid]+1 , i+1) ==  dp[i][lasts[mid]+1] ){
					l=mid;
				}
				else{
					r=mid;
				}
			}

			s+=s[lasts[l]];
		}

	}

		//store the value of current different values 
		set<char> occ;
		dp[i+1].resize(s.size()+1);
		for(int j=s.size();j>=1;j--){
			occ.insert(s[j-1]);
			dp[i+1][j]=occ.size();
		}
	}


	cout<<"!"<<" "<<s<<endl;

	return;
}

int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//int t;
	//cin>>t;

	//while(t--){
		solve();
	//}

	return 0;
}