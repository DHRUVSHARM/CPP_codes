/*
Search Engine
Send Feedback
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
Note: All the strings in database will be unique.
Input Format:
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. 
Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.
Next q lines follow, each line having a string t, which needs to be completed.
Constraints:
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
Total length of all strings in database entries ≤ 10^6
Total length of all query strings ≤ 10^6
Output Format:
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
Sample Input 1:
2 1
potential 10
potent 8
pot
Sample Output 1:
10
*/
//function implementation based question
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>

using namespace std;



class trienode{
public:
	trienode ** children;
	int weight;
	trienode(){
		children=new trienode*[26]();
		for(int i=0;i<26;i++){children[i]=NULL;}
		weight=0;
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

void insert(trienode * head , string s , int priority){
	if(s.empty()){return;}

	int index=s[0]-'a';
	if(head->children[index]){
		//exists
		head->children[index]->weight=max(head->children[index]->weight , priority);
	}	
	else{
		//does not exist
		head->children[index]=new trienode();
		head->children[index]->weight=priority;
	}
	insert(head->children[index] , s.substr(1) , priority);
}

int query(trienode * head , string text){
	int ans=-1;
	trienode * curr=head;
	for(int i=0;i<text.size();i++){
		int index=text[i]-'a';
		if(!curr->children[index]){
			//cannot find full text 
			return -1;
		}
		ans=curr->children[index]->weight;
		curr=curr->children[index];
	}
	return ans;
}

vector<int> searchEngine(vector<pair<string, int> > database, vector<string> text)
{
    // Write your code here
    trienode * head=new trienode();

    //insert
    for(int i=0;i<database.size();i++){
    	insert(head , database[i].first , database[i].second);
    }

    vector<int> answer;
    for(int i=0;i<text.size();i++){
    	int ans=query(head , text[i]);
    	answer.push_back(ans);
    }

    cleantrie(head);head=NULL;
    return answer;
}

/******************************/



//#include "solution.h"
class Runner
{
    int t;

    vector<vector<int>> s;
    vector<pair<string, int> > database;
    vector<string> text;

public:
    void takeInput()
    {

        // cin >> t;
        t = 1;
        // s.resize(t);
        int n, x,q;
        

        for (int tc = 0; tc < t; tc++)
        {
            // int q;
            cin >> n >> q;

            for (int i = 0; i < n; ++i)
            {
                string xx;
                int yy;
                cin >> xx>>yy;
                database.push_back({xx,yy});
            }
            for (int i = 0; i < q; ++i)
            {
                string xx;
                cin>>xx;
                text.push_back(xx);
            }
        }
        
    }
    /*
    vector<vector<int>> getCopy()
    {
        vector<vector<int>> arrCopy = arr;


        return arrCopy;
    }

    */
    void execute()
    {
        vector<pair<string, int> > databases = database;
        vector<string> texts = text;

        for (int i = 0; i < t; i++)
        {
            vector<int> ans = searchEngine(databases, texts);

        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> ans = searchEngine(database, text);
            for(auto& j : ans) cout<<j<<'\n';
        }
    }
};


int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}