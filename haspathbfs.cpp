/*Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
First line will contain T(number of test cases), each test case as follow.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false for each test case in a newline.
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
1
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false*/

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

bool haspathbfs(int ** graph , int n , bool* visited , int v1 , int v2){

	bool ans=false;

	queue<int> pending;
	pending.push(v1);
	visited[v1]=true;

	while(!pending.empty()){

		int ele=pending.front();
		pending.pop();
		if(ele == v2){
			//reached our destination
			ans=true;
			break;
		}

		for(int i=0;i<n;i++){
			if(graph[ele][i]==1 && !visited[i]){
				pending.push(i);
				visited[i]=true;
			}
		}
	}

	return ans;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , e;
		cin>>n>>e;

		int ** graph=new int*[n];
		for(int i=0;i<n;i++){
			graph[i]=new int[n];
			for(int j=0;j<n;j++){
				graph[i][j]=0;
			}
		}

		for(int i=0;i<e;i++){
			int start, end;
			cin>>start>>end;

			graph[start][end]=1;
			graph[end][start]=1;
		}

		int v1 , v2;
		cin>>v1>>v2;

		bool * visited=new bool[n];
		for(int i=0;i<n;i++){
			visited[i]=false;
		}

		bool ans=haspathbfs(graph , n , visited , v1 , v2);

		if(ans){cout<<"true"<<endl;}else{cout<<"false"<<endl;}


    	for(int i=0;i<n;i++){
    	delete[] graph[i];
   		 	}
    	delete[] graph;
    	delete[] visited;
}

			

	return 0;
	
}