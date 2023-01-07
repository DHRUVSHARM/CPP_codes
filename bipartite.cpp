#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool bipartite(vector<int> * graph , int n , bool * visited , int sv){

	unordered_set<int> sets[2];
	queue<int> pending;

	pending.push(sv);
	sets[0].insert(sv);

	while(!pending.empty()){
		int ele=pending.front();
		pending.pop();
		visited[ele]=true;

		//all neighbours of element will be assigned properly

		int set_num=(sets[0].count(ele)!=0)?0:1;

		for(int i=0;i<graph[ele].size();i++){
			int neighbour=graph[ele][i];
			if(sets[0].count(neighbour)==0 && sets[1].count(neighbour)==0){
				//can assign this element has not been visited
				sets[1-set_num].insert(neighbour);
				pending.push(neighbour);
			}
			else{
				if(sets[set_num].count(neighbour)!=0){
					//in same set not bipartite
					return false;
				}
			}
		}
	}

	return true;
}

bool helper(vector<int> * graph , int n){

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	for(int i=0;i<n;i++){
		if(!visited[i]){
		   bool ans=bipartite(graph , n , visited , i);
		   if(ans==false){return false;}
		}
	}

	return true;
}

int main(){

	while(true){
		
		int n;
		cin>>n;

		if(n==0){
			break;
		}

		//vertices numbered from 0 to n-1

		vector<int> * graph=new vector<int>[n]();

		int e;
		cin>>e;

		for(int i=0;i<e;i++){
			int start , end;
			cin>>start>>end;

			graph[start].push_back(end);
			graph[end].push_back(start);
		}

		bool ans=helper(graph , n);

		if(ans){cout<<"BICOLOURABLE"<<endl;}
		else{cout<<"NOT BICOLOURABLE"<<endl;}

		delete[] graph;
	}

	return 0;
}