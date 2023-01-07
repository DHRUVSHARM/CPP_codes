#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void dfs(vector<int> * graph , int n , int sv , int parent , int * in , int * low , bool * visited , int& timer){

	visited[sv]=true;
	in[sv]=timer;
	low[sv]=timer;
	timer++;

	for(int i=0;i<graph[sv].size();i++){
		int neighbour=graph[sv][i];

		if(neighbour==parent){continue;}

		if(visited[neighbour]){

			//cycle forming edge , can never be a bridge
			low[sv]=min(low[sv] , in[neighbour]);
		}
		else{

			dfs(graph,n,neighbour,sv,in,low,visited,timer);
			//now for this case we need to check if the edge forms a bridge
			//before that you can also update the sv low value
			//if in[sv]>low[neighbour] -> neigbour has a path to an ancestor of sv so removing edge makes no
			//break in connectivity; note that you can reach to sv from that ancestor
			//if in[sv]==low[neigbour] -> neighbour has a path to the sv itself so again same as above

			low[sv]=min(low[sv] , low[neighbour]);

			if(in[sv]<low[neighbour]){
				cout<<"bridge between "<<" "<<sv<<" "<<neighbour<<endl;
				
			}

		}
	}
}

void bridges(vector<int> * graph , int n){

	int * in=new int[n](); 
	int * low=new int[n]();

	int timer=0;

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	dfs(graph , n ,  0 , -1 , in , low , visited  , timer);

	cout<<"status of the edges at the end are as:"<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<":"<<" "<<in[i]<<" "<<low[i]<<endl;
	}

	delete[] in;delete[] low;delete[] visited;

	
}

int main(){

	int n , m;
	cin>>n>>m;

	vector<int> * graph=new vector<int>[n]();

	//assume 0 based indexing

	for(int i=0;i<m;i++){
		int start , end;
		cin>>start>>end;

		graph[start].push_back(end);
		graph[end].push_back(start); 
	}

	bridges(graph , n);

	delete[] graph;

	return 0;
}