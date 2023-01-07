/*

BOTTOM
Send Feedback
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.
Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).
Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.

Input Format:
First line of input will contain T(number of test case), each test case follows as.

First line will contain two space-separated integers N and M denoting the number of vertex and edges respectively.
Next M line will contain two space separated integers a, b denoting an edge from a to b.
Output Format:
For each test case output the bottom of the specified graph on a single line. 
Constraints:
1 <= T <= 50
1 <= N, M <= 10^5
Sample Input:
1
3 6
3 1
2 3
3 2
1 2
1 3
2 1
Sample Output:
1 2 3 

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void dfs(vector<int> * graph , int n , int sv , bool  * visited , stack<int>& s){
	visited[sv]=true;

	for(int i=0;i<graph[sv].size();i++){
		int neighbour=graph[sv][i];
		if(!visited[neighbour]){
			dfs(graph , n , neighbour , visited , s);
		}
	}

	s.push(sv);

	return;
}

void dfs1(vector<int> * graphT , int n , int sv , bool * visited , vector<int>& component){
	visited[sv]=true;
	component.push_back(sv);
	
	for(int i=0;i<graphT[sv].size();i++){
		int neighbour=graphT[sv][i];
		if(!visited[neighbour]){
			dfs1(graphT , n , neighbour , visited , component);
		}
	}

	return;

}

vector<int> solve(vector<int> * graph , vector<int> * graphT , int n){

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	vector<vector<int>> components;

	stack<int> s;

	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(graph , n , i , visited , s);
		}
	}

	for(int i=0;i<n;i++){visited[i]=false;}

	while(!s.empty()){
		int ele=s.top();
		s.pop();

		if(!visited[ele]){
			vector<int> component;
			dfs1(graphT , n , ele , visited , component);
			components.push_back(component);
		}
	}

	//now we have the scc of the graph
	//we will have to store the comp map for each vertex

//	cout<<endl;for(int i=0;i<components.size();i++){for(int j=0;j<components[i].size();j++){cout<<components[i][j]<<" ";}cout<<endl;}

	unordered_map<int , int> comp;

	int comp_number=0;
	for(int i=0;i<components.size();i++){
		for(int j=0;j<components[i].size();j++){
			comp.insert({components[i][j] , comp_number});
		}
		comp_number++;
	}

	unordered_map<int , int> :: iterator it;
/*	cout<<endl;
	for(it=comp.begin();it!=comp.end();it++){
		cout<<it->first+1<<" "<<it->second<<endl;
	}
*/
	vector<int> bottom;

	bool outgoing=false;

	//now we will go through each component and will check if there is outgoing edge not in component 

	for(int i=0;i<components.size();i++){
		for(int j=0;j<components[i].size();j++){
			int vertex=components[i][j];
			//cout<<endl<<"vertex is"<<vertex+1<<endl;
			for(int k=0;k<graph[vertex].size();k++){

				//cout<<graph[vertex].size()<<endl;
				if(comp[graph[vertex][k]]!=comp[vertex]){
					//this is having outgoing edge
					outgoing=true;
					break;
				}
			}
			
			if(outgoing){break;}
		}
		
		if(!outgoing){
			
			for(int j=0;j<components[i].size();j++){
				bottom.push_back(components[i][j]);

			}

		}
		outgoing=false;
	}

	

	delete[] visited;
	        sort(bottom.begin() , bottom.end());


	//cout<<endl;for(int i=0;i<bottom.size();i++){cout<<bottom[i]+1<<endl;}

	return bottom;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , m;
		cin>>n>>m;

		vector<int> * graph=new vector<int>[n]();
		vector<int> * graphT=new vector<int>[n]();

		for(int i=0;i<m;i++){
			int start , end;
			cin>>start>>end;

			graph[start-1].push_back(end-1);
			graphT[end-1].push_back(start-1);
		}

		vector<int> bottom=solve(graph , graphT , n);

		for(int i=0;i<bottom.size();i++){
			cout<<bottom[i]+1<<" ";
		}
		cout<<endl;

		delete[] graph;delete[] graphT;
	}

	return 0;
}