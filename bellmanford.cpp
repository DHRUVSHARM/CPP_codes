/*Bellman-Ford Algorithm
Send Feedback
you are given a weighted directed graph G with n vertices and m edges, and two specified vertex src and des. You want to find the length of shortest paths from vertex src to des. The graph may contain the edges with negative weight.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
Line1: contain two space-separated integers N and M denoting the number of vertex and number of edges in graph respectively.
Line2: contain two space-separated integers src, des.
Next M line will contain three space-separated integers a, b, wt representing the edge from a to b with weight wt.
Output Format:
For each test case print the distance of des from src in new line.
Note: In case of no path is found print (10 ^ 9) in that case.
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= min(800, N*(N-1))
1 <= a,b <= N
-10^5 <= wt <= 10^5
Sample Input:
1
3 6
3 1
3 1 -2
1 3 244
2 3 -2
2 1 201
3 2 220
1 2 223
Sample output:
-2
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class edgenode{
 public:
 	int start;
 	int end;
 	int weight;
};

int bellman_ford(edgenode * edges , int n , int e , int src, int des){

	int * distance=new int[n+1]();
	for(int i=0;i<=n;i++){
		distance[i]=INT_MAX;
	}
	distance[src]=0;

	int count=0; //this will count the max num of edges bw each pair 
	//without cycle this is  (n-1)

	int * temp=new int[n+1]();
	for(int i=0;i<=n;i++){temp[i]=distance[i];}

	while(count < (n-1)){

		//count + 1 is max edges allowed
		//each pair 
		for(int i=0;i<e;i++){
			//pick up the edge
			int sv=edges[i].start;
			int ev=edges[i].end;
			int w=edges[i].weight;

			if(distance[sv]==INT_MAX){continue; //have not yet reached this vertex from the main source
			}

			if( (distance[sv] + w) < distance[ev] ){
				//relax
				temp[ev]=distance[sv]+w;
			}
		}

		for(int i=0;i<=n;i++){distance[i]=temp[i];}

		count++;
	}

	
//code for detecting negative weighted cycle

	int * checker=new int[n+1]();
	for(int i=0;i<=n;i++){checker[i]=distance[i];} 
	
	for(int i=0;i<e;i++){

			//pick up the edge
			int sv=edges[i].start;
			int ev=edges[i].end;
			int w=edges[i].weight;

			if(checker[sv]==INT_MAX){continue; //have not yet reached this vertex from the main source
			}

			if( (checker[sv] + w) < checker[ev] ){
				//relax
				temp[ev]=checker[sv]+w;
			}
	}

	for(int i=0;i<=n;i++){checker[i]=temp[i];}

	//now if there is any change in distance and checker we can conclude that there is negative cycle
	for(int i=0;i<=n;i++){if(checker[i]!=distance[i]){
		cout<<"NEGATIVE CYCLE DETECTED"<<endl;
		return 0;
	}}


//**************************************************************************

    

	int ans;

	if(distance[des]==INT_MAX){
		ans= pow(10 , 9);
	}
	else { ans=distance[des]; }

	delete[] distance;delete[] temp;delete[] checker;

	return ans;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , e;
		cin>>n>>e;

		edgenode * edges=new edgenode[e]();

		int src , des;
		cin>>src>>des;

		for(int i=0;i<e;i++){
			cin>>edges[i].start>>edges[i].end>>edges[i].weight;
		}

		int ans=bellman_ford(edges , n , e , src , des);

		cout<<ans<<endl;

		delete[] edges;

	}

	return 0;
}