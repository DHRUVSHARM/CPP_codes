/*
Connected Horses
Send Feedback
You all must be familiar with the chess-board having 8 x 8 squares of alternate black and white cells. Well, here we have for you a similar N x M size board with similar arrangement of black and white cells.
A few of these cells have Horses placed over them. Each horse is unique. Now these horses are not the usual horses which could jump to any of the 8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Since this answer may be quite large, calculate in modulo 10^9+7.
Input Format:
First line contains T which is the number of test cases.
T test cases follow first line of each containing three integers N, M and Q where N,M is the size of the board and Q is the number of horses on it.
Q lines follow each containing the 2 integers, X and Y which are the coordinates of the Horses.
Output format:
For each test case, output the number of photographs taken by a photographer in new line.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
Sample Input:
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
Sample Output:
4
2
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll; 
int mod=pow(10 , 9) + 7;

void dfs(vector<int> * adj , int q , bool * isvisited , vector<int> & component , int sv){
    
    isvisited[sv]=true;
    component.push_back(sv);

    for(int i=0;i<adj[sv].size();i++){
        int neighbour=adj[sv][i];
        if(!isvisited[neighbour]){
            dfs(adj , q , isvisited , component , neighbour);
        }
    }

    return;
}

ll helper(int ** grid , int n , int m , int q , ll * factorial){

    int xdir[8]={-2 , -1 , 1 , 2 ,2,1 , -1 , -2};
    int ydir[8]={1 , 2 ,2 ,1 , -1 , -2 , -2 , -1};

    vector<int> * adj=new vector<int>[q]();

    bool ** visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }

   // cout<<"q is "<<q<<endl;

   // for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<grid[i][j]<<"\t";}cout<<endl;}cout<<endl;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //to check if step can be taken
            //mark this as visited 
            visited[i][j]=true;

            for(int k=0;k<8;k++){
                int newi=i+xdir[k];int newj=j+ydir[k];

               // cout<<endl<<newi<<"\t"<<newj<<endl;

                if(newi>=0 && newi<n && newj>=0 && newj<m && grid[newi][newj]!=-1 && grid[i][j]!=-1 && !visited[newi][newj]){
                    //found an edge for our graph
                    //cout<<endl<<newi<<"\t"<<newj<<endl;

                    adj[grid[i][j]].push_back(grid[newi][newj]);
                    adj[grid[newi][newj]].push_back(grid[i][j]);
                }

            }
            
        }
    }

   /* cout<<endl;
    for(int i=0;i<q;i++){
        cout<<i<<":\t";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }*/



    bool * isvisited=new bool[q]();
    for(int i=0;i<q;i++){
        isvisited[i]=false;
    }

    vector<vector<int>> components;

    for(int i=0;i<q;i++){
        if(!isvisited[i]){
            vector<int> component;
            dfs(adj , q , isvisited , component ,  i);
            //cout<<endl;for(int i=0;i<component.size();i++){cout<<component[i]<<"\t";}cout<<endl;
            components.push_back(component);
        }
    }

ll final_ans=1;

    for(int i=0;i<components.size();i++){
        final_ans=( final_ans * factorial[components[i].size()] )%mod;
    }

    delete[] isvisited;for(int i=0;i<n;i++){delete[] visited[i];}delete[] visited;

    return final_ans;
}

int main(){

    int t;
    cin>>t;

    int size=pow(10 , 6) + 7;
    ll * factorial=new ll[size]();
    factorial[0]=1;
    for(int i=1;i<size;i++){
        factorial[i]=(factorial[i-1] * i )%mod;
    }
    //pre processing for proper execution

    while(t--){

        int n , m , q;
        cin>>n>>m>>q;

        int ** grid=new int*[n];
        for(int i=0;i<n;i++){
            grid[i]=new int[m];
            for(int j=0;j<m;j++){
                grid[i][j]=-1;
                //-1 represents that there is no horse in that position
            }
        }

        

        int horse_num=0; //to identify the unique horses in the graph

        while(q--){
            int x , y;
            cin>>x>>y;
            //horse coordinates

            x--;y--;

            grid[x][y]=horse_num;
            horse_num++;
        }

        

        //horse num is the total number of vertices in our graph

        ll ans=helper(grid , n , m , horse_num , factorial);

        cout<<ans<<endl;

        for(int i=0;i<n;i++){delete[] grid[i];}
        delete[] grid;
    }

    delete[] factorial;

    return 0;

}