/*
Palindromic Substrings
Send Feedback
Given a string S, count and return the number of substrings of S that are a palindrome.
Single length substrings are also palindromes. You just need to print the count of palindromic substrings, not the actual substrings.
Input Format:
First line of input contains an integer T, representing the number of test cases.
Next T lines contain the string S
Constraints :
1 <= Length of S <= 2000
Output Format :
For each test case, print the count of palindrome substrings in a new line.
Sample Input 1:
1
aba
Sample Output 1:
4
Explanation:
The 4 palindrome substrings are "a", "b", "a" and "aba".
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int palindromes(string s , int n){

	int palindrome_count=0;

	

	for(int i=0;i<n;i++){

		int l , r;

		//odd
		l=i;r=i;
		while(l>=0 && r<n && s[l]==s[r]){
			//palindrome found for each iteration in this loop
			palindrome_count++;
			l--;r++;
		}

		//even
		l=i;r=i+1;
		while(l>=0 && r<n && s[l]==s[r]){
			palindrome_count++;
			l--;r++;
		}
	}

	return palindrome_count;	
}

int main(){

	int t;
	cin>>t;

	while(t--){

		string s;
		cin>>s;

		int ans=palindromes(s , s.size());

		cout<<ans<<endl;

	}

	return 0;
}