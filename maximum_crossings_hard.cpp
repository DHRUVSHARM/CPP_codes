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

ll merge(vector<int>&a , vector<int>&temp , int n , int start , int mid , int end){

	ll count=0;

	int i=start;
	int j=mid;
	int k=start;

	while(i<=(mid-1) && j<=end){
		if(a[i]<a[j]){
			//no crossing
			temp[k++]=a[i++];
		}
		else{
			//possible crossing
			temp[k++]=a[j++];
			count+=(mid-i);
		}
	}

	while(i<=(mid-1)){
		temp[k++]=a[i++];
	}
	while(j<=end){
		temp[k++]=a[j++];
	}

	for(int x=start;x<=end;x++){
		a[x]=temp[x];
	}

	return count;
}

ll mergesort(vector<int>& a , vector<int>& temp , int n , int start , int end){
	//cout<<"here";
	ll count=0;

	if(start<end){
		//cout<<"start"<<" "<<"end"<<" "<<start<<" "<<end<<endl;
		int mid=(start + end)/2;
		count+=mergesort(a , temp , n, start , mid);
		count+=mergesort(a , temp , n , mid+1 , end);
		count+=merge(a , temp , n , start , mid+1 , end);
	}

	return count;
}

void solve(){

	int n;
	cin>>n;

	vector<int> a(n , 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	//onlogn solution
	//use merge sort to count all (i<j):a[i]>=a[j]

	vector<int> temp(n , 0);
	//used for merging

	cout<<mergesort(a , temp , n , 0 , n-1)<<'\n';

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