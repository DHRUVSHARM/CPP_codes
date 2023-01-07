#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printdfs(int ** graph , int sv , int n , bool * visited){

	cout<<sv<<endl; //printing the vertex
	visited[sv]=true;

	for(int i=0;i<n;i++){

		if(graph[sv][i] == 1  &&  !visited[i]){
			//edge exists and the vertex has not been visited
			printdfs(graph , i , n , visited);
		}
	}

	return;
}

int main(){

	int n;
	cin>>n;  //number of vertices

	int e;
	cin>>e; //number of edges

	int ** graph=new int *[n];
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
		//bidirectional
	}

	bool * visited=new bool[n];
	for(int i=0;i<n;i++){visited[i]=false;}


	//disconnected graphs are handled in main only

	for(int i=0;i<n;i++){
    
    if(visited[i]==false){

			printdfs(graph , i , n , visited); //prints in dfs style
		}

	}

	//all disconnected components are also printed

	return 0;
}