/*
Sub - XOR
Send Feedback
Given an array of positive integers, you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai + 1, ..., Aj. XOR of a subarray is defined as Ai ^ Ai + 1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format:
First line of input contains N and K, space separated.
Second line of input contains N space separated.integers.
Constraints:
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Output Format:
For each test case, print the required answer.
Sample Input 1:
5 2
4 1 3 2 7   
Sample Output 1:
3
Explanation to Sample Input 1
Only subarrays satisfying the conditions are [1],[1,3,2] and [3,2].

*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class trienode{
public:
	trienode * left;
	trienode * right;
	int child_count;
	trienode(){
		this->left=NULL;
		this->right=NULL;
		this->child_count=0;
	}
};

void insert(trienode * head , int value){
	trienode * curr=head;
	for(int i=31;i>=0;i--){
		int b=(value>>i)&1;
		if(b==1){
			if(!curr->right){
				curr->right=new trienode();
				curr->right->child_count=1;
			}
			else{
				curr->right->child_count++;
			}
			curr=curr->right;
		}
		else{
			if(!curr->left){
				curr->left=new trienode();
				curr->left->child_count=1;
			}
			else{
				curr->left->child_count++;
			}
			curr=curr->left;
		}
	}

	return;
}

void cleantrie(trienode * head){
	if(head->left){cleantrie(head->left);}
	if(head->right){cleantrie(head->right);}
	delete head;
}

long long int query(trienode * head , int value , int k){
	//if(value==6){cout<<"hiii"<<endl;}
	trienode * curr=head;
	long long int ans=0;
	for(int i=31;i>=0;i--){
		//if(value==6){cout<<" i bit"<<" "<<i<<endl;}
		int p=(k>>i)&1;
		int b=(value>>i)&1;
		//if(value==6){cout<<"p"<<" "<<p<<" "<<"b"<<" "<<b<<endl;}

		if(p==1){
			if(b==1){
				//b is 1
				if(curr->right){ans+=curr->right->child_count;}
				curr=curr->left;
				//cout<<ans<<endl;

			}
			else{
				//b is 0
				if(curr->left){ans+=curr->left->child_count;}
				curr=curr->right;
				//cout<<ans<<endl;
			}
		}
		else{
			//can go only in one direction
			if(b==1){curr=curr->right;}
			else{curr=curr->left;}
		}

		if(curr==NULL){
			//cout<<"here"<<endl;
			break;
		}
	}

	return ans;
}

int main(){

	int n , k;
	cin>>n>>k;

	int * arr=new int[n]();
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	long long int ans=0;int mxor=0;

	trienode * head=new trienode();

	insert(head , mxor);

	for(int i=0;i<n;i++){
		mxor^=arr[i];
	//	cout<<"mxor"<<" "<<mxor<<endl;
		ans+=query(head , mxor , k);
	//	cout<<"ans"<<" "<<ans<<endl;
		insert(head , mxor);
		//cout<<"done"<<endl;
	}

	cout<<ans<<'\n';
	delete[] arr;
	cleantrie(head);
	head=NULL;

	return 0;
}