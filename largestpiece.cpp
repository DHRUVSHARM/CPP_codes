/*Largest Piece
Send Feedback
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Input Format :
First line will contain T(number of test cases), each test case follows as.
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Print the size of the biggest piece of '1's and no '0'sfor each test case in a newline.
Constraints:
1 <= T <= 10
1 <= N <= 1000
Sample Input :
1
2
11
01
Sample Output :
3
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int helper(char ** cake , int n , bool ** visited , int x , int y , int (&xstep)[4]  , int (&ystep)[4]){

	int count=1; //the element themself
	visited[x][y]=true;

     //cout<<endl;for(int i=0;i<n;i++){for(int j=0;j<n;j++){cout<<visited[i][j];}cout<<endl;}cout<<endl;

	for(int k=0;k<4;k++){
		//all 4 directions
		int newx=x+xstep[k];
		int newy=y+ystep[k];

		if(newx>=0 && newx<=(n-1) && newy>=0 && newy<=(n-1)){
			//in range
			if(cake[newx][newy]=='1' && !visited[newx][newy]){
				//unvisited 1 
				count=count + helper(cake , n , visited , newx , newy , xstep , ystep);
			}
		}
	}

	return count;
}

int largest(char ** cake , int n){

	int ans=0;

	bool ** visited=new bool*[n];
	for(int i=0;i<n;i++){
		visited[i]=new bool[n];
		for(int j=0;j<n;j++){
			visited[i][j]=false;
		}
	}

	int xstep[4]={0 , 1 , 0 , -1};
	int ystep[4]={1 , 0 , -1 , 0};

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(cake[i][j]=='1'){
			int smallans=helper(cake , n , visited , i , j , xstep , ystep);
			ans=max(ans , smallans);
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

		int n;
		cin>>n;

		char ** cake=new char*[n];
		for(int i=0;i<n;i++){
			cake[i]=new char[n];
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>cake[i][j];
			}
		}

		int ans=largest(cake , n);

		cout<<ans<<endl;

		for(int i=0;i<n;i++){delete[] cake[i];}delete[] cake;
	}

	return 0;
}