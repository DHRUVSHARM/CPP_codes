/*
Code Breaker
Send Feedback
Jack Ryan is one of the world’s most famous cryptographers. He has been recently tasked with breaking a code with which our country’s enemies are communicating. He has thought of a possible break in the code, using a very complex system of strings, which thankfully, you have nothing to do with. You are tasked with a little problem. Jack will give you n strings, labelled S1, S2, …. Sn, along with q queries.
In each query, you have an integer X and a string CODE. You will take into consideration strings S1 to SX. Among these selected strings, consider all the strings such that their longest common prefix with CODE is the maximum possible. Now, from these strings, print the lexicographically smallest one. This would give Jack tremendous insight into further breaking the code. Can you help him?
Input Format:
The first line of the input contains a single integer N.
N lines follow. For each valid i, the i-th of these lines contains Chef's string Si.
The next line contains a single integer Q.
The following Q lines describe queries. Each of these lines contains an interger R, followed by a space and a string P
Constraints:
1 ≤ n ≤ 100,000 
1 ≤ |Si| ≤ 10 for each valid i
1 ≤ q ≤ 100,000
1 ≤ X ≤ n
1 ≤ |CODE| ≤ 10
Output Format:
For each query, print a single line containing the string that satisfies the required conditions — the answer to that query.
Sample Input 1:
4
abcd
abce
abcdex
abcde
3
3 abcy
3 abcde
4 abcde
Sample Output 1:
abcd
abcdex
abcde
*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class trienode{
	public:
		trienode ** children;
		int word_end; //0 represents the word end

		trienode(){
			children=new trienode*[26];
			for(int i=0;i<26;i++){
				children[i]=NULL;
			}
			word_end=0;
		}
};

void insert(trienode * head , string word){
	if(word.empty()){
		head->word_end=1;
		//represents that a valid word ends here
		return;
	}

	int index=word[0]-'a';

	if(!head->children[index]){
		head->children[index]=new trienode();
	}
	insert(head->children[index] , word.substr(1));
}

void cleantrie(trienode * head){
	for(int i=0;i<26;i++){
		if(head->children[i]){
			cleantrie(head->children[i]);
		}
	}
	delete head;
}

string helper(trienode * head , string ending){

	if(head->word_end==1){
		return ending;
	}

	for(int i=0;i<26;i++){
		if(head->children[i]!=NULL){
			char letter='a'+i;
			return helper(head->children[i] , ending + letter);
			
		}
	}
}

void query(trienode * head , string word , string& accumalator){
	//we have to find maximum common prefix  , then lexicographically
	//smallest word

	trienode * curr=head;

	for(int i=0;i<word.size();i++){
		int index=word[i]-'a';
		if(curr->children[index]!=NULL){
			curr=curr->children[index];
			char letter='a'+index;
			accumalator+=letter;
		}
		else{
			break;
		}
	}

	if(curr->word_end == 1){return;}

	string ending=helper(curr , "");

	accumalator+=ending;

	return;
}

int main(){

	int n;
	cin>>n;

	string s[n+1];

	for(int i=1;i<=n;i++){
		cin>>s[i];
	}

	vector<pair<string , int>> v[n+1];

	int q;
	cin>>q;

	for(int i=1;i<=q;i++){
		int r;string text;
		cin>>r>>text;
		//r is range

		v[r].push_back({text , i});
	}

	string answers[q+1];
	//this will store the final answers

	trienode * head=new trienode();

	for(int i=1;i<=n;i++){
		insert(head , s[i]);
		//now answer all queries with range 1..i
		for(int j=0;j<v[i].size();j++){
			string accumalator=""; //accumalate the answer
			query(head , v[i][j].first , accumalator);
			answers[v[i][j].second]=accumalator;
		}
	}

	for(int i=1;i<=q;i++){
		cout<<answers[i]<<'\n';
	}

	cleantrie(head);head=NULL;

	return 0;
}