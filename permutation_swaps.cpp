/*
Permutation Swaps
Send Feedback
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.
He also believes that there are M good pairs of integers (ai, bi). Kevin can perform following operation with his permutation:
Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.

Input format:
The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
Output format:
For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N
Time Limit: 1 second
Sample Input 1:
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
Sample Output 1:
NO 
YES
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void dfs(vector<int> * adj , int n , bool * visited , vector<int>& component , int sv){
	
	visited[sv]=true;
	component.push_back(sv);

	for(int i=0;i<adj[sv].size();i++){
		int neighbour=adj[sv][i];
		if(!visited[neighbour]){
			dfs(adj , n , visited , component , neighbour);
		}
	}

	return;
}

bool permutation(int * p , int * q , int n , vector<int> * adj){

	vector<vector<int>> components;

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	for(int i=0;i<n;i++){
		if(!visited[i]){
			vector<int> component;
			dfs(adj , n , visited , component , i);
			components.push_back(component);
		}
	}

	bool * isoccur=new bool[n]();
	for(int i=0;i<n;i++){
		isoccur[i]=false;
	}

	for(int i=0;i<components.size();i++){
		
		for(int j=0;j<components[i].size();j++){
			//markr the indexed values in the component in p
			int index=components[i][j];
			isoccur[p[index]]=true;
		}

		for(int j=0;j<components[i].size();j++){
			int index=components[i][j];
			if(isoccur[q[index]]==false){return false;}
		}		
	}

	delete[] visited;delete[] isoccur;

	return true;

}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , m;
		cin>>n>>m;

		int * p=new int[n]();  //given permutation 
		int * q=new int[n]();  //permutation to reach using swaps

		for(int i=0;i<n;i++){
			cin>>p[i];
			p[i]--;
		}

		for(int i=0;i<n;i++){
			cin>>q[i];
			q[i]--;
		}

		vector<int> * adj=new vector<int>[n]();

		for(int i=0;i<m;i++){
			//good pairs
			int start , end;
			cin>>start>>end;
			start--;end--;

			adj[start].push_back(end);
			adj[end].push_back(start);
		}

		bool ans=permutation(p , q , n , adj);

		if(ans){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}

		delete[] p;delete[] q;delete[] adj;				

	}

	return 0;
}