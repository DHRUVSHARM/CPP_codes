/*Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.

Sample Input 1 :
1
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :

*/

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> * getpathbfs(int ** graph , int n , int v1 , int v2){

	bool * visited=new bool[n];
	for(int i=0;i<n;i++){visited[i]=false;}
	//will be used as a map
	int * parent=new int[10000 + 7]();
	for(int i=0;i<(10000 + 7);i++){
		parent[i]=-1;
	}

	int * level=new int[10000 + 7]();
	for(int i=0;i<(10000 + 7);i++){
		level[i]=-1;
	}

	queue<int> pending;
	pending.push(v1);
	visited[v1]=true;
	level[v1]=0;

	int ele;

	while(!pending.empty()){

		ele=pending.front();
		pending.pop();
		if(ele == v2){break;}

		for(int i=0;i<n;i++){
			if(graph[ele][i] == 1  &&  !visited[i]){
				level[i]=level[ele]+1;
				parent[i]=ele;
				visited[i]=true;
				pending.push(i);
			}
		}
	}

	if(ele!=v2){
		return NULL;
	}

	vector<int> * ans=new vector<int>();

	int x=v2;
	while(x!=v1){
		ans->push_back(x);
		x=parent[x];
	}
	ans->push_back(x);

	cout<<endl;for(int i=0;i<9;i++){cout<<i<<"\t"<<parent[i]<<"\t"<<level[i]<<endl;}

	delete[] visited;delete[] parent;delete[] level;

	return ans;						
}

int main(){

/*	Input Format :
First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space) for each test case in new line.
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1*/

	int t;
	cin>>t;

	while(t--){

		int n,e;
		cin>>n>>e;

		int ** graph=new int*[n];
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

		int v1 , v2;
		cin>>v1>>v2;

		vector<int> * ans=getpathbfs(graph , n , v1 , v2);
		if(ans!=NULL){for(int i=0;i<ans->size();i++){cout<<ans->at(i)<<" ";}cout<<endl;}

		for(int i=0;i<n;i++){
			delete[] graph[i];
		}
		delete[] graph;

	}

	return 0;
}


/*
1
8 10
0 1
0 3
1 2
3 4
3 5
4 5
4 6
5 6
5 7
7 6
0 7
*/