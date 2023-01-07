/*Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0, for each test case in a new line
Constraints :
1 <= T <= 10
1 <= N <= 1000
1 <= M <= 1000
Sample Input :
1
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool helper(char ** grid , int n , int m , string target , int i , int x , int y , int (&xstep)[8] , int (&ystep)[8] , bool ** visited  ){

	if(i==target.size()-1){
		//you have found it
		return true;
	}

	bool ans=false;

	visited[x][y]=true;

	//cout<<endl;for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<visited[i][j];}cout<<endl;}cout<<endl;

	for(int k=0;k<8;k++){
		int newx=x+xstep[k];
		int newy=y+ystep[k];

		if(newx >= 0 && newx <= n-1 && newy >= 0 && newy <= m-1){

			if(grid[newx][newy]==target[i+1] && !visited[newx][newy]){
				ans=helper(grid , n , m , target , i+1 , newx , newy , xstep , ystep , visited);
				if(ans==true){break;}
			}
		}
	}

	visited[x][y]=false;

	return ans;
}

bool solve(char ** grid , int n , int m){

	bool ** visited=new bool*[n];
	for(int i=0;i<n;i++){
		visited[i]=new bool[m];
		for(int j=0;j<m;j++){
			visited[i][j]=false;
		}
	}

	string target="CODINGNINJA"; //what we have to find 

	int xstep[8]={0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
	int ystep[8]={1 , 1 , 0 , -1 , -1 , -1 , 0 , 1};

	//recursive helper call

	//helper(grid , n , m , target , i , x , y , visited);

	bool ans=false; //final answer

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//look for a C
			if(grid[i][j]=='C'){
				ans=helper(grid , n , m , target , 0 , i , j , xstep , ystep , visited);

	//			cout<<endl;for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<visited[i][j];}cout<<endl;}cout<<endl;

				if(ans==true){return ans;}
			}
		}
	}



	for(int i=0;i<n;i++){delete[] visited[i];}delete[] visited;

	return ans;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , m;
		cin>>n>>m;  //nxm matrix

		char ** grid=new char*[n];
		for(int i=0;i<n;i++){
			grid[i]=new char[m];

		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>grid[i][j];
			}
		}

		bool ans=solve(grid , n , m);

		cout<<ans<<endl;

		for(int i=0;i<n;i++){delete[] grid[i];}delete[] grid;
	}

	return 0;
}