/*Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 1 to V.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :

First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :
For each test case and each connected components print the connected components in sorted order in new line.
Order of connected components doesn't matter (print as you wish).
Constraints :
2 <= V <= 10000
1 <= E <= 10000
Sample Input 1:
1
4 2
2 1
4 3
Sample Output 1:
1 2 
4 3 

*/
/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> BFS(int ** graph , int n , bool * visited , int sv ){

	queue<int> pending;
	pending.push(sv);
	visited[sv]=true;

    vector<int> ans;
    
	while(!pending.empty()){
		int ele=pending.front();
		pending.pop();
		ans.push_back(ele);

		for(int i=1;i<=n;i++){
			if(graph[ele][i]==1 && !visited[i]){
				pending.push(i);
				visited[i]=true;
			}
		}
	}

	return ans;
}

void components(int ** graph , int n){

	//vector<vector<int>> finalans;  //will store the final components

	//vector<int> ans;

	bool * visited=new bool[n+1];
	for(int i=0;i<=n;i++){visited[i]=false;}

	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			vector<int> ans=BFS(graph , n , visited , i);
			sort(ans.begin() , ans.end());
            for(int i=0;i<ans.size();i++){cout<<ans[i]<<" ";}
            cout<<endl;
			//finalans.push_back(ans);
			//ans.clear();
		}
	}
    
    delete[] visited;

	return;

}

*/
/*
int main(){

	int t;
	cin>>t;

	while(t--){

		int n , e;
		cin>>n>>e;

		int ** graph=new int*[n+1];
		for(int i=0;i<=n;i++){
			graph[i]=new int[n+1];
			for(int j=0;j<=n;j++){
				graph[i][j]=0;
			}
		}

		for(int i=0;i<e;i++){
			int start , end;
			cin>>start>>end;

			graph[start][end]=1;
			graph[end][start]=1;
		}

		//vector<vector<int>> ans
        components(graph , n);

		/*for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}*/

/*		for(int i=0;i<=n;i++){delete[] graph[i];}delete[] graph;
	}

	return 0;
}
*/


/*Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 1 to V.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :

First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :
For each test case and each connected components print the connected components in sorted order in new line.
Order of connected components doesn't matter (print as you wish).
Constraints :
2 <= V <= 10000
1 <= E <= 10000
Sample Input 1:
1
4 2
2 1
4 3
Sample Output 1:
1 2 
4 3 

*/
/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int ** graph , int n , bool * visited , int sv , vector<int>& ans){

	visited[sv]=true;
	ans.push_back(sv);

	for(int i=1;i<=n;i++){
		if(graph[sv][i]==1 && !visited[i]){
			dfs(graph , n , visited , i , ans);
		}
	}

	return;
}

void components(int ** graph , int n){

	//vector<vector<int>> finalans;  //will store the final components

	//vector<int> ans;

	bool * visited=new bool[n+1];
	for(int i=0;i<=n;i++){visited[i]=false;}

	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			vector<int> ans;
			dfs(graph , n , visited , i , ans);
			sort(ans.begin() , ans.end());
			for(int i=0;i<ans.size();i++){cout<<ans[i]<<" ";}cout<<endl;
			ans.clear();
		}
	}
    
    delete[] visited;

	return;

}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , e;
		cin>>n>>e;

		int ** graph=new int*[n+1];
		for(int i=0;i<=n;i++){
			graph[i]=new int[n+1];
			for(int j=0;j<=n;j++){
				graph[i][j]=0;
			}
		}

		for(int i=0;i<e;i++){
			int start , end;
			cin>>start>>end;

			graph[start][end]=1;
			graph[end][start]=1;
		}

		//vector<vector<int>> ans
        components(graph , n);

		/*for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}*/

/*		for(int i=0;i<=n;i++){delete[] graph[i];}delete[] graph;
	}

	return 0;
}
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>>& adj , int n , bool * visited , int sv , vector<int>& ans){

	visited[sv]=true;
	ans.push_back(sv);

	for(int i=0;i<adj[sv].size();i++){
		if(!visited[adj[sv][i]]){
			dfs(adj , n , visited , adj[sv][i] , ans);
		}
	}

	return;
}

void components(vector<vector<int>>& adj , int n){

	//vector<vector<int>> finalans;  //will store the final components

	//vector<int> ans;

	bool * visited=new bool[n+1];
	for(int i=0;i<=n;i++){visited[i]=false;}

	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			vector<int> ans;
			dfs(adj , n , visited , i , ans);
			sort(ans.begin() , ans.end());
			for(int i=0;i<ans.size();i++){cout<<ans[i]<<" ";}cout<<endl;
			ans.clear();
		}
	}
    
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
		vector<vector<int>> adj(n+1);

		for(int i=0;i<e;i++){
			int start , end;
			cin>>start>>end;

			adj[start].push_back(end);
			adj[end].push_back(start);
		}

		//vector<vector<int>> ans
        components(adj , n);

		/*for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}*/

		//for(int i=0;i<=n;i++){delete[] graph[i];}delete[] graph;
	}

	return 0;
}
