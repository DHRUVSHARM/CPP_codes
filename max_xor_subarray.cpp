/*
Maximum XOR Subarray
Send Feedback
Given an array of N integers, find the subarray whose XOR is maximum.
Input Format:
First line of input contains an integer N, representing number of elements in array.
Next line contains N space-separated integers.
Constraints:
1 <= N <= 10^6
1 <= A[i] <=10^5 
Output Format:
Print XOR of the subarray whose XOR of all elements in subarray is maximum over all subarrays.
Sample Input 1:
4
1 2 3 4
Sample Output 1:
7

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class trienode{
public:
	trienode * left;
	trienode * right;
	trienode(){

		this->left=NULL;
		this->right=NULL;
	}
};

void insert(trienode * head , int value){

	trienode * curr=head;
	for(int i=31;i>=0;i--){
		int b=(value>>i)&1;

		if(b==1){
			//to right
			if(!curr->right){
				curr->right=new trienode();
			}
			curr=curr->right;
		}
		else{
			//to left
			if(!curr->left){
				curr->left=new trienode();
			}
			curr=curr->left;
		}
	}
}

int query(trienode * head , int value){

	trienode * curr=head;
	int ans=0;
	for(int i=31;i>=0;i--){
		int b=(value>>i)&1;
		if(b==1){
			//try left
			if(curr->left){
				curr=curr->left;
				ans+=pow(2 , i);
			}
			else{
				curr=curr->right;
			}
		}
		else{
			//try right
			if(curr->right){
				curr=curr->right;
				ans+=pow(2 , i);
			}
			else{
				curr=curr->left;
			}
		}
	}

	return ans;
}

void cleantrie(trienode * head){
	if(head->right){cleantrie(head->right);}
	if(head->left){cleantrie(head->left);}
	delete head;
}

int main(){

	int n;
	cin>>n;

	int * arr=new int[n]();

	for(int i=0;i<n;i++){cin>>arr[i];}

	trienode * head=new trienode();

	int max_ans=0;
	int xor_cum=0;
	insert(head , xor_cum);

	for(int i=0;i<n;i++){

		xor_cum^=arr[i];
		int curr_ans=query(head , xor_cum);
		max_ans=max(max_ans , curr_ans);
		insert(head , xor_cum);
	}

	cout<<max_ans<<'\n';


	delete[] arr;
	cleantrie(head);
	head=NULL;
	return 0;
}