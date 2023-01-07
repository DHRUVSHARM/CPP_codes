/*Edges in MST
Send Feedback
You are given a connected weighted undirected graph without any loops and multiple edges.
Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.
Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.
Input Format:
The first line contains two space-separated integers n and m — the number of the graph's vertexes and edges, correspondingly.
 Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi", where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight.
Output Format:
Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.
Constraints:
 1 <= N, M <= 10^5
 1 <= a, b <= N
 1 <= w[i] <= 10^6
 Graph is connected and does not contain self loops and multiple edges.
Sample Input:
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
Sample Output:
none
any
at least one
at least one
any
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class edge{
public:
    int s;
    int e;
    int w;
    int index;
};

bool compare(edge e1 , edge e2){
    return e1.w<e2.w;
}

int find(int * parent , int ele){
    if(parent[ele]==ele){return ele;}
    parent[ele]=find(parent , parent[ele]); //path compression step
    return parent[ele];
}

void addedge(vector<vector<pair<int,int>>> &adj , int index , int x ,int y ,int * parent , int * ans){

    int parentx=find(parent , x);
    int parenty=find(parent , y);

    //index represents the edge number

    if(parentx == parenty){return;}

    //you have to add edge
    adj[parentx].push_back({parenty , index });
    adj[parenty].push_back({parentx , index });

    ans[index]=1;
    //now the status of this edge is atleast one
}

void dfs(vector<vector<pair<int,int>>>& adj , int sv , int edgeno , int& timer , int* in , int* low , bool * visited , int * ans){

    visited[sv]=true;
    in[sv]=timer;low[sv]=timer;
    timer++;

    for(pair<int,int> e : adj[sv]){
        int neighbour=e.first;
        int neighbour_edgeno=e.second;

        if(neighbour_edgeno == edgeno){//parent edge
            continue;
        }

        if(visited[neighbour]){
            //backedge
            low[sv]=min(low[sv] , in[neighbour]);
        }
        else{

            dfs(adj,neighbour,neighbour_edgeno,timer,in,low,visited,ans);
            low[sv]=min(low[sv] , low[neighbour]);
        }
    }

    if(edgeno != 0){
        if(in[sv]==low[sv]){ans[edgeno]=2; 
            //marked as a bridge
        }
    }
}

void merge(vector<vector<pair<int,int>>>& adj , int x , int y , int * parent , bool * visited){

    int parentx=find(parent , x);
    int parenty=find(parent , y);

    visited[parentx]=false;visited[parenty]=false;
    //have to do this before in case there are only in 0 type edges present 
    if(parentx==parenty){return;}

    adj[parentx].clear();
    adj[parenty].clear();

    parent[parenty]=parentx;


}

int main(){

    int n , m;
    cin>>n>>m;

    edge * edges=new edge[m+1](); //edgelist
    for(int i=1;i<=m;i++){
        cin>>edges[i].s>>edges[i].e>>edges[i].w;
        edges[i].index=i;
    }

    //now we sort

    sort(edges+1 , edges+m+1 , compare);

    int * ans=new int[m+1](); //stores the final answer

    vector<vector<pair<int,int>>> adj(n+1); //temporary graph

    int * parent=new int[n+1](); //to implement dsu and label connected components
    for(int i=1;i<=n;i++){parent[i]=i;}

    bool * visited=new bool[n+1]();
    for(int i=1;i<=n;i++){visited[i]=false;}

    int i=1;
    while(i<=m){
        //we will process similar weigthed elements together
        int j;
        for(j=i;(edges[i].w==edges[j].w);j++){
            //here we will add the edges to our temporary graph
            addedge(adj , edges[j].index , edges[j].s , edges[j].e , parent , ans);
        }

        int timer=0; //maintains depth of vertex
        int * in=new int[n+1]();int * low=new int[n+1]();//maintain in time and low

        for(j=i;(edges[i].w==edges[j].w);j++){
            //now we will do dfs on each connected component to mark the bridges if any
            //pickup one of the vertices of the edge and find parent
            int p=find(parent , edges[j].s);
            //cout<<p<<endl;
            if(!visited[p]){
                //perform dfs to mark bridges
                dfs(adj , p , 0 , timer , in , low , visited , ans);
            }
        }

        delete[] in;delete[] low;

        //now you will mwrge 

        for(j=i;(edges[i].w == edges[j].w);j++){

            merge(adj , edges[j].s , edges[j].e , parent , visited);
        }

        i=j;
    }

    for(int i=1;i<=m;i++){
        if(ans[i]==0){
            cout<<"none"<<endl;
        }
        else if(ans[i]==1){
            cout<<"at least one"<<endl;
        }
        else{
            cout<<"any"<<endl;
        }
    }

    delete[] edges;delete[] ans;delete[] parent;delete[] visited;

    return 0; 

}