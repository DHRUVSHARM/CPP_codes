/*String Search
Send Feedback
You are given an string S and a test string T. You have to find whether string S is a substring of the string T.
Input Format:
First line of input will contain an integer T, representing the number of test cases
Each test case is as follows:
Line 1: contains the string S.
Line 2: contains the string T.
Constraints:
1 <= T <= 100
1 <= |S|, |T| <= 10^5
Output Format:
For each test case print "Yes" if S is present in T or "No" otherwise.
Sample Input 1:
2
ye
wnpnzijdi
ao
jaoalc
Sample Output 1:
No
Yes
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void getlps(int * lps , string pattern){
	lps[0]=0;
	if(pattern.size()==1){return;}

	int i=1;int j=0;

	while(i<pattern.size()){
		if(pattern[i]==pattern[j]){
			lps[i]=j+1;
			i++;j++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				lps[i]=0;i++;
			}
		}
	}

	return;
}

bool kmp(string text , string pattern , int * lps){
	int i=0;int j=0;

	while(i<text.size() && j<pattern.size()){
		if(text[i]==pattern[j]){
			i++;j++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
			 i++;
			}
		}
	}

	if(j==pattern.size()){return true;}
	else{return false;}
}

int main(){

	int t;
	cin>>t;

	while(t--){

		string pattern;
		cin>>pattern;

		string text;
		cin>>text;

		int * lps=new int[pattern.size()]();

		getlps(lps , pattern);

		bool ans=kmp(text , pattern , lps);

		if(ans){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

		delete[] lps;
	}

	return 0;
}