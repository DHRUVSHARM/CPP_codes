/*Code : BFS Traversal
Send Feedback
Given an undirected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note :
1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void printbfs(int ** graph , int n , bool * visited , int sv){

	queue<int> pending;
	pending.push(sv);
	visited[sv]=true;

	while(!pending.empty()){

		int ele=pending.front();
		pending.pop();
		cout<<ele<<" ";

		for(int i=0;i<n;i++){

			if( !visited[i] && graph[ele][i]==1 ){
				pending.push(i);
				visited[i]=true;
			}
		}
	}

	return;
}

void BFS(int ** graph , int n){

	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	for(int i=0;i<n;i++){
		if(visited[i]==false){
			printbfs(graph , n , visited , i);
		}
	}

	delete[] visited;

	return;
}


int main(){

	int n, e;
	cin>>n>>e;

	int ** graph=new int*[n];
	for(int i=0;i<n;i++){
		graph[i]=new int[n];
		for(int j=0;j<n;j++){
			graph[i][j]=0;
		}
	}

	for(int i=0;i<e;i++){
		int start,end;
		cin>>start>>end;

		graph[start][end]=1;
		graph[end][start]=1;
	}

	BFS(graph , n);

	for(int i=0;i<n;i++){
		delete[] graph[i];
	}
	delete[] graph;

	return 0;	
}