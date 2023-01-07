#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void dfs(vector<int> * edges , int n , bool * visited , int sv , unordered_set<int> * component){

	visited[sv]=true;
	component->insert(sv);

	for(int i=0;i<edges[sv].size();i++){
		int neighbour=edges[sv][i];
		if(!visited[neighbour]){
			dfs(edges , n , visited , neighbour , component);
		}
	}

	return;
}

unordered_set<unordered_set<int>*>* get_components(vector<int> * edges , int n){

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();

		//	unordered_set<int>* component=new unordered_set<int>();


	for(int i=0;i<n;i++){
		if(!visited[i]){
			unordered_set<int>* component=new unordered_set<int>();
			dfs(edges , n , visited , i , component);
			output->insert(component);
			//delete component;
		}
	}


	delete[] visited;
	return output;
}

void bfs(vector<int> * edges , int n  , bool * visited , int sv , vector<int>& component){

	queue<int> pending;
	visited[sv]=true;
	pending.push(sv);

	while(!pending.empty()){
		int ele=pending.front();
		component.push_back(ele);
		pending.pop();

		for(int i=0;i<edges[ele].size();i++){
			int neighbour=edges[ele][i];
			if(!visited[neighbour]){
				visited[neighbour]=true;
				pending.push(neighbour);
			}
		}
	}

	return;
}

void connected_bfs(vector<int> * edges , int n){

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){visited[i]=false;}

	vector<vector<int>> components;
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			vector<int> component;
			bfs(edges , n , visited , i , component);
			components.push_back(component);
			//component.clear();
		}
	}

	for(int i=0;i<components.size();i++){
		for(int j=0;j<components[i].size();j++){
			cout<<components[i][j]+1<<" ";
		}
		cout<<endl;
	}

	delete[] visited;

	return;
}

int main(){

	int n;
	cin>>n;

	vector<int> * edges=new vector<int>[n];

	int e;
	cin>>e;

	for(int i=0;i<e;i++){
		//converting one based vertes numbering to zero based
		int start , end;
		cin>>start>>end;

		edges[start-1].push_back(end-1);
		edges[end-1].push_back(start-1);
	}

	unordered_set<unordered_set<int>*> * components=get_components(edges , n);

	unordered_set<unordered_set<int>*> :: iterator it;

	for(it=components->begin();it!=components->end();it++){
		unordered_set<int>* component=(*it);
		unordered_set<int> :: iterator it1;
		for(it1=component->begin();it1!=component->end();it1++){
			cout<<(*it1)+1<<" ";
		}
		cout<<endl;
		delete component;
	}
	delete components;

	//also display the components using bfs
	cout<<endl;

	connected_bfs(edges , n);

	delete[] edges;

	return 0;
}