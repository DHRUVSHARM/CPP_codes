/*
Fill the Matrix
Send Feedback
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.
You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input Format:
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Constraints:
1 ≤ T ≤ 20
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^5
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Output Format:
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Sample Input 1:
1
5 4
1 2 0
2 2 0
5 2 1
2 1 1
Sample Output 1:
no
*/
/*
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool helper(vector<int> * graph , int n , bool * visited , int sv){
	unordered_set<int> sets[2];
	queue<int> pending;

	pending.push(sv);
	sets[0].insert(sv);

	while(!pending.empty()){
		int ele=pending.front();
		visited[ele]=true;
		pending.pop();

		int set_num=sets[0].count(sv)!=0?0:1;

		for(int i=0;i<graph[sv].size();i++){
			int neighbour=graph[sv][i];
			if(sets[0].count(neighbour)==0 && sets[1].count(neighbour)==0){
				sets[1-set_num].insert(neighbour);
				pending.push(neighbour);
			}
			else{
				if(sets[set_num].count(neighbour)!=0){return false;}
			}
		}
	}

	return true;
}

bool bipartite(vector<int> * graph , int n){

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	for(int i=0;i<n;i++){
		if(!visited[i]){
			bool ans=helper(graph , n , visited , i);
			if(ans==false){ delete[] visited; return ans;}
		}
	}

	delete[] visited;
	return true;
}

int find(int  * parent , int n , int index){
	if(parent[index]==index){
		return index;
	}

	return find(parent , n , parent[index]);
}

bool solve(int ** arr , int n , vector<pair<int,int>>& filled_indices){

	//first we will do some initial check 
	for(int i=0;i<filled_indices.size();i++){
		int x=filled_indices[i].first;
		int y=filled_indices[i].second;

		//arr[x][y] is filled
		if(x==y && arr[x][y]==1){return false;}

		if(arr[y][x]!=-1 && arr[x][y]!=arr[y][x]){return false;}
	}

	//now we will combine all the zero value filled indices and will merge them
	//we will use union find for the merging
	int * parent=new int[n]();
	for(int i=0;i<n;i++){
		parent[i]=i;
	}

	for(int i=0;i<filled_indices.size();i++){
		int x=filled_indices[i].first;
		int y=filled_indices[i].second;

		//union
		if(arr[x][y]==0){
			int parentx=find(parent , n , x);
			int parenty=find(parent , n , y);

			parent[parenty]=parentx;
		}		
	}

	//now we will number the components created denoted by parent to vertices of our graph

	unordered_map<int , int> ptov;
	int vertex_num=0;int graph_size=0;
	for(int i=0;i<n;i++){
		if(parent[i]==i){ptov[i]=vertex_num;vertex_num++;graph_size++;}
	}

	//now we will add edges and build graph

	vector<int> * graph=new vector<int>[graph_size]();

	for(int i=0;i<filled_indices.size();i++){
		int x=filled_indices[i].first;
		int y=filled_indices[i].second;

		if(arr[x][y]==1){
			//to add edge
			int parentx=find(parent , n , x);
			int parenty=find(parent , n , y);

			if(parentx==parenty){return false;}

			//transform
			int start=ptov[parentx];int end=ptov[parenty];
			//add
			graph[start].push_back(end);
			graph[end].push_back(start);

		}
	}

	//now if the graph has odd cycle (ie; is not bipartite) it will be false

	bool check=bipartite(graph , graph_size);

	delete[] graph;delete[] parent;

	return check;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , q;
		cin>>n>>q;

		int ** arr=new int*[n];
		for(int i=0;i<n;i++){
			arr[i]=new int[n];
			for(int j=0;j<n;j++){
				arr[i][j]=-1;
			}
		}

		//-1 represents that the arr is empty 

		vector<pair<int,int>> filled_indices;

		for(int i=0;i<q;i++){
			int x , y , value;
			cin>>x>>y>>value;
			x--;y--;
			arr[x][y]=value;
			filled_indices.push_back({x , y});
		}

		bool ans=solve(arr , n , filled_indices);

		if(ans){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}

		for(int i=0;i<n;i++){delete[] arr[i];}delete[] arr;
	}

	return 0;
}
*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool helper(vector<int> * graph , int n , bool * visited , int sv){
	unordered_set<int> sets[2];
	queue<int> pending;

	//cout<<sv<<endl;

	pending.push(sv);
	sets[0].insert(sv);

	while(!pending.empty()){
		int ele=pending.front();
		visited[ele]=true;
		pending.pop();

		int set_num=(sets[0].count(ele)!=0)?0:1;

		for(int i=0;i<graph[ele].size();i++){
			int neighbour=graph[ele][i];
			if(sets[0].count(neighbour)==0 && sets[1].count(neighbour)==0){
				sets[1-set_num].insert(neighbour);
				pending.push(neighbour);
			}
			else{
				if(sets[set_num].count(neighbour)!=0){return false;}
			}
		}
	}

	return true;
}

bool bipartite(vector<int> * graph , int n){

	//cout<<"size"<<" "<<n<<endl;

	bool * visited=new bool[n]();
	for(int i=0;i<n;i++){
		visited[i]=false;
	}

	for(int i=0;i<n;i++){
		if(!visited[i]){
			bool ans=helper(graph , n , visited , i);
	//		cout<<"subans"<<" "<<ans<<endl;
			if(ans==false){  return ans;}
		}
	}

	delete[] visited;
	return true;
}

int find(int  * parent , int n , int index){
	if(parent[index]==index){
		return index;
	}

	return find(parent , n , parent[index]);
}

bool solve(int ** arr , int n , vector<pair<int,int>>& filled_indices){



	//now we will combine all the zero value filled indices and will merge them
	//we will use union find for the merging
	int * parent=new int[n]();
	for(int i=0;i<n;i++){
		parent[i]=i;
	}

	for(int i=0;i<filled_indices.size();i++){
		int x=filled_indices[i].first;
		int y=filled_indices[i].second;

		//union
		if(arr[x][y]==0){
			int parentx=find(parent , n , x);
			int parenty=find(parent , n , y);

			parent[parenty]=parentx;
		}		
	}

	//cout<<"parent"<<endl;for(int i=0;i<n;i++){cout<<i+1<<"\t"<<parent[i]+1<<endl;}cout<<endl;

	//now we will number the components created denoted by parent to vertices of our graph

	unordered_map<int , int> ptov;
	int vertex_num=0;int graph_size=0;
	for(int i=0;i<n;i++){
		if(parent[i]==i){ptov.insert({i , vertex_num});
            vertex_num++;graph_size++;}
	}

	//cout<<"ptov"<<endl;unordered_map<int,int>::iterator it;
	//for(it=ptov.begin();it!=ptov.end();it++){cout<<it->first+1<<"\t"<<it->second<<endl;}cout<<endl;

	//now we will add edges and build graph

	vector<int> * graph=new vector<int>[graph_size]();

	for(int i=0;i<filled_indices.size();i++){
		int x=filled_indices[i].first;
		int y=filled_indices[i].second;

		if(arr[x][y]==1){
			//to add edge
			int parentx=find(parent , n , x);
			int parenty=find(parent , n , y);

			if(parentx==parenty){return false;}

			//transform
			int start=ptov[parentx];int end=ptov[parenty];
	//		cout<<"edge added"<<" "<<start<<" "<<end<<endl;
			//add
			graph[start].push_back(end);
			graph[end].push_back(start);

		}
	}

	//now if the graph has odd cycle (ie; is not bipartite) it will be false

	bool check=bipartite(graph , graph_size);

	delete[] graph;delete[] parent;

	return check;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , q;
		cin>>n>>q;

		int ** arr=new int*[n];
		for(int i=0;i<n;i++){
			arr[i]=new int[n];
			for(int j=0;j<n;j++){
				arr[i][j]=-1;
			}
		}

		//array is too large

		//-1 represents that the arr is empty 

		vector<pair<int,int>> filled_indices;
        
        bool flag=true;

		for(int i=0;i<q;i++){
			int x , y , value;
			cin>>x>>y>>value;
			x--;y--;
            
            int start , end;
            start=min(x , y);end=max(x , y);
            if(arr[start][end]!=-1){
                //already filled
                if(arr[start][end]!=value){flag=false;}
            }
            else{
                //not filled fill it
                arr[start][end]=value;
		 		filled_indices.push_back({start , end});
                
            }
            //diagonal ones will be handled in union and rest checked
        }

        //cout<<"here"<<endl;

      //  cout<<endl;cout<<"filled_indices"<<endl;
       // for(int i=0;i<filled_indices.size();i++){cout<<filled_indices[i].first+1<<" "<<filled_indices[i].second+1<<endl;}

        bool ans;
        if(flag==false){ans=false;}
	    else{ans=solve(arr , n , filled_indices);}
        
		if(ans){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}

		for(int i=0;i<n;i++){delete[] arr[i];}delete[] arr;
	}

	return 0;
}