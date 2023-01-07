#include<bits/stdc++.h>
#include<iostream>
using namespace std;

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

	vector<int> a(n , 0); //our points
	vector<int> b(n , 0); //illyas points
	vector<int> count_a(101 , 0);
	//a valuse are from 0 to 100
	vector<int> count_b(101 , 0);


	for(int i=0;i<n;i++){cin>>a[i];count_a[a[i]]++;}
	for(int i=0;i<n;i++){cin>>b[i];count_b[b[i]]++;}

	int stages=0; //maximum stages to add can be n

	for(int i=0;i<=n;i++){
		int k=(n+i)-floor((n+i)/4);
		//cout<<"new size"<<" "<<n+i<<endl;
		
		//k represents the top stages which will be considered for calculation
		int illaya_score=0;int curr_stages=k;
		int j=100;

		//cout<<curr_stages<<endl;

				while(curr_stages>0 && j>=0){
					if(curr_stages>=count_b[j]){
						curr_stages-=count_b[j];
						illaya_score+=(count_b[j]*j);
					}
					else{
						illaya_score+=(curr_stages*j);
						curr_stages=0;
					}
					j--;
				}
			//	cout<<"curr"<<" "<<curr_stages<<endl;
			
		

		//you have to beat illays score to seal it
		int you_score=0;curr_stages=k;
		j=100;

					while(curr_stages>0 && j>=0){
					if(curr_stages>=count_a[j]){
						curr_stages-=count_a[j];
						you_score+=(count_a[j]*j);
					}
					else{
						you_score+=(curr_stages*j);
						curr_stages=0;
					}
					j--;
				}


			//cout<<"you"<<" "<<"ilaya"<<" "<<you_score<<" "<<illaya_score<<endl;

			
		if(you_score>=illaya_score){cout<<i<<endl;
			return;
		}

		//add another stage
		count_a[100]++;
		count_b[0]++;

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