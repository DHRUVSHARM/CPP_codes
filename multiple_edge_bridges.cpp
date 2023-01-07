#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class edgenode{
public:
	int start;
	int end;
	int weight;
	int index;
};

void dfs(vector<vector<pair<int,int>>>& adj , int n , bool * visited , bool * isbridge , int * in , int * low , int sv , int & timer , int edgecount){

	visited[sv]=true;
	in[sv]=timer;low[sv]=timer;
	timer++;

	for(int i=0;i<adj[sv].size();i++){
		int neighbour=adj[sv][i].first;
		int neighbour_count=adj[sv][i].second;

		if(neighbour_count == edgecount){continue; 
		//this is the parent
		}

		if(visited[neighbour]){
			//backedge
			low[sv]=min(low[sv] , in[neighbour]);
		}
		else{

			//dfs on unvisited
			dfs(adj , n , visited , isbridge, in,low,neighbour,timer,neighbour_count);
			low[sv]=min(low[sv] , low[neighbour]);
		}
	
}

	if(edgecount!=0){if(in[sv]==low[sv]){ isbridge[edgecount]=true; }}

}

void find_bridges(vector<vector<pair<int,int>>> &adj , edgenode * edges , int n , int m){

	
	for(int i=0;i<adj.size();i++){
		cout<<i<<":"<<"\t";
		for(int j=0;j<adj[i].size();j++){
			cout<<" ( "<<adj[i][j].first<<" "<<adj[i][j].second<<" ) ";
		}
		cout<<endl;
	}

	bool * visited=new bool[n]();
	bool * isbridge=new bool[m+1]();
	for(int i=0;i<n;i++){visited[i]=false;isbridge[i]=false;}
	isbridge[n]=false;

	int * in=new int[n]();int * low=new int[n]();
	int timer=0;
    
    //starting vertex is 0
	//dfs(adj , n , visited , isbridge , in , low , 0 , timer , 0);

	for(int i=0;i<n;i++){
		if(!visited[i]){
	       dfs(adj , n , visited , isbridge , in , low , i , timer , 0);

		}
	}

	

	for(int i=1;i<=m;i++){cout<<i<<" "<<isbridge[i]<<endl;}


	for(int i=0;i<m;i++){
		//cout<<edges[i].index<<endl;
		if( isbridge[edges[i].index] ){

			cout<<"bridge between"<<" "<<edges[i].start<<" "<<edges[i].end<<endl;

		}
	}

	delete[] visited;delete[] isbridge;delete[] in;delete[] low;
}

int main(){

	//0 based indexing for the graph

	int n , m;
	cin>>n>>m;

	edgenode * edges=new edgenode[m]();
	vector<vector<pair<int,int>>> adj(n);

	for(int i=0;i<m;i++){
		int s , e , w;
		cin>>s>>e>>w;

		edges[i].start=s;edges[i].end=e;edges[i].weight=w;edges[i].index=i+1;
		adj[s].push_back({e , i+1});
		adj[e].push_back({s , i+1});
	}

	find_bridges(adj , edges , n , m);

	delete[] edges;

	return 0;
}