#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
	
	int n;
	cin>>n;

	string s;
	cin>>s;

	set<string> substrings;
	//it will store the substrings in alphabetical order
	//not required but still, generating all 3 length possible substrings
	for(int i=0;i<s.size();i++){
		string ss;
		for(int k=0; k<3 && i+k < s.size() ;k++){
			ss.push_back(s[i+k]);
			//cout<<ss<<'\n';
			substrings.insert(ss);
		}
	}

/*	for(auto x:substrings){
		cout<<x<<'\n';
	}
	cout<<"count"<<" "<<substrings.size()<<'\n';	
*/	

	for(int len=1;len<=3;len++){
		string t(len , 'a');
		while(true){
			if(substrings.count(t) == 0){
				cout<<t<<'\n';
				return;
			}

			int index=len-1;

			while(index>=0 && t[index]=='z'){
				t[index]='a';
				index--;
			}
			if(index<0){break;}

			t[index]++;
		}
	}

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