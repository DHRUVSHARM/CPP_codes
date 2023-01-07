#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//seive for prime generation

/*	const int n=pow(10 , 5) + 7;
	bitset<n> seive;
	seive.set();

	seive[0]=0;seive[1]=0;

	for(int i=2;(i*i)<=n;i++){
		if(seive[i]){
			for(int j=(i*i);j<=n;j+=i){
				seive[j]=0;
			}
		}
	}
*/

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

bool helper(string s , vector<int>& zero_pos , int k){
	//to check if k is a viable cost

	//cout<<"k"<<" "<<k<<endl;

	if(zero_pos.size() <= k+2){
		return true;
	}

	for(int i=0;i<zero_pos.size()-k-1;i++){
		//l and r represent the values around the selected substring
		//it can ve zero or 1 

		//cout<<"i"<<" "<<i<<endl;

		int l=zero_pos[i]+1;
		int r=zero_pos[i+1+k]-1;

		//cout<<"l"<<" "<<l<<" "<<"r"<<" "<<r<<endl;

		int in_ones,tot_ones,ones_removed;

		if(l>r){
			in_ones=0;
		}
		else{
			in_ones=r-l+1-k;
		}

		tot_ones=s.size()-zero_pos.size()+2;

		ones_removed=tot_ones-in_ones;

		if(ones_removed<=k){return true;}
		
	}
	return false;
}

void solve(){

	string s;
	cin>>s;

	//we are going to store the positions of zeroes in the string
	vector<int> zero_pos;

	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			zero_pos.push_back(i);
		}
	}

	//now push zeroes in front and back for implementation

	zero_pos.push_back(s.size());
	zero_pos.insert(zero_pos.begin() , -1);

	int k;//final answer

	//binary search over k (cost by finding remaining zeroes)

	int l=0;int r=s.size();

	while(l<=r){
		int mid=l+(r-l)/2;
		if(helper(s , zero_pos , mid)){
			//cost mid is possible
			k=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}

	cout<<k<<'\n';

	return;
}

int main(){

	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}