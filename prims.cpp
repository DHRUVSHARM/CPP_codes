/*Prim's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Prim's algorithm.
Input Format :
First line will contain T(number of test case), each test case follows as. 
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Weight of MST for each test case in new line.
Constraints :
1 <= T <= 10
2 <= V, E <= 10^5
1 <= wt <= 10^4
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
9
*/
//basic prims algo is 	o(v*v)


#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class pqnode{
public:
	int v;
	int w;
};

bool operator<(pqnode first , pqnode second){
	return first.w>second.w;
}

int getmin(int * weight , bool * visited , int n , priority_queue<pqnode> &pq){
	
	//cout<<endl;for(int i=0;i<n;i++){cout<<visited[i]<<"\t";}
	//cout<<endl;for(int i=0;i<n;i++){cout<<weight[i]<<"\t";}
	//cout<<endl;for(int i=0;i<n;i++){cout<<parent[i]<<"\t";}
	//cout<<endl;
/*
	int min_weight=INT_MAX;
	int vertex=-1;
	int i;
	for(i=0;i<n;i++){
		if(!visited[i]){
			if(weight[i]<min_weight){
				min_weight=weight[i];
				vertex=i;
			}
		}
	}

	//COMPLEXITY : O(V)

	*/

	int vertex;
	//now we will simply use priority queue
	while(!pq.empty()){
		vertex=pq.top().v;
		if(!visited[vertex]){pq.pop();return vertex;}
		pq.pop();
	}
	
	//o(1)
}

int prims(vector<vector<pair<int , int>>>& adj , int n){

	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	//O(V)

	int * parent=new int[n]();int * weight=new int[n]();
	parent[0]=-1; //we will start from this vertex
	weight[0]=0;

	for(int i=1;i<n;i++){
		weight[i]=INT_MAX;
	}

	//now we will create a pq to make the getmin function log(v)
	priority_queue<pqnode> pq;
	//this is a min priority queue

	for(int i=0;i<n;i++){pq.push({i , weight[i]});}

	int mst_weight=0; //final answer

	int count=0;

	while(count <= (n-1)){
//O(V)
		//first we will find the vertex with the minimum weight and not visited
		int vertex=getmin(weight , visited , n , pq);
		visited[vertex]=true;


	/*	//now we will go to all adjacent of vertex and update the weights 
		for(int i=0;i<n;i++){

			if(!visited[i] && graph[vertex][i]>0){

				if(graph[vertex][i] < weight[i]){
					weight[i]=graph[vertex][i];
					parent[i]=vertex;
				}
			}
		}
*/       
		//we will change this part as we now have adj list
		for(int i=0;i<adj[vertex].size();i++){
			//all adjacent only of vertex
			int neighbour=adj[vertex][i].first;
			int neighbour_weight=adj[vertex][i].second;

			if(!visited[neighbour]){
				//no need to check edge presence
				if( neighbour_weight < weight[neighbour]){
					weight[neighbour]=neighbour_weight;
					pq.push({neighbour , neighbour_weight});
					parent[neighbour]=vertex;

				}
			}
		}
		// now the time complexity of outer loop has become o(2*e)

		count++;
	}

	for(int i=0;i<n;i++){mst_weight+=weight[i];}
	delete[] visited;delete[] parent;delete[] weight;

	return mst_weight;

	//O(V*V) NET TIME COMPLEXITY

}

int main(){

	/*int t;
	cin>>t;

	while(t--){*/

		int n , e;
		cin>>n>>e;

/*		//adjacency matrix
		int ** graph=new int*[n];
		for(int i=0;i<n;i++){
			graph[i]=new int[n];
			for(int j=0;j<n;j++){
				graph[i][j]=0;
			}
		}
*/
		//adjacency list
		vector<vector<pair<int , int>>>adj(n);
		//first will be the vertex number , second will be the weight of the edge


		for(int i=0;i<e;i++){

			int start , end , weight;
			cin>>start>>end>>weight;
            start--;end--;
            /*if(graph[start][end]>0){
                if(weight>graph[start][end]){
                    continue;
                }
            }*/

          /*  bool handled=false;

            for(int i=0;i<adj[start].size();i++){

            	//loop to check repeating edge

            	if(adj[start][i].first == end){

            		//repeating edge found and will be handled here
            		handled=true;

            		if(adj[start][i].second <= weight ){
            			
            			//do nothing
            		}
            		else{

            			//change weight if the weight is lesser and do for reverse as well
            			adj[start][i].second=weight;
            			
            			for(int i=0;i<adj[end].size();i++){
            				if(adj[end][i].first==start){
            					adj[end][i].second=weight;
            				}
            			}

            			//done 
            		
            		}

            		break;//work done

            	}
            }

*/
/*
			graph[start][end]=weight;
			graph[end][start]=weight;
*/
//			if(!handled){
				//no duplicate
			adj[start].push_back({end , weight});
			adj[end].push_back({start , weight});

//		}


		}


		//display adj list 

		/*for(int i=0;i<adj.size();i++){
			cout<<"vertex is"<<"\t"<<i<<"\t"<<":";
			for(int j=0;j<adj[i].size();j++){
				cout<<"\t"<<"("<<adj[i][j].first<<" "<<adj[i][j].second<<")";
			}
			cout<<endl;
		}*/

		int ans=prims(adj , n);
		cout<<ans<<endl;

		//for(int i=0;i<n;i++){delete[] graph[i];}delete[] graph;
	//}

	return 0;
}