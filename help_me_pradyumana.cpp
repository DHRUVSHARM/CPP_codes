/*
Help Me Pradyumana!
Send Feedback
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
Input Format:
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
Constraints:
1 ≤ N ≤ 30000
sum(len(string[i])) ≤ 2∗10^5
1 ≤ Q ≤ 10^3
Output Format:
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes
Sample Input 1:
3
fact
factorial
factory
2
fact
pradyumn
Sample Output 1:
fact
factorial
factory
No suggestions
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class trienode{
public:
	trienode ** children;
	int word_end;
	trienode(){
		children=new trienode*[26]();
		for(int i=0;i<26;i++){
			children[i]=NULL;
		}
		word_end=0;//indicates the end of word
	}
};

void cleantrie(trienode * head){
	for(int i=0;i<26;i++){
		if(head->children[i]){
			cleantrie(head->children[i]);
		}
	}
	delete head;
}

void insert(trienode * head , string s){
	if(s.empty()){
		head->word_end=1;
		return;}
	int index=s[0]-'a';
	if(!head->children[index]){
		head->children[index]=new trienode();
	}
	insert(head->children[index] , s.substr(1));
}

void dfs(trienode * root , string acc){
	//int count=0;

	if(root->word_end==1){cout<<acc<<'\n';}
	
	for(int i=0;i<26;i++){
		if(root->children[i]){
			char add='a' + i;
			dfs(root->children[i] , acc+add);
		}
	}
	
	//if(count==26){cout<<acc<<'\n';}
}

void query(trienode * head , string text){
	//first we need to find text
	bool found=true;
	trienode * curr=head;
	for(int i=0;i<text.size();i++){
		int index=text[i]-'a';
		if(!curr->children[index]){
			//null
			found=false;
			break;
		}
		curr=curr->children[index];
	}

	if(!found){
		//insert text and print no suggestions
		insert(head , text);
		cout<<"No suggestions"<<'\n';
		return;
	}

	//we have found the text now to print all the inserted strings starting from this

	//first print the text itself
	//cout<<text<<'\n';

	dfs(curr  , text);
}

int main(){

	int n;
	cin>>n;

	trienode * head=new trienode();

	while(n--){
		string s;
		cin>>s;

		insert(head , s);
	}

	int q;
	cin>>q;

	while(q--){
		string text;
		cin>>text;
		query(head , text);
	}

	cleantrie(head);
	head=NULL;

	return 0;
}