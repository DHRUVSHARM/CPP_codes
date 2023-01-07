/*Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 0 to N - 1) and M pair of integers (u and v) denoting island, u is connected to island v and vice versa. Can you count the number of connected groups of islands?

Input Format:

The first line of input will contain T(number of test cases), each test case follows as.
Line 1: Two Integers N and M (separated by space)
Next 'M' lines, each have two space-separated integers, 'u' and 'v', denoting that there exists an edge between Vertex 'u' and Vertex 'v'.


Output Format:
Print number of Islands for each test case in new line.
Constraints:
1 <= T <= 10
1 <= N <= 1000
1 <= M <= min((N*(N-1))/2, 1000)  //number of edges
0 <= u[i] ,v[i] < N
Output Return Format :
The count the number of connected groups of islands
Sample Input :
1
2 1
0 1
Sample Output :
1 

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void dfs(int ** graph , int n , bool * visited , int sv){

	visited[sv]=true;

	for(int i=0;i<n;i++){

		if(graph[sv][i]==1 && !visited[i]){
			dfs(graph , n , visited , i);
		}
	}

	return;
}

int islands(int ** graph , int n){

	//we will use dfs
	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	int groups=0; //initially

	for(int i=0;i<n;i++){
		if(visited[i]==false){
			dfs(graph , n , visited , i);
			groups++;
		}
	}

	return groups;
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
			int start , end;
			cin>>start>>end;

			graph[start][end]=1;
			graph[end][start]=1;
		}

		int ans=islands(graph , n);
		cout<<ans<<endl;

		for(int i=0;i<n;i++){delete[] graph[i];}delete[] graph;

	}

	return 0;
}