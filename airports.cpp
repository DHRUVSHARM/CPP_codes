/*
AIRPORTS
Send Feedback
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, and with minimum cost.
Input Format:
The first line of input contains the integer T (the number of test cases), each test case follow as.
Line1: Three space-separated integers N, M and cost number of locations, number of possible roads and cost of airport respectively
The following M lines each contain three integers X, Y and C, separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output Format:
For each test case print the cost in a newline.
Constraints:
1 <= T <= 20
1 <= N, M <= 10^5
1 <= cost <= 10^9
1 <= weight(of each road) <= 10^9
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
145
2090
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;

class edgenode{
public:
	int start;
	int end;
	int weight;
};

bool compare(edgenode e1  , edgenode e2){
	return e1.weight<e2.weight;
}

int find_parent(int * parent , int index){
	if(parent[index]==index){return index;}
	return find_parent(parent , parent[index]);
}

ll airport(vector<edgenode>& edges , int n , int cost){

	int * parent=new int[n]();
	for(int i=0;i<n;i++){
		parent[i]=i;
	}

	ll road_cost=0;ll final_cost=0;

	for(int i=0;i<edges.size();i++){

		if(edges[i].weight < cost){
			//should build road
			//we will do union 
			int x=edges[i].start;int y=edges[i].end;
			int parentx=find_parent(parent , x);
			int parenty=find_parent(parent , y);

			if(parentx!=parenty){
				//no cycle made by adding
				road_cost+=edges[i].weight;
				parent[parenty]=parentx;
			}
		}
	}

	final_cost+=road_cost;

	for(int i=0;i<n;i++){
		if(parent[i]==i){
			final_cost+=cost;
		}
	}

	return final_cost;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n , m , cost;
		cin>>n>>m>>cost;

		map<pair<int , int> , int> checkedge;
		vector<edgenode> edges;

		for(int i=0;i<m;i++){
			int x , y , c;
			cin>>x>>y>>c;

			x--;y--;

			if( checkedge.find( { min(x , y) , max(x , y) }) != checkedge.end() ){
				//edge already exist
				if( c < checkedge[{min(x , y) , max(x , y)}] ){
					checkedge[{min(x , y) , max(x , y)}]=c;
				}
			}
			else{
				//not exist
				checkedge.insert( {{ min(x,y) , max(x,y) } , c });
			}
		}

	/*	cout<<endl;
		map<pair<int,int>,int>::iterator it;
		for(it=checkedge.begin();it!=checkedge.end();it++){
			cout<<(it->first).first+1<<"\t"<<(it->first).second+1<<"\t"<<it->second<<endl;
		}
	*/
		//now we have to add all the unique weighted edges to our list

		map<pair<int,int>,int> :: iterator it;
		for(it=checkedge.begin();it!=checkedge.end();it++){
			edgenode edge;
			edge.start=(it->first).first;
			edge.end=(it->first).second;
			edge.weight=it->second;
			edges.push_back(edge);
		}

		sort(edges.begin() , edges.end() , compare);

		/*cout<<"edge list is:"<<endl;
		for(int i=0;i<edges.size();i++){
			cout<<edges[i].start+1<<" "<<edges[i].end+1<<" "<<edges[i].weight<<endl;
		}*/

		ll mincost=airport(edges , n , cost);
		cout<<mincost<<endl;

	}

	return 0;


}