/*
Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 400
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool helper(char ** grid , int n,int m, bool** visited, char target ,int x,int y,int sx,int sy,int (&xstep)[4] , int (&ystep)[4] , int count ){

	visited[x][y]=true;
	bool ans=false;

   // cout<<endl;for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<visited[i][j];}cout<<endl;}cout<<endl;

	for(int k=0;k<4;k++){
		int newx=x+xstep[k];
		int newy=y+ystep[k];

		if(newx>=0 && newx<=(n-1) && newy>=0 && newy<=(m-1)){
			//in range
			if(newx==sx && newy==sy && count>=4){//cout<<"cycle"<<endl;
			return true;}
			if(grid[newx][newy]==target && !visited[newx][newy]){
				ans=helper(grid,n,m,visited,target,newx,newy,sx,sy,xstep,ystep,count+1);
				if(ans==true){break;}
			}
		}
	}

	visited[x][y]=false;
	return ans;
}

bool connectdots(char ** grid , int n , int m){

	bool ** visited=new bool*[n];
	for(int i=0;i<n;i++){
		visited[i]=new bool[m];
		for(int j=0;j<m;j++){
			visited[i][j]=false;
		}
	}

	bool ans=false; //final answer

	int xstep[4]={0 , 1 , 0 , -1};
	int ystep[4]={1 , 0 , -1 , 0};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//int k=0;
			ans=helper(grid , n , m , visited , grid[i][j] , i , j , i , j , xstep,ystep , 1);
			if(ans==true){return ans;}
		}
	}

	return ans;
}

int main(){

	int n , m;
	cin>>n>>m;

	char ** grid=new char*[n];
	for(int i=0;i<n;i++){
		grid[i]=new char[m];

	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}

	//cout<<endl;

	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<grid[i][j];
		}
		cout<<endl;
	}*/

	bool ans=connectdots(grid , n , m);

	cout<<ans<<endl;

	return 0;

}