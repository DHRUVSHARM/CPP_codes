/*
3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int cycle(int ** graph , int n){

	int count=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j && graph[i][j]==1){
				for(int k=1;k<=n;k++){
					if(k!=i && k!=j && graph[j][k]==1 && graph[k][i]==1){
						count++;
					}
				}
			}
		}
	}

	count/=6;

	return count;
}

int main(){

	int n , e;
	cin>>n>>e;

	int * u=new int[e]();
	int * v=new int[e]();

	for(int i=0;i<e;i++){
		cin>>u[i];
	}

	for(int i=0;i<e;i++){
		cin>>v[i];
	}

	int ** graph=new int*[n+1];
	for(int i=0;i<=n;i++){
		graph[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			graph[i][j]=0;
		}
	}

	for(int i=0;i<e;i++){
		graph[u[i]][v[i]]=1;
		graph[v[i]][u[i]]=1;
	}

	int ans=cycle(graph , n);

	cout<<ans<<endl;

	for(int i=0;i<=n;i++){delete[] graph[i];}delete[] graph;

	return 0;
}