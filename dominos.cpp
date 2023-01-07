/*
Dominos
Send Feedback
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.

Input Format:
The first line of input contains one integer T, specifying the number of test cases to follow.
Each test case begins with a line containing two integers
The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case.
The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Constraints:
1 <= T <= 50
1 <= N, M <= 10^5
Output Format:
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input 1:
1
3 2
1 2
2 3
Sample Output 2:
1
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;



void dfs(vector<int> * graph ,int n , bool * visited , int sv , stack<int>& s , bool use){
	visited[sv]=true;

	for(int i=0;i<graph[sv].size();i++){
		int neighbour=graph[sv][i];
		if(!visited[neighbour]){
			dfs(graph , n , visited , neighbour , s , use);
		}
	}

	if(use){
		s.push(sv);
	}

	return;
}

int dominos(vector<int> * graph , int n){

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	int count=0;

	stack<int> s;

	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(graph , n , visited , i , s , true);
		}
	}

	for(int i=0;i<n;i++){visited[i]=false;}

	while(!s.empty()){
		int ele=s.top();
		s.pop();

		if(!visited[ele]){
			count++;
			dfs(graph , n , visited , ele , s, false);
		}
	}

/*	for(int i=0;i<n;i++){
		//pick the largest degree starting vertex
		if(!visited[starting[i].first]){
			//push required
	//		cout<<"starting vertes is "<<starting[i].first+1<<endl;
			dfs(graph , n , visited , starting[i].first);
	//		cout<<endl;for(int i=0;i<n;i++){cout<<visited[i]<<" ";}cout<<endl;
			count++;
		}
	}
	*/

	delete[] visited;
	return count;
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

			graph[start-1].push_back(end-1); //directed graph
		}

		//now we will store the graph in increasing order of degree
/*
		pair<int , int> * starting=new pair<int , int>[n]();
		for(int i=0;i<n;i++){
			starting[i]={i , graph[i].size()};
		}
*/
		//sort(starting , starting + n , compare);

		//cout<<endl;for(int i=0;i<n;i++){cout<<starting[i].first+1<<" "<<starting[i].second<<endl;}cout<<endl;

		int ans=dominos(graph , n);

		cout<<ans<<endl;

		delete[] graph;
		//delete[] starting;
	}

	return 0;
}