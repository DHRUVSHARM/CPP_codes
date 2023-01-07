#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int mod=pow(10 , 9) + 7;

typedef long long ll;
typedef long double ld;

void helper(int** board , int n , int m , int x , int y , int& curr_ans , int xdir , int ydir){

	if(x<0 || x>=n || y<0 || y>=m){
		return;
	}

	curr_ans+=board[x][y];

	helper(board,n,m,x+xdir,y+ydir,curr_ans,xdir,ydir);

	return;

}

void solve(){
//cout<<"here";
	int n , m;
	cin>>n>>m;

	int ** board=new int*[n];
	for(int i=0;i<n;i++){
		board[i]=new int[m];
		for(int j=0;j<m;j++){
			cin>>board[i][j];
		}
	}


	int max_p=INT_MIN;
//cout<<"here";

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int curr_ans=0;
			//position
			int xd[4] ={1 , 1 , -1 , -1};
			int yd[4]={1 , -1 , -1 , 1};

			int x=i;
			int y=j;

			curr_ans+=board[i][j];

			for(int k=0;k<4;k++){
				helper(board , n , m , x + xd[k] , y + yd[k] , curr_ans , xd[k] , yd[k]);
			}

			max_p=max(max_p , curr_ans);
		}
	}
//cout<<"here";
	cout<<max_p<<'\n';

	for(int i=0;i<n;i++){delete[] board[i];}delete[] board;

	return;
}

int main(){
//cout<<"here";
	int t;
	cin>>t;

	while(t--){
		//cout<<"here";
		solve();
		//cout<<"here";
	}

	return 0;
}