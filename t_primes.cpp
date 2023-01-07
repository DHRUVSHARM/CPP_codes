#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int n=pow(10 , 6) + 7;

int main(){

	/*bitset<8> test;
	cout<<test<<endl;
	cout<<test[8]<<endl;*/

/*	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
*/
	/*bool * seive=new bool[1000000 + 7]();
	for(int i=0;i<1000007;i++){
		seive[i]=true;
	}*/

	bitset<n>seive;
	seive.set();

	//make seive
	//seive[0]=false;seive[1]=false;

	seive[0]=0;seive[1]=0;

	for(int i=2;(i*i)<=n;i++){
		if(seive[i]){
			for(int j=i*i;j<=n;j+=i){
				seive[j]=false;
			}
		}
	}

	int n;
	cin>>n;

	while(n--){
		long long int x;
		cin>>x;

		long long int root=sqrt(x);

		//cout<<root<<endl;

		//cout<<root * root<<endl;

		if(root*root == x && seive[root]){
			cout<<"YES"<<'\n';
		}
		else{
			cout<<"NO"<<'\n';
		}
	}

	//delete[] seive;
	return 0;
}