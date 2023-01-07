/*Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
1 <= T <= 10
2 <= V, E <= 10^3
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

//using both optimizations we will get o(vlogv +  elogv) 
//if e>v then O(logE) is the final complexity
//if V<E<<V*V that is a sparse graph and then this optimization is much better than normal o(v*v) solution

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class vertex{
public:
	int v;
	int weight;
};

bool operator<(vertex first , vertex second){
	return first.weight>second.weight;
}

int getmin(int * distance , bool * visited , int n , priority_queue<vertex>& pq){

	//int vertex=-1;

	/*for(int i=0;i<n;i++){
		if(!visited[i]){
			if( vertex==-1 || distance[i]<distance[vertex] ){
				//short circuit for the first iteration here
				vertex=i;
			}
		}
	}

	return vertex;*/
	//now we wil use priority queue

	int src=pq.top().v;
	while(visited[src]==true){
		pq.pop();
		src=pq.top().v;
	}

	//found src
	return src;

}

void djikstra(vector<vector<pair<int,int>>>& adj , int n , int * distance){

	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	//we will use priority queue 
	priority_queue<vertex> pq;

	for(int i=0;i<n;i++){
		pq.push({i , distance[i]});
	}
	//o(vlogv) step

	int count=0;

	while(count <= (n-1)){

		int src=getmin(distance , visited , n , pq);

		visited[src]=true;

		for(int i=0;i<adj[src].size();i++){
			//all neighbour visit that are unvisited
			int neighbour=adj[src][i].first;
			int neighbour_weight=adj[src][i].second;

			if(visited[neighbour]){//visited
				continue;
			}

			if( (distance[src] + neighbour_weight) < distance[neighbour]){
				distance[neighbour]=distance[src]+neighbour_weight;
				pq.push({neighbour , distance[neighbour]});
			}
		}

		count++;
	}

	//elogv step

	delete[] visited;

	return;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , e;
		cin>>n>>e;

		//we will use adjacency list
		vector<vector<pair<int,int>>> adj(n);

		for(int i=0;i<e;i++){

			int start,end,weight;
			cin>>start>>end>>weight;

			adj[start].push_back({end , weight});
			adj[end].push_back({start , weight});
		}

		int * distance=new int[n]();
		distance[0]=0; //take it as the source
		for(int i=1;i<n;i++){distance[i]=INT_MAX;}

		djikstra(adj , n , distance);

		for(int i=0;i<n;i++){
			cout<<i<<" "<<distance[i]<<endl;
		}

		delete[] distance;
	}

	return 0;
}