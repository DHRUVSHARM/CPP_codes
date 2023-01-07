/*
Monk and the Islands
Send Feedback
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input format:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output format:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
Sample Input
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
Sample Output
2
2
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool bfs(vector<int> * graph , int * level , int n , bool * visited , int sv){

	queue<int> pending;
	pending.push(sv);
	level[sv]=0;
	visited[sv]=true;

	while(!pending.empty()){
		int ele=pending.front();
		pending.pop();
		if(ele==n-1){return true;}
		for(int i=0;i<graph[ele].size();i++){
			int neighbour=graph[ele][i];
			if(!visited[neighbour]){
				level[neighbour]=level[ele]+1;
				visited[neighbour]=true;
				pending.push(neighbour);
			}
		}
	}

	return false;//not found
}

int islands(vector<int> * graph , int n){

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	int * level=new int[n]();

	bool found=bfs(graph , level , n , visited , 0);

	//cout<<endl;cout<<"level"<<endl;for(int i=0;i<n;i++){cout<<i+1<<"\t"<<level[i]<<endl;}cout<<endl;

	delete[] visited;delete[] level;

	if(found){
		return level[n-1];
	}
	else{
		return -1;
	}
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , m;
		cin>>n>>m;

		vector<int> * graph=new vector<int>[n]();

		for(int i=0;i<m;i++){
			int start , end;
			cin>>start>>end;

			graph[start-1].push_back(end-1);
			graph[end-1].push_back(start-1);
		}

		int ans=islands(graph , n);

		cout<<ans<<endl;

		delete[] graph;
	}

	return 0;
}