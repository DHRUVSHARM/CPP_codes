#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class vertex{
public:
	int v;
	int weight;
};

bool operator<(vertex first , vertex second){
	return first.weight>second.weight;
}

int main(){

	int n;cin>>n;
	vertex * arr=new vertex[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].v>>arr[i].weight;
	}

	priority_queue<vertex> pq;
	//min priority queue of objects

	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}

	while(!pq.empty()){
		vertex x=pq.top();
		cout<<x.v<<"\t"<<x.weight<<endl;
		pq.pop();
	}

	return 0;
}