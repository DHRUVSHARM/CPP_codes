//this is a reusable code for the disjoint set union (DSU) data structure 

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class DSnode{
	public:
		int data;
		int rank;
		DSnode * parent;
		DSnode(){
			this->data=0;this->rank=0;
			this->parent=NULL;
		}
};
//this describes a node in the dsu data set

class DisjointSet{
	private:
		//under the hood computation
		unordered_map<int , DSnode*> hash;
		//this will be used to convert user input to node type

		//recursive function for compression and getting parent node
		DSnode * helper(DSnode * node){
			if(node->parent == node){
				//cout<<"at top"<<node->data<<endl;
				return node;
				
			}
			//cout<<node->parent->data<<endl;
			DSnode * ans=helper(node->parent);
			node->parent=ans;
			return ans;
		}

	public:
		//can be accesed and is available to be called from objects created

		//initialize
		void initializeSet(int data){
			DSnode * node=new DSnode();
			node->data=data;
			node->rank=0;
			node->parent=node;
			hash[data]=node;
		}
		//this will return the topmost parent of the vertex passed and will do path compression in the process
		int search(int data){
			return helper(hash[data])->data;
		}
		//this will make union of two components
		void Union(int data1 , int data2){
			DSnode * parent1=helper(hash[data1]);
			DSnode * parent2=helper(hash[data2]);
			//returns the topmost parent node of both vertices
			if(parent1->data == parent2->data){
				//same parent thus, cycle
				return;
			}

			if(parent1->rank >= parent2->rank){
				if(parent1->rank == parent2->rank){
					parent1->rank = parent1->rank + 1;
					
				}
					parent2->parent=parent1;

			}

			else{
				parent1->parent=parent2;
			}
		}
};



int main(){
	//take an example with (0...6);
	DisjointSet ds;

	for(int i=0;i<=6;i++){
		ds.initializeSet(i);
	}

	ds.Union(0 , 1);
	ds.Union(1 , 2);
	ds.Union(3 , 4);
	ds.Union(2 , 4);
	ds.Union(5 , 6);
	ds.Union(4 , 6);

	for(int i=0;i<=6;i++){
		int ans=ds.search(i);
		cout<<endl<<"topmost parent"<<"\t"<<ans<<endl;
		//cout<<"********************************"<<endl;
	}

	


	return 0;
}