#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void dfs(vector<int> * graph , int n , int sv , bool * visited , stack<int>& s){

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

vector<vector<int>> kosaraju(vector<int> * graph , vector<int> * graphT , int n){

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	stack<int> s;

	vector<vector<int>> components;

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

	delete[] visited;

	return components;
}

int main(){

	int n; //number of vertices
	cin>>n;

	vector<int> * graph=new vector<int>[n]();
	vector<int> * graphT=new vector<int>[n]();  //transpose of graph

	int e;
	cin>>e;


	for(int i=0;i<e;i++){
		int start , end;
		cin>>start>>end; //directed graph

		graph[start-1].push_back(end-1);
		graphT[end-1].push_back(start-1);
	}

	vector<vector<int>> components=kosaraju(graph , graphT , n);

	for(int i=0;i<components.size();i++){
		for(int j=0;j<components[i].size();j++){
			cout<<components[i][j]+1<<" ";
		}
		cout<<endl;
	}

	delete[] graph;delete[] graphT;

	return 0;
}