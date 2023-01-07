/*
Floyd-Warshall Algorithm
Send Feedback
You are given an undirected weighted graph G with n vertices. And Q queries, each query consists of two integers a and b and you have print the distance of shortest path between a and b.
Note: If there is no path between a and b print 10^9
Input Format:
First line of Input will contain T(number of test cases), each test case follows as.
Line1: contains two space-separated integers N and M denoting the number of vertex and edge in graph.
Next M line contain three space-separated integers a, b, c denoting the edge between a and b with weight c.
Next line will contain Q (number of queries)
Next Q lines will contain two space-separated integers a and b.
Output Format:
For each query of each test case print the answer in a newline.
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= M <= 10^4
1 <= Q <= 10^4
1 <= wt <= 10^5 (for each edge)
Note: Graph may contain multiple edges.
Sample Input:
1
3 6
3 1 4
1 3 17
2 3 2
1 3 7
3 2 11
2 3 15
3
1 1 
2 2 
2 3 
Sample output:
0
0
2

*/

/*
1
2 2
1 2 20
1 2 14
5
2 2 
2 2 
1 1 
1 2 
2 2 
*/

/*
1
4 12
3 4 17
4 3 18
3 2 3
1 2 10
1 3 21
1 4 11
4 1 22
2 1 23
3 4 4
4 1 18
1 2 20
3 4 21
9
4 3 
2 1 
1 1 
1 3 
4 1 
3 1 
1 2 
4 3 
1 1 
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void floyd_warshall(int ** distance , int ** graph , int n){

	for(int k=0;k<n;k++){
		//add a vertex in between the following pairs
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(distance[i][k]!=INT_MAX && distance[k][j]!=INT_MAX && ((distance[i][k] + distance[k][j]) < distance[i][j]) ){
					distance[i][j]=distance[i][k] + distance[k][j];
				}
			}
		}
	}

	return;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , e;
		cin>>n>>e;

		int** graph=new int*[n];
		for(int i=0;i<n;i++){
			graph[i]=new int[n];
			for(int j=0;j<n;j++){
				if(i==j){graph[i][j]=0;continue;}
				graph[i][j]=INT_MAX;
			}
		}

		for(int i=0;i<e;i++){
			int start , end , weight;
			cin>>start>>end>>weight;

			start--;end--;

			if(graph[start][end]!=INT_MAX){
				if(weight<graph[start][end]){
					graph[start][end]=weight;
                    graph[end][start]=weight;
				}
				continue;
			}

			graph[start][end]=weight;
			graph[end][start]=weight;
		}

		int** distance=new int*[n];
		for(int i=0;i<n;i++){
			distance[i]=new int[n];
			for(int j=0;j<n;j++){
				distance[i][j]=graph[i][j];
			}
		}

		//precomputation via floyd warshall to get distance matrix
		floyd_warshall(distance , graph , n);		

		int q;
		cin>>q;

		while(q--){

			int a , b;
			cin>>a>>b;

			a--;b--;
            
            if(distance[a][b]==INT_MAX){cout<<pow(10 , 9)<<endl;continue;}
			cout<<distance[a][b]<<endl;
		}

		for(int i=0;i<n;i++){delete[] graph[i];}delete[] graph;
		for(int i=0;i<n;i++){delete[] distance[i];}delete[] distance;
	}

	return 0;
}