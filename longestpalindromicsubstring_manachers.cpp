/*
Longest Palindromic Substring
Send Feedback
You are given a string S .You have to find the length of the longest palindromic substring of S.
Input Format:
First line of input contains the string S.
Constraints:
1 <= |S| <= 4*10^6
Output Format:
You have to print the length of longest palindromic substring
Sample Input 1:
zkpbhxkmauuamkxsyi
Sample Output 1:
10
Explanation:
In the given sample test case, the longest palindromic substring is: xkmauuamkx.

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int manacher(string s){

	int center=0;
	int range=0;

	int * lps=new int[s.size()]();

	//cout<<endl<<s<<endl;

	for(int i=1;i<s.size()-1;i++){

		if(i < range){
			//we have some part of the answer or all of it
			int k=center-(i-center);

			if(lps[k] + i < range){
				//we have the complete answer
				lps[i]=lps[k];
			}
			else{
				//we have partial answer
				lps[i]=lps[k];
				while(s[i+lps[i]+1] == s[i-lps[i]-1]){lps[i]++;}

				if(i + lps[i] > range){
					center=i;
					range=i+lps[i];
				}
			}
		}
		else{
			//we don't have enough information 
			while(s[i+lps[i]+1] == s[i-lps[i]-1]){
				lps[i]++;
			}
			if(i+lps[i] > range){
				center=i;range=i+lps[i];
			}
		}

	//	cout<<"lps"<<" "<<i<<" "<<lps[i]<<endl;
	}



	int ans=0;int max_index=-1;
	for(int i=1;i<(s.size()-1);i++){
		if(lps[i] > ans){
			ans=lps[i];
			max_index=i;
		}
	}

	int start=max_index-lps[max_index];int end=max_index+lps[max_index];
	string longest="";
	while(start<=end){
		if(s[start]!='#'){
			longest=longest+s[start];
		}
		start++;
	}

	cout<<"longest palindrome:"<<" "<<longest<<endl;

	delete[] lps;

	return ans;
}



int main(){

	string s;
	cin>>s;

	string input="";

	for(int i=0;i<s.size();i++){
		input=input+s[i]+"#";
	}
	input="@#" + input + "&";

	//cout<<input;

	int ans=manacher(input);

	//cout<<"here"<<endl;
	cout<<ans<<endl;

	return 0;
}