/*
Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Kruskal's algorithm.
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

//TIME COMPLEXITY WITH SIMPLE UNION FIND IS ELOGE + EV
//WITH DSU WE CAN GET O(V) TO O(LOGV)

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class DSnode{
	public:
		int data;
		int rank;
		DSnode * parent;
		DSnode(){
			this->data=0;this->rank=0;
			this->parent=NULL;
		}
};
//this describes a node in the dsu data set

class DisjointSet{
	private:
		//under the hood computation
		unordered_map<int , DSnode*> hash;
		//this will be used to convert user input to node type

		//recursive function for compression and getting parent node
		DSnode * helper(DSnode * node){
			if(node->parent == node){
				//cout<<"at top"<<node->data<<endl;
				return node;
				
			}
			//cout<<node->parent->data<<endl;
			DSnode * ans=helper(node->parent);
			node->parent=ans;
			return ans;
		}

	public:
		//can be accesed and is available to be called from objects created

		//initialize
		void initializeSet(int data){
			DSnode * node=new DSnode();
			node->data=data;
			node->rank=0;
			node->parent=node;
			hash[data]=node;
		}
		//this will return the topmost parent of the vertex passed and will do path compression in the process
		int search(int data){
			return helper(hash[data])->data;
		}
		//this will make union of two components
		void Union(int data1 , int data2){
			DSnode * parent1=helper(hash[data1]);
			DSnode * parent2=helper(hash[data2]);
			//returns the topmost parent node of both vertices
			if(parent1->data == parent2->data){
				//same parent thus, cycle
				return;
			}

			if(parent1->rank >= parent2->rank){
				if(parent1->rank == parent2->rank){
					parent1->rank = parent1->rank + 1;
					
				}
					parent2->parent=parent1;

			}

			else{
				parent1->parent=parent2;
			}
		}
};




class edge{
public:
	int start;
	int end;
	int weight;
};

bool compare(edge first , edge second){
	return first.weight<second.weight;
}

int kruskal(edge * edges , int n , int e , DisjointSet& ds){

	int mst_weight=0; //final ans

	int i=0; //pointer
	int count=0; //if count==(n-1) terminate

	int * parent=new int[n]();
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	//O(V)

	while(count <= (n-1) &&  i<e ){

		//union find
		int v1=edges[i].start;
		int v2=edges[i].end;
/*
		int parent1=v1;int parent2=v2; //topmost parents
		while(parent[parent1]!=parent1){
			parent1=parent[parent1];
		}
		while(parent[parent2]!=parent2){
			parent2=parent[parent2];
		}
*/
		//we will instead use ds to find the topmost parent of the vertices
		int parent1=ds.search(v1);
		int parent2=ds.search(v2);

		if(parent1==parent2){i++;continue; //cycle detected
		}

		//no cycle detected , can add
		mst_weight+=edges[i].weight;
		
		//parent[parent2]=parent1;
		//this union process can be done using our union function
		ds.Union(v1 , v2);

		count++;i++;
	}
	//O(EV)

	return mst_weight;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , e;
		cin>>n>>e;

		//we will use edge list to store the graph

		edge * edges=new edge[e];

		for(int i=0;i<e;i++){
			cin>>edges[i].start>>edges[i].end>>edges[i].weight;
		}

		//O(E) COMPLEXITY

		//sort the edgelist by weight
		sort(edges , edges + e , compare);
		//O(E*LOG E)

		//now we will initialize set for all vertices
		DisjointSet ds;
		for(int i=0;i<n;i++){
			ds.initializeSet(i);
		}

		int ans=kruskal(edges , n , e , ds);

		cout<<ans<<endl;

		delete[] edges;

	}

	return 0;
}