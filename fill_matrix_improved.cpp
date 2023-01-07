/*
Fill the Matrix
Send Feedback
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.
You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input Format:
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Constraints:
1 ≤ T ≤ 20
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^5
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Output Format:
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Sample Input 1:
1
5 4
1 2 0
2 2 0
5 2 1
2 1 1
Sample Output 1:
no
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool cancolor(vector<vector<int>>& adj , int n , map<pair<int,int> , int>& type , int sv , int * color){

	color[sv]=0; //color our sv
	queue<int> q;
	q.push(sv);

	while(!q.empty()){
		int ele=q.front();
		q.pop();

		for(int i=0;i<adj[ele].size();i++){
			int neighbour=adj[ele][i];
			int c=type[{min(ele , neighbour) , max(ele , neighbour)}];

			if(color[neighbour]==-1){
				//uncolored can assign
				if(c==0){
					color[neighbour]=color[ele];
					//put same , merge
				}
				else{
					color[neighbour]=1-color[ele];
					//put opposite
				}
                q.push(neighbour);
			}
			else{
				//already colored check if it is colored properly if not break and false
				if(abs(color[ele]-color[neighbour])!=c){
					//this covers the diagonal 1 case and also the unequal transpose again
					return false;
				}
			}
		}

	}

	return true;
}

bool solve(vector<vector<int>>& adj , int n , map<pair<int,int> , int>& type){

	int * color=new int[n]();
	for(int i=0;i<n;i++){
		color[i]=-1;
	}

	//-1 indicates that the vertex has not been colored yet

	for(int i=0;i<n;i++){
		if(color[i]==-1 &&  adj[i].size()>=1 ){
			bool ans=cancolor(adj , n , type , i , color);
			if(!ans){return false;}
		}
	}

	return true;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , q;
		cin>>n>>q;

		bool ans=true; //final ans

		map<pair<int , int> , int> type;
		vector<vector<int>> adj(n);

		for(int i=0;i<q;i++){

			int x , y , value;
			cin>>x>>y>>value;

			x--;y--;

			adj[x].push_back(y);
			adj[y].push_back(x);

			int start=min(x , y);int end=max(x , y);

			if(type.find({start , end})!=type.end()){
				//the input already exists
				if(type[{start , end}]!=value){
					ans=false;
				}
			}
			else{
				//input does not exist
				type[{start , end}]=value;
			}
		}

		if(ans==false){
			cout<<"no"<<endl;continue;
		}

		ans=solve(adj , n, type);

		if(ans){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}

	}

	return 0;
}