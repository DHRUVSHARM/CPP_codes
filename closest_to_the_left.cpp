#include<bits/stdc++.h>
#include<iostream>
using namespace std;

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

void solve(vector<int>& a , int n , int x){

	//to get max i:a[i]<=x
	//other wise you have to return 0

	int l=-1;int r=n;
	//loop invariant: a[l]<=x , a[r]>x

	//to get min i: a[i]>=x
	//loop invariantL: a[l]<x ,  a[r]>=x

	while(r>l+1){
		int mid=l + (r-l)/2;
		if(a[mid]>=x){
			r=mid;
		}
		else{
			l=mid;
		}
	}

	if(r==n){
		cout<<n+1<<'\n';
	}
	else{
		cout<<r+1<<'\n';
	}

	return;
}

int main(){

	int n , t;
	cin>>n>>t;

	vector<int> a(n , 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	//int t;
	//cin>>t;

	while(t--){
		
		int x;
		cin>>x;

		solve(a , n , x);
	}

	return 0;
}