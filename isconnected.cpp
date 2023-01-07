/*
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Print "true" or "false" for each test case in new line
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
1
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
1
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void dfs(int ** graph , int n , bool * visited , int sv){

	visited[sv]=true;

	for(int i=0;i<n;i++){
		if(graph[sv][i]==1 && !visited[i]){
			dfs(graph , n , visited , i);
		}
	}

	return;
}

bool isconnected(int ** graph , int n){

	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	//we will use dfs to explore the graph
	dfs(graph , n , visited , 0);  //let us start with 0

	for(int i=0;i<n;i++){
		if(visited[i]==false){
			return false;
			//disconnected and unvisited part found
		}
	}

	delete[] visited;

	return true; //everything is visited and thus connected
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , e;
		cin>>n>>e;

		int ** graph=new int * [n];
		for(int i=0;i<n;i++){
			graph[i]=new int[n];
			for(int j=0;j<n;j++){
				graph[i][j]=0;
			}
		}

		for(int i=0;i<e;i++){
			int start , end;
			cin>>start>>end;

			graph[start][end]=1;
			graph[end][start]=1;
		}

		bool ans=isconnected(graph , n);

		if(ans){cout<<"true"<<endl;}else{cout<<"false"<<endl;}

		for(int i=0;i<n;i++){delete[] graph[i];}delete[] graph;


	}

	return 0;
}